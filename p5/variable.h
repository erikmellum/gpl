#pragma once
#include "expr.h"
#include "symbol_table.h"
#include "symbol.h"

class Variable
{
    public:      
        Variable(int value);
        Variable(string value);
        Variable(string value, Expr* expr);
        Symbol* eval();
    private:
        string name;
        Expr* left;
        Expr* right;
};
