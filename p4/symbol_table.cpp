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
