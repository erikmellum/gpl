#include "for_stmt.h"

For_stmt::For_stmt(Statement_block* newInitializer, Expr* argument, Statement_block* newIncrementor, Statement_block* newBody)
{
	initializer = newInitializer;
	incrementor = newIncrementor;
	body = newBody;
	expr = argument;
}

void For_stmt::execute()
{
	/**
	for(initializer->execute(); expr->eval_int() == true; incrementor->execute())
	{
		//body->execute();
	}**/
}
