
#include "game_object.h"
#include "animation_block.h"
#include "indent.h"
#include "gpl_assert.h"
#include "error.h"
#include <algorithm>
using namespace std;

// all game objects that have been created but not deleted
// used for (1) error checking via valid() (2) drawing all game objects
/* static */ vector<Game_object *> Game_object::all_game_objects;

// all game objects that have been deleted
// used for error checking via has_been_deleted()
/* static */ vector<Game_object *> Game_object::deleted_game_objects;

/* static */ bool Game_object::graphics_dirty = true;

void Game_object::insert_into_all_game_objects_vector()
{
  // all_game_objects is a vector sorted by drawing_order
  // Sorted small to large (small drawing_order drawn first/on bottom)

  // find the first iter w/a larger or equal m_drawing_order compared to this
  vector<Game_object *>::iterator iter = all_game_objects.begin();
  while (iter != all_game_objects.end()
     && (*iter)->m_drawing_order < m_drawing_order)
     iter++;
  
  // this object has a larger drawing_order than any object in vector
  if (iter == all_game_objects.end())
    all_game_objects.push_back(this);
  // the game object pointed to by iter is the first one in the vector
  // that has a drawing order larger or equal to this
  // insert before this object
  else all_game_objects.insert(iter,this);

}

// call when the drawing_order for a Game_object changes
// removes the object from the all_game_objects vector and
// inserts it in the correct position
void Game_object::update_order_in_game_objects_vector()
{
  // remove this from all_game_objects
  vector<Game_object *>::iterator iter =
      find(all_game_objects.begin(), all_game_objects.end(), this);
  assert(iter != all_game_objects.end());
  all_game_objects.erase(iter);

  // now put it back -- it will go in the correct place this time
  insert_into_all_game_objects_vector();
}

/* static */ bool Game_object::graphics_out_of_date_with_last_rendering()
{
  bool result = graphics_dirty;
  graphics_dirty = false;
  return result;
}

/* static */ void Game_object::animate_all_game_objects()
{
  vector<Game_object *>::iterator iter;
  for (iter = all_game_objects.begin();
    iter != all_game_objects.end();
    iter++)
  {
    Game_object *cur = *iter;
    if (cur->m_should_animate)
      cur->animate();
  }
}

/* static */ void Game_object::draw_all_game_objects()
{
  vector<Game_object *>::iterator iter;
  for (iter = all_game_objects.begin();
    iter != all_game_objects.end();
    iter++)
  {
    if ((*iter)->m_should_draw)
      (*iter)->draw();
  }
}

Game_object::Game_object(double red /* =  0.5 */,
                         double green /* = 0.5 */,
                         double blue /* =  0.5 */
                         )
{
  m_x = 0;
  m_y = 0;
  m_w = 10;
  m_h = 10;
  m_red = red;
  m_green = green;
  m_blue = blue;
  m_animation_block = 0;
  m_visible = 1;
  m_proximity = 4;
  m_drawing_order = 0;
  m_user_int = 0;
  m_user_double = 0.0;
  m_user_string = "";
  m_user_int2 = 0;
  m_user_double2 = 0.0;
  m_user_string2 = "";
  m_user_int3 = 0;
  m_user_double3 = 0.0;
  m_user_string3 = "";
  m_user_int4 = 0;
  m_user_double4 = 0.0;
  m_user_string4 = "";
  m_user_int5 = 0;
  m_user_double5 = 0.0;
  m_user_string5 = "";

  // OpenGL is not initialized enough yet to create our
  // display list.  Use a unique number so that draw()
  // will know it is the first time it is called.
  m_display_list = 0;
  m_display_list_dirty = true;

  // objects that are place holders for parameters to animation_blocks
  // should never be drawn or animated (they are not "real" objects)
  // the functions never_draw() and never_animate() reset these
  // however, all others objects should be drawn and animated
  m_should_draw = true;
  m_should_animate = true;

  // Set my type name
  // --> must be done by all that inherit me
  m_object_type_name = "Game_object";

  // register my variable that can be set/get from parser
  // --> each object that inherits me that wants to have any of
  // --> its member variables settable, must do the same for each
  register_member_variable("x", &m_x);
  register_member_variable("y", &m_y);
  register_member_variable("w", &m_w);
  register_member_variable("h", &m_h);
  register_member_variable("red", &m_red);
  register_member_variable("green", &m_green);
  register_member_variable("blue", &m_blue);
  register_member_variable("animation_block", &m_animation_block);
  register_member_variable("visible", &m_visible);
  register_member_variable("proximity", &m_proximity);
  register_member_variable("drawing_order", &m_drawing_order);
  register_member_variable("user_int", &m_user_int);
  register_member_variable("user_double", &m_user_double);
  register_member_variable("user_string", &m_user_string);
  register_member_variable("user_int2", &m_user_int2);
  register_member_variable("user_double2", &m_user_double2);
  register_member_variable("user_string2", &m_user_string2);
  register_member_variable("user_int3", &m_user_int3);
  register_member_variable("user_double3", &m_user_double3);
  register_member_variable("user_string3", &m_user_string3);
  register_member_variable("user_int4", &m_user_int4);
  register_member_variable("user_double4", &m_user_double4);
  register_member_variable("user_string4", &m_user_string4);
  register_member_variable("user_int5", &m_user_int5);
  register_member_variable("user_double5", &m_user_double5);
  register_member_variable("user_string5", &m_user_string5);

  insert_into_all_game_objects_vector();
}

