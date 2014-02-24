#ifndef OSX
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif

#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

const int window_width = 200;
const int window_height = 200;

int x = 10;
int y = 10;
int w = 10;
int h = 10;

void draw_callback()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(0.0, 0.0, 1.0);

  glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + h);
    glVertex2i(x, y + h);
  glEnd();

  glutSwapBuffers();
}


// Called by GLUT every time the user presses a key
void special_callback(int key, int x_loc, int y_loc)
{
  switch (key)
  {
	  case GLUT_KEY_UP: 
		  if (y <= window_height - 14)
		    y += 5;
		  break;
	  case GLUT_KEY_DOWN:
		  if (y >= 5)
		    y -= 5;
		  break;
	  case GLUT_KEY_LEFT:
		  if (x >= 5)
		    x -= 5;
		  break;
	  case GLUT_KEY_RIGHT:
		  if (x <= window_width - 14)
		    x += 5;
		  break;
	  case GLUT_KEY_F1:
		  exit(0);
  }
  draw_callback();
}


int main(int argc, char **argv)
{

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(window_width, window_height);
  glutInitWindowPosition(50,50);
  glutCreateWindow("simple glut demonstration");

  glutDisplayFunc(draw_callback);
  glutSpecialFunc(special_callback);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, window_width, 0, window_height);
  glClearColor (1.0, 1.0, 1.0, 0.0);

  cout << "select graphics window:" << endl;
  cout << "  use arrows to move rectangle around window" << endl;
  cout << "  press F1 to exit" << endl;

  glutMainLoop ();
}
