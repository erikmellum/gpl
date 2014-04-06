#include "variable.h"

Variable::Variable(string value)
{
    name = value;
    second = "";
    expression = NULL;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    expression = expr;
    second = "";
}
Variable::Variable(string value, string parameter)
{
    name = value;
    second = parameter;
    expression = NULL;
}

Symbol* Variable::eval()
{
    Symbol_table *symbol_table = Symbol_table::instance();
    
    if(expression)
    {
    	int i = expression->eval_int();
    	stringstream ss;
    	ss << name << "[" << i << "]";
    	name = ss.str();
    }
    if(symbol_table->lookup(name))
    {
        Symbol* temp = symbol_table->retrieve(name);
        if(second != "")
        {
            if(temp->getType() == GAME_OBJECT)
            {
                Game_object* object = temp->getGameObject();
                Gpl_type type;
                object->get_member_variable_type(second, type);
                if(type == INT)
                {
                    int var;
                    object->get_member_variable(second, var);
                    return new Symbol(second, var);
                }
                else if(type == DOUBLE)
                {
                    double var;
                    object->get_member_variable(second, var);
                    return new Symbol(second, var);
                }
                else if(type == STRING)
                {
                    string var;
                    object->get_member_variable(second, var);
                    return new Symbol(second, var);
                }
            } 
        }
        return temp;
    }
    return new Symbol("dummy", 0);
}
