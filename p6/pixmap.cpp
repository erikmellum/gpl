#include "pixmap.h"
#include "gpl_assert.h"

#include <stdio.h>      /* Header file for standard file i/o. */
#include <stdlib.h>     /* Header file for malloc/free. */
#include <iostream>
using namespace std;

#include "default_pixmap.h"
/* static */ Pixmap::Pixmap_data *Pixmap::default_pixmap_data = 0;
/* static */ map<string, Pixmap::Pixmap_data*> Pixmap::m_pixmap_cache;

Pixmap::Pixmap()
{
  // if the default pixmap has yet to be created, create it
  if (!default_pixmap_data)
  {
    default_pixmap_data = new Pixmap_data(default_width,
                                          default_height,
                                          default_data
                                         );
  }
  m_pixmap_data = 0;

  m_filename = "";
  register_member_variable("filename", &m_filename);

  m_object_type_name = "Pixmap";
  // width and height of a pixmap are derived --> user cannot change them
  Status status;
  status = mark_member_variable_as_derived("w");
  assert(status == OK);
  status = mark_member_variable_as_derived("h");
  assert(status == OK);

  m_tried_to_read_current_file = false;

  // the filename is not specified yet, so don't try to read file yet
}

void Pixmap::updated(string name)
{
  // called with x,y or filename changes

  // if the filename changes, set flag that it hasn't been read yet
  if (name == "filename")
    m_tried_to_read_current_file = false;

  // this will cause a new display list to be created that will use new (x,y)
  m_display_list_dirty = true;
}

void Pixmap::build_display_list()
{
  // if there is a pending file read, attempt to read file
  if (!m_tried_to_read_current_file)
    read_file();

  // if the pixmap_data is not defined, file read must have failed
  // use the default
  if (!m_pixmap_data)
  {
    m_pixmap_data = default_pixmap_data;
    m_w = m_pixmap_data->m_width;
    m_h = m_pixmap_data->m_height;
  }

  // build the display list
  assert(m_display_list);
  assert(m_pixmap_data);
  glNewList(m_display_list, GL_COMPILE);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glRasterPos2i(m_x, m_y);

  // the .bmp format packs pixels into rows that are a
  // multiple of 4 bytes (adds padding if neccessary).  
  // Tell openGL to expect the padding @ 4byte level
  glPixelStorei(GL_UNPACK_ALIGNMENT, (GLint) 4);

  // LIMITATION: it would be nice if I could draw pixmaps with
  // stencils
  //   solution:  
  //     include a second filename that specifies a stencil file
  //     read the stencil in and keep it with the bitmap_data
  //     before calling glDrawPixels()...
  //     The following isn't correct, but it might be partially correct
  //       glEnable(GL_STENCIL_TEST)
  //       glDrawPixels(..., stencil,  using the stencil argument)
  //       glDrawPixels(as before)
  //       glDisable(GL_STENCIL_TEST)

  glDrawPixels(m_pixmap_data->m_width,
               m_pixmap_data->m_height,
               GL_BGR, GL_UNSIGNED_BYTE,
               m_pixmap_data->m_data
              );
  glPopMatrix();
  glEndList();
}

