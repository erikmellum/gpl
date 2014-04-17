#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

/****

Introduction:

  class Game_object is a pure virtual base class for all gpl objects such as:

    class Circle : public Game_object
    class Triangle : public Game_object
    class Rectangle : public Game_object

  It provides support for two main parts of a gpl object
    
    1) member variables (named variables of type int, double, string)
    2) graphics (animation, drawing, calculations (e.g. touches))

  Users of Game_object (and the classes that inherit it) should focus
  on its public member functions.  In other words, you can use Game_object
  without fully understanding how it works.


Member variables
 Motivation:

    Need to be able to set/get member variables knowing only the
    variable's textual name

    This arises from the fact that in a gpl script we have the textual
    names of variables but since gpl is not C++ code, we can't simply
    use "obj.x"

    Need a mechanism that is extensible.  Specifically, when a new
    class is created, need to be able to set/get its member variables
    knowing only the variable's textual name

 Solution:

    Keep a registry of variables that can be set/get from gpl.

    Implement this registry in class Game_object.

    Require all objects w/variables that need to be set/get from gpl
    to inherit Game_object.

  Registry
    
    Need to map the name of the variable to its memory location
    Also keep an enumerated label of the type so we can do type checking

    The class Typed_void_ptr will store the memory location (as void *)
    and an enumerated variable (of type Gpl_type) to store the real type.

    A map will implement the registry:
        std::map<string, Typed_void_ptr *> m_variable_registry;

    Each object that inherits from Game_object will have to put
    all variables it wants accessible from gpl into the registry by
    calling
    
        void register_member_variable(string name, int *value)
        void register_member_variable(string name, double *value)
        void register_member_variable(string name, string *value)
        ...

    Each of these will set the enum flag to the correct value
  
  Access:

      The gpl code can now set/get member variables by using the member
    functions:

        Status set_member_variable(string name, int value);
        Status set_member_variable(string name, double value);
        Status set_member_variable(string name, string *value);
        ...

    The get functions return a status:

        enum Status {OK,
              MEMBER_NOT_OF_GIVEN_TYPE,
              MEMBER_NOT_DECLARED
              };

        Status get_member_variable(string name, int &value);
        Status get_member_variable(string name, double &value);
        Status get_member_variable(string name, string &value);
        ...

 Comments:

    This has gotten a bit more complex than I thought it would.  I wonder
    if there is an easier way to do this.  However, I don't think there
    are lots of situations when one needs to access a member variable
    only having the textual names.  In C++, the textual names are usually
    long gone by run time.

Graphics

  All graphics are done using OpenGL display lists.

  In order to define the graphics for an object, it must override the
  pure virtual function:
  
      virtual void build_display_list() = 0;

  in this function the graphics should be drawn to the display list
  m_display_list.

  Updating display list
  
    When a member variable is changed, build_display_list() is called before
    the object is redrawn.

    A class can redefine this behavior by providing the following function:

      virtual void updated(string name) {m_display_list_dirty = true;}

    If a member variable is not linked to the graphics, then don't
    mark the display list as dirty when that variable changes

  Drawing order

    An integer is associated with each Game_object to specify its
    drawing order.  Game_objects with smaller numbers are drawn before
    Game_objects with larger numbers.  Thus the Game_object with the
    largest drawing_order number is drawn last and will thus appear on
    top of all other game objects.

****/

#include "gpl_type.h"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#include <string>
#include <map>
#include <vector>

class Animation_block;

class Game_object
{
  public:

    Game_object(double red = 0.5, double green = 0.5, double blue = 0.5);
    virtual ~Game_object();
    const std::string type() const {return m_object_type_name;}

    void draw();

    Status set_member_variable(std::string name, int value);
    Status set_member_variable(std::string name, double value);
    Status set_member_variable(std::string name, std::string value);
    Status set_member_variable(std::string name, Animation_block *block);

    Status get_member_variable_type(std::string name, Gpl_type &type);

    Status get_member_variable(std::string name, int &value);
    Status get_member_variable(std::string name, double &value);
    Status get_member_variable(std::string name, std::string &value);
    Status get_member_variable(std::string name, Animation_block *&value);

    bool visible() {return m_visible;}

    // a game object used as a parameter should never be drawn or animated
    // it is just used as a placeholder for the actual parameter
    // thus when creating an object to be used as a parameter, set them
    // to by calling never_draw() and never_animate()
    void never_draw() {m_should_draw = false;}
    void never_animate() {m_should_animate = false;}

    int touches(Game_object *obj);
    int near(Game_object *obj);

    // if no objects have changed, do not draw
    static bool graphics_out_of_date_with_last_rendering();

    // draw all game objects in the vector all_game_objects
    static void draw_all_game_objects();

    static void animate_all_game_objects();
    void animate();

    bool valid() const;

    std::ostream &print(std::ostream &os) const;

  protected:
    void insert_into_all_game_objects_vector();
    void update_order_in_game_objects_vector();

    void register_member_variable(std::string name, int *value)
     { register_member_variable(INT, name, (void *) value);}
    void register_member_variable(std::string name, double *value)
     { register_member_variable(DOUBLE, name, (void *) value);}
    void register_member_variable(std::string name, std::string *value)
     { register_member_variable(STRING, name, (void *) value);}
    void register_member_variable(std::string name, Animation_block **value)
     { register_member_variable(ANIMATION_BLOCK, name, (void *) value);}

    Status mark_member_variable_as_derived(std::string name);
      
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    double m_red;
    double m_green;
    double m_blue;
    Animation_block *m_animation_block;
    int m_visible;
    int m_proximity;
    bool m_should_draw;
    bool m_should_animate;
    bool m_display_list_dirty;
    int m_drawing_order;
    int m_user_int;
    double m_user_double;
    std::string m_user_string;
    int m_user_int2;
    double m_user_double2;
    std::string m_user_string2;
    int m_user_int3;
    double m_user_double3;
    std::string m_user_string3;
    int m_user_int4;
    double m_user_double4;
    std::string m_user_string4;
    int m_user_int5;
    double m_user_double5;
    std::string m_user_string5;

    std::string m_object_type_name;

    GLuint m_display_list;

    // each object that inherits us must implement build_display_list()
    virtual void build_display_list() = 0;

    // the default is to mark the display list as dirty when any member
    // variable changes.  Subclasses can redefine this behavior if the
    // display list changes only when some members fields are changed
    virtual void updated(std::string name) {m_display_list_dirty = true;}

  private:
    class Typed_void_ptr
    {
      public:
        Typed_void_ptr(Gpl_type type, void *value)
         {m_type = type; m_value = value; m_derived = false;}
          Gpl_type m_type;
        void *m_value;
        bool m_derived;
    };

    std::map<std::string, Typed_void_ptr *> m_variable_registry;
    Typed_void_ptr* lookup_registered_member_variable(std::string name);
    void register_member_variable(Gpl_type type,
                                  std::string name,
                                  void *value
                                 );

    static std::vector<Game_object *> all_game_objects;
    static std::vector<Game_object *> deleted_game_objects;
    static bool graphics_dirty;

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Game_object(const Game_object &);
    const Game_object &operator=(const Game_object &);
};

std::ostream &operator<<(std::ostream &os, const Game_object &game_object);
std::ostream &operator<<(std::ostream &os, const Game_object *game_object);

#endif // #ifndef GAME_OBJECT_H
