#include "expr.h"

Expr::Expr(int value)
{
    type = INT;
    int_value = value;
    kind = INT_CONST;
}
Expr::Expr(double value)
{
    double_value = value;
}
Expr::Expr(string value)
{
    string_value = value;
}
Expr::Expr(Variable* value)
{
    variable_value = value;
}
int Expr::eval_int()
{
    if(kind == INT_CONST)
        return int_value;
    return -1;
}
double Expr::eval_double()
{
    return 0;
}
string Expr::eval_string()
{
    return "";
}
string Expr::getType()
{
    return type;
}
Kind Expr::getKind()
{
    return kind;
}


