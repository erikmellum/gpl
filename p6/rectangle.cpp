#include "rectangle.h"
#include "gpl_assert.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

Rectangle::Rectangle() : Game_object(/* red = */ 1.0,
                                     /* green = */ 0.0,
                                     /* blue = */ 0.0
                                    )
{
  m_rotation = 0;
  register_member_variable("rotation", &m_rotation);
  m_object_type_name = "Rectangle";
}

/* virtual */ void Rectangle::build_display_list()
{
  assert(m_display_list);

  glNewList(m_display_list, GL_COMPILE);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  if (m_rotation != 0)
  {
    double center_x = m_x + m_w/2.0;
    double center_y = m_y + m_h/2.0;
    glTranslated(center_x, center_y, 0);
    glRotated(m_rotation, 0, 0, 1);
    glTranslated(-center_x, -center_y, 0);
  }

  glColor3f(m_red, m_green, m_blue);
  glBegin(GL_QUADS);
    glVertex2i(m_x, m_y);
    glVertex2i(m_x + m_w, m_y);
    glVertex2i(m_x + m_w, m_y + m_h);
    glVertex2i(m_x, m_y + m_h);
  glEnd();
  glPopMatrix();
  glEndList();
}
