#include "statement.h"
#include "expr.h"
#pragma once

using namespace std;

class Exit_stmt
{
	public:
		void execute();

	private:
		Expr* expr;
};