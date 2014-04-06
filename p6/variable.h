#pragma once
#include "expr.h"
#include "symbol_table.h"
#include "symbol.h"
#include <sstream>
#include "game_object.h"
#include "animation_block.h"
using namespace std;
class Expr;

class Variable
{
    public:      
        Variable(string value);
        Variable(string value, Expr* expr);
        Variable(string value, string parameter);
        Symbol* eval();
    private:
        Symbol* symbol;
        Expr* expression;
        string name;
        string second;
};
