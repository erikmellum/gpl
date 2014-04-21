/** 
Author: Erik Mellum
Created: 4/16/14
Class: Print_stmt ipmlements a print statement for gpl using cout
**/

#include "statement.h"
#include "expr.h"
#include <iostream>
#pragma once

using namespace std;

class Print_stmt : public Statement
{
	public:
		Print_stmt(Expr* expr, int newLineNo);
		void execute();
		void setOutput(Expr* newExpr);
		void setLineNo(int newLineNo);
	private:
		Expr* output;
		int line_no;
};