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
#include <vector>
#include <sstream>
#include "expr.h"
using namespace std;

Symbol_table *symbol_table = Symbol_table::instance();
// use this global variable to store all the values in the array
// add vectors here for additional types
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
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)s
 double         union_double;
 Gpl_type       union_gpl_type;
 Operator_type  union_operator_type;
 Expr           *union_expression_kind;
 Variable       *union_variable_type;
}

%token T_INT
%token T_DOUBLE
%token T_STRING
%token T_TRIANGLE
%token T_PIXMAP
%token T_CIRCLE
%token T_RECTANGLE
%token T_TEXTBOX
%token T_FORWARD
%token T_INITIALIZATION

%token T_TRUE
%token T_FALSE

%token T_ON
%token T_SPACE
%token T_LEFTARROW
%token T_RIGHTARROW
%token T_UPARROW
%token T_DOWNARROW
%token T_LEFTMOUSE_DOWN
%token T_MIDDLEMOUSE_DOWN
%token T_RIGHTMOUSE_DOWN
%token T_LEFTMOUSE_UP
%token T_MIDDLEMOUSE_UP
%token T_RIGHTMOUSE_UP
%token T_MOUSE_MOVE
%token T_MOUSE_DRAG

%token T_F1
%token T_AKEY
%token T_SKEY
%token T_DKEY
%token T_FKEY
%token T_HKEY
%token T_JKEY
%token T_KKEY
%token T_LKEY
%token T_WKEY

%token T_TOUCHES
%token T_NEAR

%token T_ANIMATION

%token T_IF
%token T_FOR
%token T_ELSE
%token T_EXIT

%token T_LPAREN
%token T_RPAREN
%token T_LBRACE
%token T_RBRACE
%token T_LBRACKET
%token T_RBRACKET
%token T_SEMIC
%token T_COMMA
%token T_PERIOD

%token T_ASSIGN
%token T_PLUS_ASSIGN
%token T_MINUS_ASSIGN
%token T_PLUS_PLUS
%token T_MINUS_MINUS

%token T_ASTERISK
%token T_DIVIDE
%token T_MOD
%token T_PLUS
%token T_MINUS
%token T_SIN
%token T_COS
%token T_TAN
%token T_ASIN
%token T_ACOS
%token T_ATAN
%token T_SQRT
%token T_FLOOR
%token T_ABS
%token T_RANDOM
%token T_LESS
%token T_GREATER
%token T_LESS_EQUAL
%token T_GREATER_EQUAL
%token T_EQUAL
%token T_NOT_EQUAL
%token T_ERROR
%token T_AND
%token T_OR
%token T_NOT
%token UNARY_OPS
// the following need a type
// %token <type goes here> TOKEN
%token <union_string> T_ID
%token <union_int> T_INT_CONSTANT
%token <union_double> T_DOUBLE_CONSTANT
%token <union_string> T_STRING_CONSTANT
%token <union_int> T_PRINT
%type <union_gpl_type> simple_type
%type <union_variable_type> variable
%type <union_expression_kind> expression
%type <union_expression_kind> primary_expression
%type <union_expression_kind> optional_initializer
%type <union_operator_type> math_operator
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



%% // indicates the start of the rules
%left T_OR;
%left T_AND;
%left T_NOT_EQUAL T_EQUAL;
%left T_GREATER T_GREATER_EQUAL T_LESS T_LESS_EQUAL;
%left T_PLUS T_MINUS;
%left T_ASTERISK T_DIVIDE T_MOD;
%right T_NOT;
%nonassoc UNARY_OPS;
%nonassoc IF_NO_ELSE;
%nonassoc T_ELSE;
//---------------------------------------------------------------------
program:
    declaration_list block_list
    ;

//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
    variable_declaration T_SEMIC
    | object_declaration T_SEMIC
    | forward_declaration T_SEMIC
    ;

