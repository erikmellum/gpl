#include "variable.h"

Variable::Variable(string value)
{
    name = value;
    param = "";
    expression = NULL;
    type = STANDARD;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    expression = expr;
    param = "";
    type = STANDARD;
}
Variable::Variable(string value, string parameter)
{
    name = value;
    param = parameter;
    expression = NULL;
    type = OBJECT_PARAM;
}
Variable::Variable(string value, Expr* expr, string parameter)
{
    name = value;
    param = parameter;
    expression = expr;
    type = OBJECT_PARAM;
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
Var_type Variable::getType()
{
    return type;
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
void Variable::setIntParam(Symbol* sym, int newValue)
{
    Game_object* object = sym->getGameObject();
    Status status;
    status = object->set_member_variable(param, newValue);
    assert(status == OK);
}
void Variable::setDoubleParam(Symbol* sym, double newValue)
{
    Game_object* object = sym->getGameObject();
    Status status;
    status = object->set_member_variable(param, newValue);
    assert(status == OK);
}
void Variable::setStringParam(Symbol* sym, string newValue)
{
    Game_object* object = sym->getGameObject();
    Status status;
    status = object->set_member_variable(param, newValue);
    assert(status == OK);
}
string Variable::getParam()
{
    return param;
}
void Variable::setParam(string newParam)
{
    param = newParam;
}
Gpl_type Variable::getParamType(Symbol* sym)
{
    Game_object* object = sym->getGameObject();
    Gpl_type type;
    Status status;
    status = object->get_member_variable_type(param, type);
    assert(status == OK);
    return type;
}