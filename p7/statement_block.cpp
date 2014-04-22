#include "statement_block.h"

using namespace std;

Statement_block::Statement_block(){}

Statement_block::Statement_block(int block_line)
{
  m_line = block_line;
}

void Statement_block::addStatement(Statement* statement)
{
  statements.push_back(statement);
}

Statement* Statement_block::removeStatement()
{
  Statement* temp = statements.back();
  statements.pop_back();
  return temp;
}

bool Statement_block::empty()
{
  if(statements.empty())
    return true;
  return false;
}

void Statement_block::execute()
{
  for(unsigned int i = 0; i < statements.size(); i++)
  {
    statements[i]->execute();
  }

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
