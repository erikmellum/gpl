#include "expr.h"

using namespace std;
Expr::Expr(int value)
{
    type = INT;
}
Expr::Expr(double value)
{
    type = DOUBLE;
}
Expr::Expr(string value)
{
    type = STRING;
}
int Expr::eval_int()
{
    assert(m_type == INT)
    switch on type
    if the left is an int eval int
    if the  right is an int eval int
}
string Expr::eval_string()
{
    if(m_type == int)
        int type = eval int
        cast tmp to string
}









int Expr::eval_int()
{
    
}
double Expr::eval_double()
{
    
string Expr::eval_string()
{
    
}