Game_object::~Game_object()
{

  vector<Game_object *>::iterator iter =
      find(all_game_objects.begin(), all_game_objects.end(), this);
  assert(iter != all_game_objects.end());

  deleted_game_objects.push_back(*iter);

  all_game_objects.erase(iter);
}

void Game_object::draw()
{
  if (!m_visible)
      return;
  if (m_display_list_dirty)
  {
    if (m_display_list == 0)
      m_display_list = glGenLists(1);

    build_display_list();
    m_display_list_dirty = false;
  }
  //   it might be more efficient to move the translation for m_x and m_y
  //   out of the display list
  //   a) if most objects move, it will probably be faster to take it out of
  //      the display list
  //   b) if most objects don't move, it will be faster to leave it in
  //   unclear if there is an efficiency problem...

  glCallList(m_display_list);
}

Status Game_object::get_member_variable_type(string name, Gpl_type &type)
{
  Typed_void_ptr* typed_void_ptr = lookup_registered_member_variable(name);

  if (typed_void_ptr)
  {
    type = typed_void_ptr->m_type;
    return OK;
  }
  else
  {
    return MEMBER_NOT_DECLARED;
  }
}

Status Game_object::set_member_variable(string name, int value)
{
  graphics_dirty = true;
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
      return MEMBER_NOT_DECLARED;
  if (variable->m_type != INT)
    return MEMBER_NOT_OF_GIVEN_TYPE;
  assert(variable->m_value);


  if (variable->m_derived)
    Error::error(Error::CANNOT_CHANGE_DERIVED_ATTRIBUTE,
          name, m_object_type_name);
  
  else *((int *) variable->m_value) = value;

  // when drawing_order is changed, need to update the drawing order
  if (name == "drawing_order")
    update_order_in_game_objects_vector();

  updated(name);
  return OK;
}

Status Game_object::set_member_variable(string name, double value)
{
  graphics_dirty = true;
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
      return MEMBER_NOT_DECLARED;
  if (variable->m_type != DOUBLE)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  assert(variable->m_value);

  *((double *) variable->m_value) = value;

  updated(name);
  return OK;
}

Status Game_object::set_member_variable(string name, string value)
{
  graphics_dirty = true;
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
      return MEMBER_NOT_DECLARED;
  if (variable->m_type != STRING)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  assert(variable->m_value);

  *((string *) variable->m_value) = value;
  updated(name);
    
  return OK;
}

Status Game_object::set_member_variable(string name, Animation_block *value)
{
  graphics_dirty = true;
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;
  if (variable->m_type != ANIMATION_BLOCK)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  assert(variable->m_value);

  // note, we don't dereference m_value as above because
  // we store Animation_blocks as pointers
  *((Animation_block **) variable->m_value) = value;

  updated(name);
  return OK;
}

Status Game_object::get_member_variable(string name, int &value)
{
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;
  if (variable->m_type != INT)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  value = *((int *) variable->m_value);
  return OK;
}

Status Game_object::get_member_variable(string name, double &value)
{
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;

  if (variable->m_type == DOUBLE)
  {
    value = *((double *) variable->m_value);
    return OK;
  }
  else return MEMBER_NOT_OF_GIVEN_TYPE;
}

Status Game_object::get_member_variable(string name, string &value)
{
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;
  if (variable->m_type != STRING)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  value = *((string *) variable->m_value);
  return OK;
}

Status Game_object::get_member_variable(string name, Animation_block *&value)
{
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;
  if (variable->m_type != ANIMATION_BLOCK)
    return MEMBER_NOT_OF_GIVEN_TYPE;

  // note, we don't dereference m_value as above because
  // we store Animation_blocks as pointers
  value = *((Animation_block **) variable->m_value);
  return OK;
}


static bool overlap(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2
                   )
{
  return !(ax2 < bx1 || ax1 > bx2 || ay1 > by2 || ay2 < by1);
}

