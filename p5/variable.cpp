#include "variable.h"

#pragma once

using namespace std;

Variable::Variable(string value)
{
    name = value;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    expression = expr;
}
Symbol* Variable::eval()
{
    Symbol_table *symbol_table = Symbol_table::instance();
    if(symbol_table->lookup(name))
    {
        return symbol_table->retrieve(name);
    }
    return NULL;
}
