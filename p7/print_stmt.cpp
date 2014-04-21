#include "print_stmt.h"

Print_stmt::Print_stmt(Expr* expr, int newLineNo)
{
	output = expr;
	line_no = newLineNo;
}
void Print_stmt::execute()
{
	cout << output->eval_string();
}
