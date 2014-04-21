/** 
Author: Erik Mellum
Created: 4/16/14
Class: Exit_stmt
**/

#include "statement.h"
#include "expr.h"
#pragma once

using namespace std;

class Exit_stmt : public Statement
{
	public:
		Exit_stmt(Expr* newExpr, int newLineNo);
		void execute();

	private:
		Expr* expr;
		int lineNo;
};