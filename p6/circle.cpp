#include "circle.h"
#include "gpl_assert.h"
using namespace std;

Circle::Circle() :  Game_object(/* red = */ 0.0,
                                /* green = */ 0.0,
                                /* blue = */ 1.0
                               )
{
    m_radius = 10;
    register_member_variable("radius", &m_radius);
    m_object_type_name = "Circle";

    // the width and height are derived from the radius
    m_w = 2*m_radius;
    m_h = 2*m_radius;

    // width and height are derived --> user cannot change them
    Status status;
    status = mark_member_variable_as_derived("w");
    assert(status == OK);
    status = mark_member_variable_as_derived("h");
    assert(status == OK);

    m_quadric = 0;
}

void Circle::updated(string name)
{
  if (name == "radius")
  {
    m_w = 2*m_radius;
    m_h = 2*m_radius;
  }
  m_display_list_dirty = true;
}

void Circle::build_display_list()
{
  assert(m_display_list);
  if (m_quadric == 0)
  {
    m_quadric = gluNewQuadric();
    gluQuadricDrawStyle(m_quadric, GLU_FILL);
  }
  glNewList(m_display_list, GL_COMPILE);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glTranslated(m_x + m_radius, m_y + m_radius, 0);
  glColor3f(m_red, m_green, m_blue);
  gluDisk(m_quadric,
          /* innerRadius = */ 0,    // creates a hole in center
          /* outerRadius = */ m_radius,
          /* slices = */ 200, // use to be 20
          /* rings = */ 1
         );
  glPopMatrix();
  glEndList();

  // width and height are derived from the radius
  m_w = 2*m_radius;
  m_h = 2*m_radius;
}
