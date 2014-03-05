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
    gpl_type = DOUBLE;
    double_value = value;
    kind = DOUBLE_CONST;
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
    lhs = newlhs;
    rhs = newrhs;
    kind = BINARY_OP;
    if(operator_type == MULTIPLY)
    {
        if(lhs->getKind() == INT_CONST)
        {
            if(rhs->getKind() == INT_CONST)
            {
                gpl_type = INT;
            }
            else if(rhs->getKind() == DOUBLE_CONST)
            {
                gpl_type = DOUBLE;
            }
        }
        else if(lhs->getKind() == DOUBLE_CONST)
        {
            if(rhs->getKind() == INT_CONST)
            {
                gpl_type = INT;
            }
            else if(rhs->getKind() == DOUBLE_CONST)
            {
                gpl_type = DOUBLE;
            }
        }
        
    }
}
int Expr::eval_int()
{
    if(kind == BINARY_OP)
    {
        if(operator_type == MULTIPLY)
        {            
            return lhs->eval_int() * rhs->eval_int();
        }
    }
    else if(kind == INT_CONST)
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
Gpl_type Expr::getGplType()
{
    return gpl_type;
}
Operator_type Expr::getOperatorType()
{
    return operator_type;
}
Kind Expr::getKind()
{
    return kind;
}


