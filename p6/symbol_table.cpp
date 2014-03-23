#include "symbol_table.h"
#include "symbol.h"
#include <iostream>

using namespace std;

Symbol_table *Symbol_table::m_instance = 0;

Symbol_table * Symbol_table::instance()
{
  if (m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}

void Symbol_table::print(ostream &os)
{
    for (map<string,Symbol*>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {        
        it->second->print(os);
    }
}
void Symbol_table::insert(Symbol* newSymbol)
{
    symbol_table.insert(pair<string,Symbol*>(newSymbol->getName(),newSymbol));
}
void Symbol_table::remove(string symbolToRemove)
{
    symbol_table.erase(symbolToRemove);
}
Symbol* Symbol_table::retrieve(string name)
{
    return symbol_table.at(name);
}
bool Symbol_table::lookup(string name)
{
    for (map<string,Symbol*>::iterator it=symbol_table.begin(); it!=symbol_table.end(); ++it)
    {
        if(it->second->getName() == name)
            return true;
    }
    // returns false if symbol not in the map
    return false;
}
bool Symbol_table::get(string name, int &value)
{
   Symbol *cur = retrieve(name);
   if (!cur || !cur->getType() == INT)
      return false;

   value = cur->getInt();
   return true;
}
bool Symbol_table::get(string name, double &value)
{
   Symbol *cur = retrieve(name);
   if (!cur || !cur->getType() == DOUBLE)
      return false;

   value = cur->getDouble();
   return true;
}
bool Symbol_table::get(string name, string &value)
{
   Symbol *cur = retrieve(name);
   if (!cur || !cur->getType() == STRING)
      return false;

   value = cur->getString();
   return true;
}
bool Symbol_table::get_type(string name, Gpl_type &type)
{
   Symbol *cur = retrieve(name);
   if (!cur)
      return false;

   type = cur->getType();
   return true;
}
bool Symbol_table::set(string name, int value)
{
    Symbol *cur = retrieve(name);
    if (!cur || !cur->getType() == INT)
      return false;

    cur->setInt(value);
    return true;
}
string gpl_type_to_string(Gpl_type myType)
{
    switch(myType)
    {
        case INT:
            return "int";
            break;
        case DOUBLE:
            return "double";
            break;
        case STRING:
            return "string";
            break;
        case GAME_OBJECT:
            return "game_object";
            break;
        case ANIMATION_BLOCK:
            return "animation_block";
            break;
    }
    return "";
}