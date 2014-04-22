#include "exit_stmt.h"

Exit_stmt::Exit_stmt(Expr* newExpr, int newLineNo)
{
	expr = newExpr;
	lineNo = newLineNo;
}
void Exit_stmt::execute()
{
	exit(lineNo);
}
