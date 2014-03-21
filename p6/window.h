/***

Class Window provides a wrapper to the OpenGL window

It handles the animation by calling:

  symbol_table->animate_all_game_objects();

 on every clock tick.  Symbol_table::animate_all_game_objects() should
 be implemented so that it calls the animate function for all game_objects.

It distributes events handed to it by the windowing system by calling

    event_manager->execute_handlers(Event_manager::<key>);

 every time a key is pressed.  For example, when a space is pressed it calls:

    event_manager->execute_handlers(Event_manager::SPACE);

How to use class Window

 If you provide an class Event_manager which is a singleton and has the member
 function execute_handlers() and if you provide a class Symbol_table which is
 a singleton and has the member variable animate_all_game_objects() which

***/

#ifndef WINDOW_H
#define WINDOW_H

#include <string>

class Window
{
  public:

    // !!! Make sure "NUMBER_OF_KEYS" is updated when adding keystrokes !!!
    // or your program will have a really nasty memory bug
    enum Keystroke {
        SPACE = 0,
        LEFTARROW = 1,
        RIGHTARROW = 2,
        UPARROW = 3,
        DOWNARROW = 4,
        LEFTMOUSE_DOWN = 5,
        MIDDLEMOUSE_DOWN = 6,
        RIGHTMOUSE_DOWN = 7,
        LEFTMOUSE_UP = 8,
        MIDDLEMOUSE_UP = 9,
        RIGHTMOUSE_UP = 10,
        MOUSE_MOVE = 11,
        MOUSE_DRAG = 12,
        F1 = 13,
        AKEY = 14,
        SKEY = 15,
        DKEY = 16,
        FKEY = 17,
        HKEY = 18,
        JKEY = 19,
        KKEY = 20,
        LKEY = 21,
        WKEY = 22,
        INITIALIZE = 23,
        NUMBER_OF_KEYS = 24 // UPDATE to one more than last one if adding a key!!!
       };

    Window(int x, int y, int w, int h, std::string title, int speed,
           double red, double green, double blue,
           bool read_keypresses_from_standard_input = false);

    void initialize();
    void main_loop();
    int width() {return m_w;}
    int height() {return m_h;}
    void set_width(int width);
    void set_height(int height);

    void dump_pixels(const char *dumpwindow_filename);

  private:
    void initialize(int argc, char **argv);

    int m_x;
    int m_y;
    int m_w;
    int m_h;
    std::string m_title;
    bool m_read_keypresses_from_standard_input;

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Window(const Window &);
    const Window &operator=(const Window &);

};

#endif // #ifndef WINDOW_H
