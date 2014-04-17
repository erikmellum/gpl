/** 
Author: Erik Mellum
Created: 4/16/14
Class: For_stmt implements a for statement
**/

#include "statement.h"
#include "statement_block.h"
#include "expr.h"
#pragma once

using namespace std;

class For_stmt
{
	public:
		For_stmt(Statement_block* newInitializer, Statement_block* newIncrementor, Statement_block* newBody, Expr* newExpr);
		void execute();

	private:
		Statement_block* initializer;
		Statement_block* incrementor;
		Statement_block* body;
		Expr* expr;
};