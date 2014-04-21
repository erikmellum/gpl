#include "assignment_stmt.h"

Assignment_stmt::Assignment_stmt(Variable* newLhs, Expr* newRhs, Assign_kind newType)
{
	lhs = newLhs;
	rhs = newRhs;
	type = newType;
}
void Assignment_stmt::execute()
{

}
