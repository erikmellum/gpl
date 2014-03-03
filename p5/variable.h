#pragma once
#include "expr.h"

class Variable
{
    public:      
        Variable(int value);
        Variable(string value);
        Variable(string value, Expr* expr);
    private:
        string name;
        Expr* left;
        Expr* right;
};
