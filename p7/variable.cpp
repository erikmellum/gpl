#include "variable.h"

Variable::Variable(string value)
{
    name = value;
    param = "";
    expression = NULL;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    expression = expr;
    param = "";
}
Variable::Variable(string value, string parameter)
{
    name = value;
    param = parameter;
    expression = NULL;
}
Variable::Variable(string value, Expr* expr, string parameter)
{
    name = value;
    param = parameter;
    expression = expr;
}
Symbol* Variable::eval()
{
    Symbol_table *symbol_table = Symbol_table::instance();
    string rname = name;
    if(expression)
    {   
    	int i = expression->eval_int();
    	stringstream ss;
    	ss << name << "[" << i << "]";
    	rname = ss.str();
    }
    if(symbol_table->lookup(rname))
    {
        return symbol_table->retrieve(rname);
    }
    return new Symbol("dummy", 0);
}
int Variable::getIntValue(Symbol* sym)
{
    Game_object* object = sym->getGameObject();
    Gpl_type type;
    Status status;
    status = object->get_member_variable_type(param, type);
    if(type == INT)
    {
        int var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        return var;
    }
    //else 
        //error
    return 0;

}
double Variable::getDoubleValue(Symbol* sym)
{
    Game_object* object = sym->getGameObject();
    Gpl_type type;
    Status status;
    status = object->get_member_variable_type(param, type);
    assert(status == OK);
    if(type == DOUBLE)
    {
        double var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        return var;
    }
    else if(type == INT)
    {
        int var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        return (double) var;
    }
    //else 
        //error
    return 0;
}
string Variable::getStringValue(Symbol* sym)
{
    Game_object* object = sym->getGameObject();
    Gpl_type type;
    Status status;
    status = object->get_member_variable_type(param, type);
    assert(status == OK);
    if(type == STRING)
    {
        string var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        return var;
    }
    else if(type == DOUBLE)
    {
        stringstream ss;
        double var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        ss << var;
        return ss.str();
    }
    else if(type == INT)
    {
        stringstream ss;
        int var;
        status = object->get_member_variable(param, var);
        assert(status == OK);
        ss << var;
        return ss.str();
    }
    //else 
        //error
    return 0;
}