#include "if_stmt.h"

If_stmt::If_stmt(Expr* newExpr, Statement_block* thenBlock, Statement_block* elseBlock)
{
	expr = newExpr;
	then_block = thenBlock;
	else_block = elseBlock;
}
void If_stmt::execute()
{

}
