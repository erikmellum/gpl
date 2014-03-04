#include "variable.h"
#include "expr.h"

Expr::Expr(int value)
{
    gpl_type = INT;
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
    kind = VARIABLE;
    gpl_type = value->eval()->getType();
    variable_value = value;
}
Expr::Expr(Operator_type type, Expr *newlhs, Expr *newrhs)
{
    operator_type = type;
    
    //eval lhs
    lhs = newlhs;
    //eval rhs
    rhs = newrhs;
    //apply operator
}
int Expr::eval_int()
{
    if(kind == INT_CONST)
        return int_value;
    else if(kind == VARIABLE)
        return variable_value->eval()->getInt();
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
Gpl_type Expr::getType()
{
    if(gpl_type)
        return gpl_type;
}
Operator_type Expr::getType()
{
    if(operator_type)
        return operator_type;
}
Kind Expr::getKind()
{
    return kind;
}


