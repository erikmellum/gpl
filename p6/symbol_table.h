#include <map>
#include "symbol.h"

using namespace std;
#pragma once

class Symbol_table
{
  public:
    static Symbol_table *instance();
    void print(ostream &os);
    void insert(Symbol* newSymbol);
    Symbol* retrieve(string name);
    bool get(string name, int &value);
    bool get(string name, double &value);
    bool get(string name, string &value);
    bool get_type(string name, Gpl_type &type);
    bool set(string name, int value); // used for mouse_x, mouse_y
    bool lookup(string name);
    void remove(string symbolToRemove);
    
  private:
    static Symbol_table *m_instance;
    Symbol_table() {};
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);
    map<string, Symbol*> symbol_table;
    public:
    
};



