#include "variable.h"
#pragma once

using namespace std;

Variable::Variable(string value)
{
    name = value;
}
Variable::Variable(string value, Expr* expr)
{
    name = value;
    left = expr;
}