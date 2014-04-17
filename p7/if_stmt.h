#include "statement.h"
#include "statement_block.h"
#include "expr.h"
#pragma once

using namespace std;

class If_stmt
{
	public:
		void execute();
		
	private:
		Expr* expr;
		Statement_block then;
		Statement_block else;

};