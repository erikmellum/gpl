#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "game_object.h"
#include <string>

class Triangle : public Game_object
{
  public:
      Triangle();

  private:
    int m_size;
    double m_rotation;
    double m_skew;

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Triangle(const Triangle &);
    const Triangle &operator=(const Triangle &);

    virtual void updated(std::string name);
    virtual void build_display_list();

};

#endif // #ifndef TRIANGLE_H
