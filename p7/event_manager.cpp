#include "event_manager.h"
#include "gpl_assert.h"
using namespace std;

/* static */ Event_manager *Event_manager::m_instance = 0;

/* static */ Event_manager * Event_manager::instance()
{
  if (!m_instance)
    m_instance = new Event_manager();
  return m_instance;
}

Event_manager::Event_manager()
{

}

Event_manager::~Event_manager()
{
}

void 
Event_manager::execute_handlers(Window::Keystroke keystroke)
{
	for(unsigned int i = 0; i < handlers[keystroke].size(); i++)
	{
		handlers[keystroke][i]->execute();
	}
}

void 
Event_manager::register_handler(Window::Keystroke keystroke, Statement_block* newBlock)
{
	handlers[keystroke].push_back(newBlock);
}
