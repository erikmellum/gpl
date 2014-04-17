#include "for_stmt.h"

For_stmt::For_stmt(Statement_block* newInitializer, Statement_block* newIncrementor, Statement_block* newBody, Expr* newExpr)
{
	initializer = newInitializer;
	incrementor = newIncrementor;
	body = newBody;
	expr = newExpr;
}

void For_stmt::execute()
{

}
