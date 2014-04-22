#include "print_stmt.h"

Print_stmt::Print_stmt(Expr* expr, int newLineNo)
{
	output = expr;
	line_no = newLineNo;
}
void Print_stmt::execute()
{
	cout << "gpl[" << line_no << "]: " << output->eval_string() << endl;
}