void Pixmap::read_file()
{
  // special case that no filename has been specified yet
  if (m_filename == "")
    return;

  // flag that we have tried to read the file so that we don't attempt
  // to read bad files over and over
  m_tried_to_read_current_file = true;

  // If the pixmap in m_filename has already been read
  // get it out of the cache
  map<string, Pixmap_data *>::const_iterator iter;
  iter = m_pixmap_cache.find(m_filename);
  if (iter != m_pixmap_cache.end())
  {
    m_pixmap_data = (*iter).second;
    m_w = m_pixmap_data->m_width;
    m_h = m_pixmap_data->m_height;
    return;
  }


  // set to NULL in case read fails
  m_pixmap_data = 0;

  FILE *file;
  unsigned long width=0;           // width of image
  unsigned long height=0;          // height of image
  unsigned long i;                 // standard counter
  unsigned short int planes;       // number of planes in image (must be 1)
  unsigned short int bpp;          // number of bits per pixel (must be 24)

  // make sure the file is there
  if ((file = fopen(m_filename.c_str(), "rb"))==NULL)
  {
    cerr << "Texture filename <" << m_filename << "> not found." << endl;
    return;
  }

  unsigned long data_offset = 0;
  fseek(file, 10, SEEK_SET);
  if ((i = fread(&data_offset, 4, 1, file)) != 1)
  {
    cerr << "Error reading data_offset size from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  unsigned long header_size = 0;
  // read the size of header
  if ((i = fread(&header_size, 4, 1, file)) != 1)
  {
    cerr << "Error reading header size from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  // read bitmap width
  if ((i = fread(&width, 4, 1, file)) != 1)
  {
    cerr << "Error reading width from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  // read bitmap height
  if ((i = fread(&height, 4, 1, file)) != 1)
  {
    cerr << "Error reading height from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  // read the planes
  if ((fread(&planes, 2, 1, file)) != 1)
  {
    cerr << "Error reading planes from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  // LIMITATION: some day it would be nice to handle any number of planes
  // this code only works for bitmaps with 1 plane
  if (planes != 1)
  {
    cerr << "Error reading texture filename <" << m_filename
         << "> it has more than 1 plane" << endl;
    return;
  }

  // read the bits-per-pixel
  if ((i = fread(&bpp, 2, 1, file)) != 1)
  {
    cerr << "Error reading bits per pixel from texture filename <" << m_filename << endl;
    return;
  }
  
  // LIMITATION: some day it would be nice to handle any bit/pixel
  // this code only works for bitmaps with 24 bits per pixel
  if (bpp != 24)
  {
    cerr << "Error reading texture filename <" << m_filename
         << " bits per pixel != 24 (can only handle 1 plane w/24 bits per pixel" << endl;
    return;
  }

  unsigned long compression = 0;
  if ((i = fread(&compression, 4, 1, file)) != 1)
  {
    cerr << "Error reading compression from texture filename <"
         << m_filename << ">" << endl;
    return;
  }

  if (compression)
  {
    cerr << "Error reading texture filename <" << m_filename
         << "> the bitmap is compressed, gpl can't handle compressed"
         << " bitmaps"
         << endl;
    return;
  }

  unsigned long bitmap_data_size = 0;
  if ((i = fread(&bitmap_data_size, 4, 1, file)) != 1)
  {
    cerr << "Error reading bitmap_data_size from texture filename <"
         << m_filename << ">" << endl;
    return;
  }
  // buffer used hold the pixel array (passed to Pixmap_data: DO NOT DELETE)
  unsigned char *bitmap_data = (unsigned char *) malloc(bitmap_data_size);

  // seek to the start of the pixel array
  fseek(file, data_offset, SEEK_SET);

  // read the padded bitmap_data
  if ((i = fread(bitmap_data, bitmap_data_size, 1, file)) != 1)
  {
    cerr << "Error reading image from texture filename <"
         << m_filename << ">" << endl;
    return;
  }
  // done reading .bmp file
  fclose(file);

  m_pixmap_data = new Pixmap_data(width, height, bitmap_data);
  m_w = m_pixmap_data->m_width;
  m_h = m_pixmap_data->m_height;

  // insert new pixmap into the pixmap cache
  m_pixmap_cache[m_filename] = m_pixmap_data;

  /****
  // DO NOT DELETE, keep it around in case we want a new default
  // this code was used to create default_pixmap.h
  //
  // to change default_pixmap.h to hold a new image
  // (1) uncomment this code
  // (2) create a gpl program with single pixmap
  //      pixmap p(file = "newdefault.bmp")
  // (3) run gpl save stdout to file
  // (4) update default_pixmap.h with the output
  cout << "dumping bitmap ******************" << endl;
  cout << "width = " << m_width << endl;
  cout << "height= " << m_height<< endl;
  cout << "size = " << size << endl;
  cout << "data = " << endl;
  int in_row = 0;
  for (int i = 0; i < size; i++)
  {
    if (++in_row > 10)
    {
      cout << endl;
      in_row = 0;
    }
    cout << (unsigned short) m_data[i] << ",";
  }
  ****/
}
