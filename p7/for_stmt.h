#include "statement.h"
#pragma once

using namespace std;

class For_stmt
{
	public:
		void execute();

	private:
		Statement_block* initializer;
		Statement_block* incrementor;
		Statement_block* body;
		Expr* expr;
};