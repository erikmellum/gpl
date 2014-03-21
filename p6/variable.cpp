#include "variable.h"

Variable::Variable(string value)
{
    name = value;
    expression = NULL;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    expression = expr;
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
        return symbol_table->retrieve(name);
    }
    return new Symbol("dummy", 0);
}
