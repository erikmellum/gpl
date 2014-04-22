#include "assignment_stmt.h"

Assignment_stmt::Assignment_stmt(Expr* newLhs, Expr* newRhs, Assign_kind newType)
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
			/**
			if(lhs->getGplType() == INT)
			{
				lhs->eval_int() = rhs->eval_int();
			}
			else if(lhs->getGplType() == DOUBLE)
			{
				lhs->eval_double() = rhs->eval_double();
			}
			else if(lhs->getGplType() == STRING)
			{
				lhs->eval_string() = rhs->eval_string();
			}
			else if(lhs->getGplType() == GAME_OBJECT)
			{	
				lhs->eval_game_object() = rhs->eval_game_object();
			}
			else if(lhs->getGplType() == ANIMATION_BLOCK)
			{
				lhs->eval_animation_block() = rhs->eval_animation_block();

			}
			**/
		break;
		case PLUS_EQUALS:
			/**
			if(lhs->getGplType() == INT)
			{
				lhs->eval_int() += rhs->eval_int();
			}
			else if(lhs->getGplType() == DOUBLE)
			{
				lhs->eval_double() += rhs->eval_double();
			}
			**/
		break;
		case MINUS_EQUALS:
			/**
			if(lhs->getGplType() == INT)
			{
				lhs->eval_int() -= rhs->eval_int();
			}
			else if(lhs->getGplType() == DOUBLE)
			{
				lhs->eval_double() -= rhs->eval_double();
			}
			**/
		break;
	}
}
