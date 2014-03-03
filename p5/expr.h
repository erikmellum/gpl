
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
#include "gpl_type.h"
using namespace std;
class Expr
{
    public:
        Expr(int value);
        Expr(double value);
        Expr(string value);
        Expr(Operator_type type, Expr *newlhs, Expr *newrhs); // for the operators
        Expr(Operator_type type, Expr *newlhs);
        Expr(Variable* value);
        int eval_int();
        double eval_double();
        string eval_string();
        string getType();
        Kind getKind();
    private:
        string type;
        Kind kind;
        int int_value;
        double double_value;
        string string_value;
        Variable* variable_value;
        Expr* lhs;
        Expr* rhs;
};
