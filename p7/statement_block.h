/***
  This file is a placeholder for the Statement_block class you will write in 
  the next assignment p7.

  You may use it w/o modification in p6.

  You may use it as a starting point for your Statement_block class for p7.

  I have put in just enough for it to work in p6.

***/


#ifndef STATEMENT_BLOCK_H
#define STATEMENT_BLOCK_H

#include <iostream>

#include "indent.h"

class Game_object;

class Statement_block
{
  public:
    Statement_block(int block_line);

    // Implement this function
    bool empty();

    // This is called when a statement block is executed
    // Implement it for p7
    void execute();
  
    std::ostream &print(std::ostream &os) const;

  protected:

    // line number statement block starts on (only used for debugging)
    int m_line; 
};


std::ostream & operator<<(std::ostream &os, const Statement_block &statement_block);

std::ostream & operator<<(std::ostream &os, const Statement_block *statement_block);

#endif // #ifndef STATEMENT_BLOCK_H