//---------------------------------------------------------------------
variable_declaration:
    simple_type  T_ID  optional_initializer
    {
        string id = *$2;
        if(!symbol_table->lookup(id) && !symbol_table->lookup(id+"[0]"))
        {          
            if($1 == INT)
            {
                int initial_value = 0;
                
                if($3 != NULL)
                {
                    if($3->getKind() == INT_CONST)
                    {   
                        symbol_table->insert(new Symbol(id,$3->eval_int()));
                    }
                    else
                    {

                        initial_value = $3->eval_int();
                    }
                    
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
            else if($1 == DOUBLE)
            {
                double initial_value = 0;
                
                if($3 != NULL)
                {
                    if($3->getKind() == DOUBLE_CONST)
                    {   
                        symbol_table->insert(new Symbol(id,$3->eval_double()));
                    }
                    else
                    {

                        initial_value = $3->eval_double();
                    }
                    
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
            else if($1 == STRING)
            {
                string initial_value = "";
                if($3 != NULL)
                {

                    initial_value = $3->eval_string();
                    
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
        }
        else
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, id);
        }
    }
    | simple_type T_ID T_LBRACKET T_INT_CONSTANT T_RBRACKET
    {        
        string identifier;
        string id = *$2;
        if(!symbol_table->lookup(id) && !symbol_table->lookup(id+"[0]"))
        {
            if($1 == INT)
            {
                for(int i = 0; i < $4; i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),1));
                }
                
            }
            else if($1 == DOUBLE)
            {
                for(int i = 0; i < $4; i++)
                {
                    stringstream ss;
                    ss  << id  << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),1.1));
                }
            }
            else if($1 == STRING)
            {
                for(int i = 0; i < $4; i++)
                {
                    stringstream ss;
                    ss  << id  << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),"a"));
                }
            }
        }
        else
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, id);
        }
    }
    ;

//---------------------------------------------------------------------
simple_type:
    T_INT
    {
        $$ = INT;
    }
    | T_DOUBLE
    {
        $$ = DOUBLE;
    }
    | T_STRING
    {
        $$ = STRING;
    }
    ;

//---------------------------------------------------------------------
optional_initializer:
    T_ASSIGN expression
    {
      $$ = $2;
    }
    | empty
    {
      $$ = NULL;
    }
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID T_LPAREN parameter_list_or_empty T_RPAREN
    
    | object_type T_ID T_LBRACKET expression T_RBRACKET
    
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE
    | T_PIXMAP
    | T_CIRCLE
    | T_RECTANGLE
    | T_TEXTBOX
    ;

//---------------------------------------------------------------------
parameter_list_or_empty :
    parameter_list
    | empty
    ;

//---------------------------------------------------------------------
parameter_list :
    parameter_list T_COMMA parameter
    | parameter
    ;

//---------------------------------------------------------------------
parameter:
    T_ID T_ASSIGN expression
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
    ;

//---------------------------------------------------------------------
block_list:
    block_list block
    | empty
    ;

//---------------------------------------------------------------------
block:
    initialization_block
    | animation_block
    | on_block
    ;

//---------------------------------------------------------------------
initialization_block:
    T_INITIALIZATION statement_block
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE { } statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    T_TRIANGLE T_ID
    | T_PIXMAP T_ID
    | T_CIRCLE T_ID
    | T_RECTANGLE T_ID
    | T_TEXTBOX T_ID
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    | T_UPARROW
    | T_DOWNARROW
    | T_LEFTARROW
    | T_RIGHTARROW
    | T_LEFTMOUSE_DOWN
    | T_MIDDLEMOUSE_DOWN
    | T_RIGHTMOUSE_DOWN
    | T_LEFTMOUSE_UP
    | T_MIDDLEMOUSE_UP
    | T_RIGHTMOUSE_UP
    | T_MOUSE_MOVE
    | T_MOUSE_DRAG
    | T_AKEY 
    | T_SKEY 
    | T_DKEY 
    | T_FKEY 
    | T_HKEY 
    | T_JKEY 
    | T_KKEY 
    | T_LKEY 
    | T_WKEY 
    | T_F1
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    | statement_block
    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
