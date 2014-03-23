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
    else if(type == UNARY_MINUS)
    {
        if(lhs->getKind() == INT_CONST)
            gpl_type = INT;
        else if(lhs->getKind() == DOUBLE_CONST)
            gpl_type = DOUBLE;
    }
    else if(type == RANDOM)
    {
        gpl_type = INT;
    }
    else if(type == NOT)
    {
        gpl_type = INT;
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
        if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
        {
            gpl_type = DOUBLE;
        }
        else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
        {
            gpl_type = INT;
        }    
    }
    else if(operator_type == DIVIDE)
    {
        if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
        {
            gpl_type = DOUBLE;
        }
        else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
        {
            gpl_type = INT;
        }    
    }
    else if(operator_type == PLUS)
    {
        if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
        {                         
            gpl_type = STRING;
        }
        else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
        {
            gpl_type = DOUBLE;
        }
        else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
        {
            gpl_type = INT;
        }
    }
    else if(operator_type == MINUS)
    {
        if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
        {
            gpl_type = DOUBLE;
        }
        else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
        {
            gpl_type = INT;
        }
    }
    else if(operator_type == EQUAL || operator_type == AND || operator_type == OR
    || operator_type == GREATER_THAN_EQUAL || operator_type == GREATER_THAN ||
    operator_type == LESS_THAN_EQUAL || operator_type == LESS_THAN 
    || operator_type == NOT_EQUAL || operator_type == MOD)
    {
        gpl_type = INT;
    }
}
int Expr::eval_int()
{
    if(kind == BINARY_OP)
    {
        if(operator_type == MULTIPLY)
        {       
            return (lhs->eval_int() * rhs->eval_int());
        }
        else if(operator_type == DIVIDE)
        {
            return (lhs->eval_int() / rhs->eval_int());
        }
        else if(operator_type == MINUS)
        {
            return (lhs->eval_int() - rhs->eval_int());
        }
        else if(operator_type == PLUS)
        {
            return (lhs->eval_int() + rhs->eval_int());
        }
        else if(operator_type == MOD)
        {
            return (lhs->eval_int() % rhs->eval_int());
        }
        else if(operator_type == EQUAL)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() == rhs->eval_string());
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() == rhs->eval_double());
            }   
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() == rhs->eval_int());
            }               
        }
        else if(operator_type == NOT_EQUAL)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() != rhs->eval_string());
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() != rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() != rhs->eval_int());
            }  
        }
        else if(operator_type == AND)
        {
            if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() && rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() && rhs->eval_int());
            }
        }
        else if(operator_type == OR)
        {
            if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() || rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() || rhs->eval_int());
            }
        }
        else if(operator_type == GREATER_THAN_EQUAL)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() >= rhs->eval_string());      
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() >= rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() >= rhs->eval_int());
            }
        }
        else if(operator_type == GREATER_THAN)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() > rhs->eval_string());      
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() > rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() > rhs->eval_int());
            }
        }
        else if(operator_type == LESS_THAN_EQUAL)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() <= rhs->eval_string());      
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() <= rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() <= rhs->eval_int());
            }
        }
        else if(operator_type == LESS_THAN)
        {
            if(lhs->getGplType() == STRING || rhs->getGplType() == STRING)
            {
                return (lhs->eval_string() < rhs->eval_string());      
            }
            else if(lhs->getGplType() == DOUBLE || rhs->getGplType() == DOUBLE)
            {
                return (lhs->eval_double() < rhs->eval_double());
            }
            else if(lhs->getGplType() == INT && rhs->getGplType() == INT)
            {
                return (lhs->eval_int() < rhs->eval_int());
            }
        }
    }
    else if(kind == UNARY_OP)
    {
        if(operator_type == UNARY_MINUS)
        {
            return lhs->eval_int()*-1;
        }
        else if(operator_type == RANDOM)
        {
            return rand() % lhs->eval_int();
        }
        else if(operator_type == NOT)
        {
            if(lhs->getGplType() == INT)
            {
                return lhs->eval_int() ? 0 : 1;
            }
            else if(lhs->getGplType() == DOUBLE)
            {
                return lhs->eval_double() ? 0 : 1;
            }
        }
        else if(operator_type == FLOOR)
        {
            if(lhs->getGplType() == INT)
            {
                return floor(lhs->eval_int());
            }
            else if(lhs->getGplType() == DOUBLE)
            {
                return floor(lhs->eval_double());
            }
        }
        else if(operator_type == ABS)
        {
            return abs(lhs->eval_int());
        }
    }
    else if(kind == INT_CONST)
        return int_value;
    else if(kind == DOUBLE_CONST)
        return (int) double_value;
    else if(kind == VARIABLE)
    {
        if(variable_value->eval()->getType() == DOUBLE)
            return (int) variable_value->eval()->getDouble();
        else
            return variable_value->eval()->getInt();
    }
    return 0;
}
double Expr::eval_double()
{
    if(gpl_type == INT)
    {
        return eval_int();
    }
    else if(kind == BINARY_OP)
    {
        if(operator_type == MULTIPLY)
        {            
            return (lhs->eval_double() * rhs->eval_double());
        }
        else if(operator_type == DIVIDE)
        {
            return (lhs->eval_double() / rhs->eval_double());
        }
        else if(operator_type == PLUS)
        {
            return (lhs->eval_double() + rhs->eval_double());
        }
        else if(operator_type == MINUS)
        {
            return (lhs->eval_double() - rhs->eval_double());
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
            return cos(lhs->eval_double()*PI/180);
        }
        else if(operator_type == TAN)
        {
            return tan(lhs->eval_double()*PI/180);
        }
        else if(operator_type == ASIN)
        {
            return asin(lhs->eval_double())*180/PI;
        }
        else if(operator_type == ACOS)
        {
            return acos(lhs->eval_double())*180/PI;
        }
        else if(operator_type == ATAN)
        {
            return atan(lhs->eval_double())*180/PI;
        }
        else if(operator_type == SQRT)
        {
            return sqrt(lhs->eval_double());
        }
        else if(operator_type == ABS)
        {
            return abs(lhs->eval_double());
        }
        else if(operator_type == UNARY_MINUS)
        {
            return lhs->eval_double()*-1;
        }
    }
    else if(kind == DOUBLE_CONST)
    {
        return double_value;
    }
    else if(kind == VARIABLE)
    {
        return variable_value->eval()->getDouble();
    }
    return 0;
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
            if(gpl_type == INT)
            {
                ostringstream oss;
                oss << lhs->eval_int();
                return oss.str();
            }
            else if(gpl_type == DOUBLE)
            {
                ostringstream oss;
                oss << eval_double();
                return oss.str();
            }
            else if(gpl_type == STRING)
                return lhs->eval_string() + rhs->eval_string();
        }
    }
    return "";
}
Game_object* Expr::eval_game_object()
{
    if(kind == VARIABLE)
    {
        if(gpl_type == GAME_OBJECT)
        {
            return(variable_value->eval()->getGameObject());
        }
    }
}
Animation_block* Expr::eval_animation_block()
{
    if(kind == VARIABLE)
    {
        if(gpl_type == ANIMATION_BLOCK)
        {
            return(variable_value->eval()->getAnimationBlock());
        }
    }
}
//////////////////////
// Helper functions //
//////////////////////
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