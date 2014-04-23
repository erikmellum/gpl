#include "exit_stmt.h"

Exit_stmt::Exit_stmt(Expr* newExpr, int newLineNo)
{
	expr = newExpr;
	lineNo = newLineNo;
}
void Exit_stmt::execute()
{
	cout << "gpl[" << lineNo << "]: exit(" << expr->eval_int() << ")"; 
	exit(expr->eval_int());

}
