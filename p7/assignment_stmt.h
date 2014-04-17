/** 
Author: Erik Mellum
Created: 4/16/14
Class: Assignment_stmt implements an assign statement for gpl
**/

#include "statement.h"
#include "gpl_type.h"
#include "expr.h"
#pragma once

using namespace std;

class Assignment_stmt
{
	public:
		Assignment_stmt(Expr* newLhs, Expr* newRhs, Operator_type newType);
		void execute();
		
	private:
		Expr* lhs;
		Expr* rhs;
		Operator_type type;
};