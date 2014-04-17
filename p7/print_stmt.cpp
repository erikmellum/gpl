#include "print_stmt.h"

Print_stmt::Print_stmt(Expr* expr)
{
	output = expr;
}
void Print_stmt::execute()
{
	cout << output->eval_string();
}
