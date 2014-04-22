#include "assignment_stmt.h"

Assignment_stmt::Assignment_stmt(Variable* newLhs, Expr* newRhs, Assign_kind newType)
{
	lhs = newLhs;
	rhs = newRhs;
	type = newType;
}
void Assignment_stmt::execute()
{
	switch(type)
	{
		case EQUALS:		
			if(lhs->eval()->getType() == INT)
			{
				lhs->eval()->setInt(rhs->eval_int());
			}
			else if(lhs->eval()->getType() == DOUBLE)
			{
				lhs->eval()->setDouble(rhs->eval_double());
			}
			else if(lhs->eval()->getType() == STRING)
			{
				lhs->eval()->setString(rhs->eval_string());
			}
			else if(lhs->eval()->getType() == GAME_OBJECT)
			{	
				lhs->eval()->setGameObject(rhs->eval_game_object());
			}
			else if(lhs->eval()->getType() == ANIMATION_BLOCK)
			{
				lhs->eval()->setAnimationBlock(rhs->eval_animation_block());
			}
		break;
		case PLUS_EQUALS:
			if(lhs->eval()->getType() == INT)
			{
				lhs->eval()->setInt(rhs->eval_int() + lhs->eval()->getInt());
			}
			else if(lhs->eval()->getType() == DOUBLE)
			{
				if(rhs->getGplType() == DOUBLE || rhs->getGplType() == INT)
					lhs->eval()->setDouble(rhs->eval_double() + lhs->eval()->getDouble());
			}
		break;
		case MINUS_EQUALS:
			if(lhs->eval()->getType() == INT)
			{
				lhs->eval()->setInt(lhs->eval()->getInt() - rhs->eval_int());
			}
			else if(lhs->eval()->getType() == DOUBLE)
			{
				if(rhs->getGplType() == DOUBLE || rhs->getGplType() == INT)
					lhs->eval()->setDouble(lhs->eval()->getDouble() - rhs->eval_double());
			}
		break;
	}
}
