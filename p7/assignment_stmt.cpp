#include "assignment_stmt.h"

Assignment_stmt::Assignment_stmt(Expr* newLhs, Expr* newRhs, Operator_type newType)
{
	lhs = newLhs;
	rhs = newRhs;
	type = newType;
}
void Assignment_stmt::execute()
{

}
