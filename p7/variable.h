#pragma once
#include "expr.h"
#include "symbol_table.h"
#include "symbol.h"
#include <sstream>
#include "game_object.h"
#include "animation_block.h"
#include "gpl_assert.h" 
#include <string>
#include "error.h"
using namespace std;
class Expr;

enum Var_type{
    STANDARD,
    OBJECT_PARAM
};
class Variable
{
    public:      
        Variable(string value);
        Variable(string value, Expr* expr);
        Variable(string value, string parameter);
        Variable(string value, Expr* expr, string parameter);
        Var_type getType();
        int getIntValue(Symbol* sym);
        double getDoubleValue(Symbol* sym);
        string getStringValue(Symbol* sym);
        void setIntParam(Symbol* sym, int newValue);
        void setDoubleParam(Symbol* sym, double newValue);
        void setStringParam(Symbol* sym, string newValue);
        string getParam();
        Gpl_type getParamType(Symbol* sym);
        void setParam(string newParam);
        Symbol* eval();
    private:
        Symbol* symbol;
        Expr* expression;
        Var_type type;
        string name;
        string param;
};
