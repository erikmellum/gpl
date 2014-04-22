/** 
Author: Erik Mellum
Created: 4/16/14
Class: If_stmt implements an if statement for gpl
**/

#include "statement.h"
#include "statement_block.h"
#include "expr.h"
#pragma once

using namespace std;

class If_stmt : public Statement
{
	public:
		If_stmt(Expr* newExpr, Statement_block* thenBlock);
		If_stmt(Expr* newExpr, Statement_block* thenBlock, Statement_block* elseBlock);
		void execute();
		
	private:
		Expr* expr;
		Statement_block* then_block;
		Statement_block* else_block;

};