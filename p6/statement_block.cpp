#include "statement_block.h"
#include "gpl_assert.h"
using namespace std;


Statement_block::Statement_block(int block_line)
{
  m_line = block_line;
}

// Return true if this statement_block has no statements, false otherwise
// Implement this function for p7 (but you won't need it until p8)
bool Statement_block::empty()
{
  // This function MUST be defined for p8
  // If you forget to define it, none of your animations will work
  // So define it when you implement p7

  // **** remove this assert when you implement empty();
  //assert(false); 

  // place holder to keep the compiler from issuing a warning
  return true;
}

// this function is called for all non-animation_block statement_blocks
// Implement it for p7
void Statement_block::execute()
{
  // This function should be defined before it is ever called
  // This assert will cause the program to abort if this function 
  // is called before it is implemented.

  // *** ==> Remove this assert when you implement this function
  assert(false);
}

ostream & Statement_block::print(ostream &os) const
{
  os << indent << "Statement_block[" << m_line;
  
  os << "]" << endl
     << indent << "{" << endl;
  indent++;
  os << indent << "statement block not implemented yet" << endl;
  indent--;
  os << indent << "}";
  return os;
}


ostream & operator<<(ostream &os, const Statement_block &statement_block)
{
  return statement_block.print(os);
}

ostream & operator<<(ostream &os, const Statement_block *statement_block)
{
  if (!statement_block)
  {
      os << indent << "NULL";
      return os;
  }

  return statement_block->print(os);
}
