#include "if_stmt.h"

If_stmt::If_stmt(Expr* newExpr, Statement_block* thenBlock)
{
	expr = newExpr;
	then_block = thenBlock;
	else_block = NULL;
}
If_stmt::If_stmt(Expr* newExpr, Statement_block* thenBlock, Statement_block* elseBlock)
{
	expr = newExpr;
	then_block = thenBlock;
	else_block = elseBlock;
}
void If_stmt::execute()
{
	if(!else_block)
	{
		if(expr->eval_int())
			then_block->execute();
	}
	else
		if(expr->eval_int())
			then_block->execute();
		else
			else_block->execute();
}
