#ifndef CIRCLE_H
#define CIRCLE_H

#include "game_object.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

class Circle : public Game_object
{
  public:
    Circle();

  private:
    virtual void updated(std::string name);
    virtual void build_display_list();

    int m_radius;
    GLUquadricObj *m_quadric;

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Circle(const Circle &);
    const Circle &operator=(const Circle &);
};

#endif // #ifndef CIRCLE_H
