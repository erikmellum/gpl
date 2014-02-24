#include "Expr.h"

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
    
}
double Expr::eval_double()
{
    
string Expr::eval_string()
{
    
}
