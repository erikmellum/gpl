/*
  Pixmap provide an encapsulation for bitmaps.
  To create a pixmap, pass a filename to the constructor.
  The file will be read and the data stored in the Pixmap object.

  In order to provide simple bitmap animation, the file associated with a
  pixmap can be change.  Consider an animation of a stick figure walking.
  The animation can be achieved by having four different pixmaps and cycling
  through them.  Class Pixmap implements this with using the gpl
  attribute mechanism:  my_pixmap.filename = "person_2.bmp"

  The next time my_pixmap is drawn, the new bitmap will be used.

  In order to reduce run-time, a cache of all pixmaps used since program
  start up is kept.

  LIMITATIONS:
    Only works for pixmaps with 1 plane and 24 bits per plane
*/

#ifndef PIXMAP_H
#define PIXMAP_H

#include "game_object.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#endif

#include <string>
#include <map>


class Pixmap : public Game_object
{
  public:
    Pixmap();
    void draw();
  private:
    class Pixmap_data
    {
      public:
        unsigned long m_width;
        unsigned long m_height;
        unsigned char *m_data;
        Pixmap_data(unsigned long width,
              unsigned long height,
              unsigned char *data)
        {
          m_width = width;
          m_height = height;
          m_data = data;
        }
    };
    static Pixmap_data *default_pixmap_data;
    static std::map<std::string, Pixmap_data*> m_pixmap_cache;

    Pixmap_data *m_pixmap_data;
    std::string m_filename;

    bool m_tried_to_read_current_file;

    void read_file();
    void build_display_list();
    void updated(std::string name);
  
    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Pixmap(const Pixmap &);
    const Pixmap &operator=(const Pixmap &);

};

#endif
