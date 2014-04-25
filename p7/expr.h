
enum Kind {
    INT_CONST,
    DOUBLE_CONST,
    STRING_CONST,
    BINARY_OP,
    UNARY_OP,
    VARIABLE
};

#pragma once
class Variable;
#include <string>
#include <cmath>
#include <stdlib.h>
#define PI 3.14159265
#include "variable.h"
#include "gpl_type.h"
#include "game_object.h"
#include "animation_block.h"
#include <ctype.h>
using namespace std;
class Expr
{
    public:
        Expr(int value);
        Expr(double value);
        Expr(string value);
        Expr(Operator_type newtype, Expr *newlhs, Expr *newrhs); // for the operators
        Expr(Operator_type newtype, Expr *newlhs);
        Expr(Variable* value);
        int eval_int();
        double eval_double();
        string eval_string();
        Game_object* eval_game_object();
        Animation_block* eval_animation_block();
        Gpl_type getGplType();
        Operator_type getOperatorType();
        Kind getKind();
        Variable* getVariable();
    private:
        Gpl_type gpl_type;
        Operator_type operator_type;
        Kind kind;
        int int_value;
        double double_value;
        string string_value;
        Variable* variable_value;
        Expr* lhs;
        Expr* rhs;
};
