/*
  Normally when using flex and bison, you include the file y.tab.h

  For gpl you will include parser.h instead of y.tab.h

  parser.h will include y.tab.h

  The reason:
   Since the union created by bison contains the following types

    std::string

   and in furture assignments it will contain the types

   Symbol *
   Expression_tree *
   Statement_block *

   The header file for each of these types must be included before
   y.tab.h is included

*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
using namespace std;

// In future gpl assignments you will include .h files here
// for example, when you need to put an Expr * into the union you will
// include expr.h

// The type of values in the array
enum Variable_type {INT, STRING, DOUBLE};

#include "y.tab.h"

#endif // #ifndef PARSER_H
