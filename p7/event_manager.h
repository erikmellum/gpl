/***
  This file is a placeholder for the Event_manager class you will write 
  in phase 7 (p7).

  My class Window uses class Event_manager.  Since p6 uses class Window
  you need this placeholder class to get p6 to work.

  You may use this file and event_manager.cpp w/o modification in p6.

  You may use them as a starting point for your Event_manager class for p7.

  I have put in just enough for it to work in p6.

***/

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "statement_block.h"
#include "window.h" // for Keystroke enum

class Statement_block;

class Event_manager
{
  public:

    static Event_manager *instance();

    void execute_handlers(Window::Keystroke keystroke);
    void register_handler(Window::Keystroke keystroke, Statement_block* newBlock);
    ~Event_manager();

  private:
    // hide default constructor because this is a singleton
    Event_manager();
    vector<Statement_block*> handlers[Window::NUMBER_OF_KEYS];
    static Event_manager *m_instance;

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Event_manager(const Event_manager&); 
    const Event_manager &operator=(const Event_manager&); 
};

#endif // #ifndef EVENT_MANAGER_H
