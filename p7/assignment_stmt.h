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

enum Assign_kind{
	EQUALS,
	PLUS_EQUALS,
	MINUS_EQUALS
};

class Assignment_stmt : public Statement
{
	public:
		Assignment_stmt(Expr* newLhs, Expr* newRhs, Assign_kind newType);
		void execute();
		
	private:
		Expr* lhs;
		Expr* rhs;
		Assign_kind type;
};