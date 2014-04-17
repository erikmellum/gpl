#include "statement.h"
#include "operator_type.h"
#include "gpl_type.h"
#pragma once

using namespace std;

class Assignment_stmt
{
	public:
		void execute();
		
	private:
		Expr* lhs;
		Expr* rhs;
		Operator_type type;
};