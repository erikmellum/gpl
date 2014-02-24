/*
  This file contains the input to the bison compiler generator.
  bison will use this file to generate a C/C++ parser.

  The default output file for bison is: y.tab.c

    $ bison array.y    will produce the file y.tab.c

  This grammar describes a language that looks like an array
  declaration

    int foo[] = {1, 2, 3, 4};
    int bar[] = {17, 42};
    int abc[] = {};

  This example DOES NOT demonstrate how a real language would
  initialize arrays.  It is a contrived and overly simplified 
  example to demonstrate the bison/flex syntax.
  
*/

%{  // bison syntax to indicate the start of the header
    // the header is copied directly into y.tab.c

extern int yylex();         // this lexer function returns next token
extern int yyerror(char *); // used to print errors
extern int line_count;      // the current line in the input; from array.l

#include "error.h"      // class for printing errors (used by gpl)
#include "gpl_assert.h" // function version of standard assert.h
#include "parser.h"
#include <iostream>
#include <string>
#include <vector>

// use this global variable to store all the values in the array
// add vectors here for additional types
vector<int> *int_vector;
vector<double> *double_vector = new vector<double>;
vector<string> *string_vector = new vector<string>;
// bison syntax to indicate the end of the header
%} 

// The union is used to declare the variable yylval which is used to
// pass data between the flex generated lexer and the bison generated parser, 
// and to pass values up/down the parse tree.
// 
// A union is kind of like a structure or class, but you can only use one 
// field at a time.  Each line describes one item in the union.  The left hand
// side is the type, the right hand side it out name for the type (the "union_"
// is my convention to indicate that this is a member of the union).
// 
// Unions do not have any error checking.  For example, if you put an int in
// the following union  (my_union.union_int = 42)  and then attempt to use it
// as a string (cout << my_union.union_string) you will get garbage.

// The "%union" is bison syntax
// The "union_" is my convention to indicate a member of the union 
//     (it can be hard to tell what is a union field and what is not)

%union {
 int            union_int;
 string         *union_string;  // MUST be a pointer to a string (this sucks!)s
 double         union_double;
 Variable_type  union_variable_type;
}

// each token in the language is defined here
%token T_COMMA
%token T_ASSIGN
%token T_LBRACE
%token T_RBRACE
%token T_INT
%token T_SEMIC

// if a token has a type associated with it, put that type (as named in the
// union) inside of <> after the %token

%token <union_int> T_INT_CONSTANT // this token has a int value associated w/it
%token <union_string> T_ID // this token has a string value associated w/it
%token <union_string> T_ERROR // this token has a string value associated w/it
%token <union_double> T_DOUBLE_CONSTANT

// Grammar symbols that have values associated with them need to be
// declared here.  The above union is used for the "ruturning" the value.
// 
// NOTE: Values are not really returned as in function calls, but values
// associated with symbols sort of look like functions and the values associated
// with a bison symbol look like return values
//
// Because of the following statement, rules that have the symbol "values" on the 
// right-hand-side can use $n to get the "value" associated with it:
// 
//    declaration: T_ID T_ASSIGN T_LBRACE values T_RBRACE T_SEMIC
// 
// In this example, $6 is the Variable_type associated with the symbol "values" (it is the
// sixth symbol right of the ":").

%type <union_variable_type> values


%% // indicates the start of the rules

//---------------------------------------------------------------------
program:
  declaration_list
  {
    // this code is executed after entire input has been parsed

  }
  ;
//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
  T_ID T_ASSIGN T_LBRACE values T_RBRACE T_SEMIC
  {
    string id = *$1; // dereference the string in $1 and copy to local variable id

    // We are now done with the memory allocated in array.l for the T_ID string.
    // In the gpl assignment you probably won't want to delete it here.
    delete $1;

    cout << id << " = {";

    if ($4 == INT)
    {
      for (vector<int>::iterator iter = int_vector->begin(); iter != int_vector->end(); iter++)
      {
        // if this is not the first number, print a ","
        if (iter != int_vector->begin())
          cout << ", ";
        cout << *iter;
      }
    }
    delete int_vector;
    int_vector = 0;
    if ($4 == DOUBLE)
    {
      for (vector<double>::iterator iter = double_vector->begin(); iter != double_vector->end(); iter++)
      {
        // if this is not the first number, print a ","
        if (iter != double_vector->begin())
          cout << ", ";
        cout << *iter;
      }
    }
    delete double_vector;
    double_vector = 0;
     double_vector = new vector<double>;
    if ($4 == STRING)
    {
      for (vector<string>::iterator iter = string_vector->begin(); iter != string_vector->end(); iter++)
      {
        // if this is not the first number, print a ","
        if (iter != string_vector->begin())
          cout << ", ";
        cout << *iter;
      }
    }
    delete string_vector;
    string_vector = 0;
    string_vector = new vector<string>; 
    // put code here to print out the DOUBLE and STRING vectors

    cout << "};\n";

    // we are done using the global vector of integers
    
  }
  |
  empty
  ;


//---------------------------------------------------------------------
values:
  {
    // create a global vector of integers BEFORE int_values rule is matched
    
    int_vector = new vector<int>;  
   
    
  }
  int_values
  {
    $$ = INT;
  }
  | 
  string_values  // complete this
  {
    $$ = STRING;
  }
  |
  double_values  // complete this
  {
    $$ = DOUBLE;
  }
  ;

//---------------------------------------------------------------------
int_values:
  int_values T_COMMA T_INT_CONSTANT
  {
    // put the given integer into the global vector created in the
    // start of the int_values rule
    // $3 is the union & field associated with T_INT_CONSTANT
    int_vector->push_back($3);
  }
  |
  T_INT_CONSTANT
  {
    // same as above
    // code duplication is not idea, but this is easier to understand
    int_vector->push_back($1);
  }
  ;

//---------------------------------------------------------------------
string_values:
  string_values T_COMMA T_ID
  {
    // put the given integer into the global vector created in the
    // start of the int_values rule
    // $3 is the union & field associated with T_INT_CONSTANT
    string_vector->push_back(*$3);
  }
  |
  T_ID
  {
    // same as above
    // code duplication is not idea, but this is easier to understand
    string_vector->push_back(*$1);
  }
  ;

//---------------------------------------------------------------------
double_values:
  double_values T_COMMA T_DOUBLE_CONSTANT
  {
    // put the given integer into the global vector created in the
    // start of the int_values rule
    // $3 is the union & field associated with T_INT_CONSTANT
    double_vector->push_back($3);
  }
  |
  T_DOUBLE_CONSTANT
  {
    // same as above
    // code duplication is not idea, but this is easier to understand
    double_vector->push_back($1);
  }
  ;

//---------------------------------------------------------------------
empty:
  ;