statement_block_creator:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
statement_list:
    statement_list statement
    | empty
    ;

//---------------------------------------------------------------------
statement:
    if_statement
    | for_statement
    | assign_statement T_SEMIC
    | print_statement T_SEMIC
    | exit_statement T_SEMIC
    ;

//---------------------------------------------------------------------
if_statement:
    T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
assign_statement:
    variable T_ASSIGN expression
    | variable T_PLUS_ASSIGN expression
    | variable T_MINUS_ASSIGN expression
    ;

//---------------------------------------------------------------------
variable:
    T_ID
    {
        $$ = new Variable(*$1);
    }
    | T_ID T_LBRACKET expression T_RBRACKET
    {
        $$ = new Variable(*$1, $3);
    }
    | T_ID T_PERIOD T_ID
    {
        $$ = NULL;
    }
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
    {
        $$= NULL;
    }
    ;

//---------------------------------------------------------------------
expression:
    primary_expression
    | expression T_OR expression
    {
        /**
        if($1 == ??)
        else if($1 == ?)
        else if ($1 == ?)
        $$ = new Expression(,$3yy
        **/
    }
    | expression T_AND expression
    {
    }
    | expression T_LESS_EQUAL expression
    {
    }
    | expression T_GREATER_EQUAL  expression
    {
    }
    | expression T_LESS expression 
    {
    }
    | expression T_GREATER  expression
    {
    }
    | expression T_EQUAL expression
    {
    }
    | expression T_NOT_EQUAL expression
    {
    }
    | expression T_PLUS expression 
    {
        $$ = new Expr(PLUS,$1,$3);
    }
    | expression T_MINUS expression
    {
    }
    | expression T_ASTERISK expression
    {
        if($1->getKind() == STRING_CONST || $3->getKind() == STRING_CONST)
        {
            //$$ = new Expression(0);
        }
        else
        {
            $$ = new Expr(MULTIPLY,$1,$3);
        }
        
    }
    | expression T_DIVIDE expression
    {
    }
    | expression T_MOD expression
    {
    }
    | T_MINUS  expression %prec UNARY_OPS
    {
    }
    | T_NOT  expression %prec UNARY_OPS
    {
    }
    | math_operator T_LPAREN expression T_RPAREN
    {
        $$ = new Expr($1,$3);
    }
    | variable geometric_operator variable
    {
    }
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN
    {
        $$ = $2;
    }
    | variable
    {        
        $$ = new Expr($1);   
    }
    | T_INT_CONSTANT
    {
        $$ = new Expr($1);
    }
    | T_TRUE
    {
        $$ = new Expr(1);
    }  
    | T_FALSE
    {
        $$ = new Expr(0);
    }
    | T_DOUBLE_CONSTANT
    {
        $$ = new Expr($1);
    }
    | T_STRING_CONSTANT
    {
        $$ = new Expr(*$1);
    }
    ;

//---------------------------------------------------------------------
geometric_operator:
    T_TOUCHES
    | T_NEAR
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN
    {
        $$ = SIN;
    }
    | T_COS
    {
        $$ = COS;
    }
    | T_TAN
    {
        $$ = TAN;
    }
    | T_ASIN
    {
        $$ = ASIN;
    }
    | T_ACOS
    {
        $$ = ACOS;
    }
    | T_ATAN
    {
        $$ = ATAN;
    }
    | T_SQRT
    {
        $$ = SQRT;
    }
    | T_ABS
    {
        $$ = ABS;
    }
    | T_FLOOR
    {
        $$ = FLOOR;
    }
    | T_RANDOM
    {
        $$ = RANDOM;
    }
    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;


