#include "gpl_type.h"
#include "gpl_assert.h"
using namespace std;

string gpl_type_to_string(Gpl_type gpl_type)
{
  switch (gpl_type)
  {
    case INT: return "int";
    case DOUBLE: return "double";
    case STRING: return "string";
    case GAME_OBJECT: return "game_object";
    case ANIMATION_BLOCK: return "animation_block";
  }
  assert(false);

  return "error";  // this keeps compiler happy
}

ostream &operator<<(ostream &os, const Gpl_type &gpl_type)
{
  switch (gpl_type)
  {
    case INT: os << "int"; return os;
    case DOUBLE: os << "double"; return os;
    case STRING: os << "string"; return os;
    case GAME_OBJECT: os << "game_object"; return os;
    case ANIMATION_BLOCK: os << "animation_block"; return os;
    default: assert(false);
  }

  return os;
}

string status_to_string(Status status)
{
  switch(status)
  {
    case OK: return "OK";
    case MEMBER_NOT_OF_GIVEN_TYPE: return "MEMBER_NOT_OF_GIVEN_TYPE";
    case MEMBER_NOT_DECLARED: return "MEMBER_NOT_DECLARED";
    default: assert(false);
  }
  assert(false);
  return ""; // to prevent a compilation warning
}

string operator_to_string(Operator_type op)
{
  switch(op)
  {
    case PLUS: return "+";
    case MINUS: return "-";
    case DIVIDE: return "/";
    case MULTIPLY: return "*";
    case MOD: return "%";
    case UNARY_MINUS: return "-";
    case NOT: return "!";
    case AND: return "&&";
    case OR: return "||";
    case EQUAL: return "==";
    case NOT_EQUAL: return "!=";
    case LESS_THAN: return "<";
    case LESS_THAN_EQUAL: return "<=";
    case GREATER_THAN: return ">";
    case GREATER_THAN_EQUAL: return ">=";
    case NEAR: return "near";
    case TOUCHES: return "touches";
    case SIN: return "sin";
    case COS: return "cos";
    case TAN : return "tan";
    case ASIN : return "asin";
    case ACOS : return "acos";
    case ATAN : return "atan";
    case SQRT : return "sqrt";
    case ABS: return "abs";
    case FLOOR: return "floor";
    case RANDOM: return "random"; 
    default: assert(false);
  }
  assert(false);
  return ""; // to prevent a compilation warning
}
