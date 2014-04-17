#include "statement.h"
#include "expr.h"
#include <iostream>
#pragma once

using namespace std;

class Print_stmt
{
	public:
		void execute();
		void setOutput(Expr* newExpr);
	private:
		Expr* output;
};