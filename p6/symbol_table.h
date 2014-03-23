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
    Symbol* get(string name, int newValue);
    Symbol* get(string name, double newValue);
    Symbol* get(string name, string newValue);
    Gpl_type get_type(string name, Gpl_type type);
    void set(string name, int newValue);
    void set(string name, double newValue);
    void set(string name, string newValue);
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



