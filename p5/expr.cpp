
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
    gpl_type = STRING;
    string_value = value;
    kind = STRING_CONST;
}
Expr::Expr(Variable* value)
{
    kind = VARIABLE;
    gpl_type = value->eval()->getType();
    variable_value = value;
}
Expr::Expr(Operator_type type, Expr *newlhs)
{
    kind = UNARY_OP;
    operator_type = type;
    lhs = newlhs;
    if(type ==  FLOOR || type == RANDOM)
        gpl_type = INT;
    else if (type == ABS)
    {
        if(lhs->getKind() == INT_CONST)
            gpl_type = INT;
        else if(lhs->getKind() == DOUBLE_CONST)
            gpl_type = DOUBLE;
    }
    else
    {
        gpl_type = DOUBLE;
    }
    
}
Expr::Expr(Operator_type type, Expr *newlhs, Expr *newrhs)
{
    operator_type = type;
    lhs = newlhs;
    rhs = newrhs;
    kind = BINARY_OP;
    if(operator_type == MULTIPLY)
    {
        if(lhs->getGplType() == INT)
        {
            if(rhs->getGplType() == INT)
            {
                gpl_type = INT;
            }
            else if(rhs->getGplType() == DOUBLE)
            {
                gpl_type = DOUBLE;
            }
        }
        else if(lhs->getGplType() == DOUBLE)
        {
            if(rhs->getGplType() == INT)
            {
                gpl_type = INT;
            }
            else if(rhs->getGplType() == DOUBLE)
            {
                gpl_type = DOUBLE;
            }
        }
        
    }
    else if(operator_type == PLUS)
    {
        if(lhs->getGplType() == STRING)
        {                
            if(rhs->getGplType() == STRING ||
            rhs->getGplType() == DOUBLE ||
            rhs->getGplType() == INT)
                gpl_type = STRING;
        }
        else if(rhs->getGplType() == STRING)
        {
            if(lhs->getGplType() == INT ||
            lhs->getGplType() == DOUBLE)
                gpl_type = STRING;
        }
        else if(lhs->getGplType() == INT)
        {
            if(rhs->getGplType() == INT)
                gpl_type = INT;
            else if(rhs->getGplType() == DOUBLE)
            {
                gpl_type = DOUBLE;
            }
        }
        else if(lhs->getGplType() == DOUBLE)
        {
            if(rhs->getGplType() == INT || rhs->getGplType() == DOUBLE)
                gpl_type = DOUBLE;
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
    else if(kind == UNARY_OP)
    {
    }
    else if(kind == INT_CONST)
        return int_value;
    else if(kind == VARIABLE)
        return variable_value->eval()->getInt();
    return -1;
}
double Expr::eval_double()
{

    if(kind == BINARY_OP)
    {
        if(operator_type == MULTIPLY)
        {            
            return lhs->eval_double() * rhs->eval_double();
        }
        else if(operator_type == PLUS)
        {
            return lhs->eval_double() + rhs->eval_double();
        }
    }
    else if(kind == UNARY_OP)
    {
        if(operator_type == SIN)
        {

            return sin(lhs->eval_double()*PI/180);
        }
        else if(operator_type == COS)
        {
            return cos(lhs->eval_int()*PI/180);
        }
        else if(operator_type == TAN)
        {
            return tan(lhs->eval_double()*PI/180);
        }
        else if(operator_type == ASIN)
        {
            return asin(lhs->eval_double()*PI/180);
        }
        else if(operator_type == ACOS)
        {
            return acos(lhs->eval_double()*PI/180);
        }
        else if(operator_type == ATAN)
        {
            return atan(lhs->eval_double()*PI/180);
        }
        else if(operator_type == SQRT)
        {
            return sqrt(lhs->eval_double());
        }
        else if(operator_type == ABS)
        {
            return abs(lhs->eval_double());
        }
        else if(operator_type == FLOOR)
        {
            return floor(lhs->eval_double());
        }
    }
    else if(kind == DOUBLE_CONST)
        return double_value;
    else if(kind == INT_CONST)
        return int_value;
    else if(kind == VARIABLE)
    {
        if(gpl_type == INT)
        {
            return variable_value->eval()->getInt();
        }
        else if(gpl_type == DOUBLE)
        {
            return variable_value->eval()->getDouble();
        }
    }
    return -1;
}
string Expr::eval_string()
{
    
    if(kind == STRING_CONST)
        return string_value;
    else if(kind == VARIABLE)
    {        

        if(gpl_type == INT)
        {
            ostringstream oss;
            oss << variable_value->eval()->getInt();
            return oss.str();
        }
        else if(gpl_type == DOUBLE)
        {        
            ostringstream oss;            
            oss << variable_value->eval()->getDouble();
            return oss.str();
        }
        else if(gpl_type == STRING)
            return variable_value->eval()->getString();
    }        
    else if(kind == INT_CONST)
    {
        ostringstream oss;
        oss << int_value;
        return oss.str();
    }
    else if(kind == DOUBLE_CONST)
    {
        ostringstream oss;
        oss << double_value;
        return oss.str();
    }
    else if(kind == BINARY_OP)
    {
        if(operator_type == PLUS)
        {    
            if(gpl_type == DOUBLE || gpl_type == INT)
            {
                ostringstream oss;
                oss << eval_double();
                return oss.str();
            }
            return lhs->eval_string() + rhs->eval_string();
        }
    }
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