// since gpl does not have a bool, touches() and near() return an int to reduce
// confusion between ints and bools
int Game_object::touches(Game_object *obj)
{

/*****
LIMITATION

touches uses the bounding box of the object which is created at object
construction.

The bounding box is not a very good representation of triangles or circles.
And it does not take into account the rotation of either triangles
or rectangles.

It would make the touches mechanism better if objects were represented
with a more accurate boundary.

Idea 1:  use a polygon to represent the bounding boxes.  Each type of
object could create and update their polygon.  When line segments of the
polygons of two objects intersect the two objects would be considered touching.
This approach does not handle containment (when one object is completely
inside another).

Idea 2: represent each object as a set of triangles.  When segments of
triangles of two objects intersect, the objects touch.  Could also look
for a vertex inside of another object's triangle.
*****/


  // true if the bounding boxes of this and obj overlap
  return overlap(m_x, m_y, m_x + m_w, m_y + m_h,
         obj->m_x, obj->m_y, obj->m_x + obj->m_w, obj->m_y+obj->m_h);
}

int Game_object::near(Game_object *obj)
{

  // expand the bounding boxes of this and obj by their respective m_proximity
  // true if the expanded bounding boxes of this and obj overlap
  return overlap(m_x - m_proximity, m_y - m_proximity,
           m_x + m_w + m_proximity, m_y + m_h + m_proximity,
         obj->m_x - obj->m_proximity, obj->m_y - obj->m_proximity,
         obj->m_x + obj->m_w + obj->m_proximity,
         obj->m_y+obj->m_h + obj->m_proximity);
}

Game_object::Typed_void_ptr* Game_object::lookup_registered_member_variable(string name)
{
    // Check if name in map of registered_member_variables
    map<string, Typed_void_ptr *>::iterator iter;
    iter = m_variable_registry.find(name);
    if (iter == m_variable_registry.end())
    {
      return 0;
    }
    return (*iter).second;
}

void Game_object::register_member_variable(Gpl_type type,
                                           string name,
                                           void *value
                                          )
{
    assert(type == INT || type == DOUBLE
           || type == STRING || type == ANIMATION_BLOCK
          );

    // make sure this member variable has not already been registered
    assert(!lookup_registered_member_variable(name));

    // insert this member variable into the registry as type "type"
    m_variable_registry[name] = new Typed_void_ptr(type, (void *)value);
}

Status Game_object::mark_member_variable_as_derived(string name)
{
  Typed_void_ptr *variable = lookup_registered_member_variable(name);
  if (!variable)
    return MEMBER_NOT_DECLARED;
  variable->m_derived = true;
  return OK;
}


void Game_object::animate()
{
  if (m_animation_block)
  {
    // Call our own animation block
    // Animation blocks are special type of statement block that ALWAYS
    // contain a pointer to a symbol in the symbol_table that represent
    // a parameter.

    // When this object calls its animation block, it must pass itself
    // <this> to the execute function of the animation_block


    if (!m_animation_block->empty())
      m_animation_block->execute(this);
    // else do nothing

  }
}

bool Game_object::valid() const
{
  vector<Game_object *>::iterator iter =
      find(all_game_objects.begin(), all_game_objects.end(), this);
  return iter != all_game_objects.end();
}

ostream & Game_object::print(ostream &os) const
{
  os << indent << m_object_type_name /* << "<" << (void *) this << ">" */
     << endl << indent << "{" << endl;
  os.flush();
  indent++;

  map<string, Typed_void_ptr *>::const_iterator iter;
  for (iter = m_variable_registry.begin();
    iter != m_variable_registry.end();
    iter++
    )
  {
    if (iter != m_variable_registry.begin())
      os << "," << endl;

    Typed_void_ptr *cur_member = (*iter).second;
    string cur_name = (*iter).first;

    os << indent << cur_name << " = ";
    switch (cur_member->m_type)
    {
      case INT:
        os << "int(" << *((int *) cur_member->m_value) << ")";
        break;
      case DOUBLE:
        os << "double(" << *((double *) cur_member->m_value) << ")";
        break;
      case STRING:
        os << "string(\"" << *((string *) cur_member->m_value)<< "\")";
        break;
      case ANIMATION_BLOCK:
        if (*((Animation_block **) (cur_member->m_value)) == 0)
          os << "animation_block(0)";
        else
        {
          indent++;
          os << endl<< *((Animation_block **) (cur_member->m_value));
          indent--;
        }
        break;
      default:
        // there is a programming bug if this is ever executed
        assert(false);
    }
  } // for loop iterating through all registered member variables
  os << endl;
  indent--;
  os << indent << "}";
  return os;
}

ostream & operator<<(ostream &os, const Game_object &game_object)
{
  return game_object.print(os);
}

ostream & operator<<(ostream &os, const Game_object *game_object)
{
  if (!game_object)
  {
    os << indent << "Game_object{NULL}";
    return os;
  }
  else return game_object->print(os);
}
