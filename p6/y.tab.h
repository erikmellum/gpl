/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_INT = 258,
     T_DOUBLE = 259,
     T_STRING = 260,
     T_TRIANGLE = 261,
     T_PIXMAP = 262,
     T_CIRCLE = 263,
     T_RECTANGLE = 264,
     T_TEXTBOX = 265,
     T_FORWARD = 266,
     T_INITIALIZATION = 267,
     T_TRUE = 268,
     T_FALSE = 269,
     T_ON = 270,
     T_SPACE = 271,
     T_LEFTARROW = 272,
     T_RIGHTARROW = 273,
     T_UPARROW = 274,
     T_DOWNARROW = 275,
     T_LEFTMOUSE_DOWN = 276,
     T_MIDDLEMOUSE_DOWN = 277,
     T_RIGHTMOUSE_DOWN = 278,
     T_LEFTMOUSE_UP = 279,
     T_MIDDLEMOUSE_UP = 280,
     T_RIGHTMOUSE_UP = 281,
     T_MOUSE_MOVE = 282,
     T_MOUSE_DRAG = 283,
     T_F1 = 284,
     T_AKEY = 285,
     T_SKEY = 286,
     T_DKEY = 287,
     T_FKEY = 288,
     T_HKEY = 289,
     T_JKEY = 290,
     T_KKEY = 291,
     T_LKEY = 292,
     T_WKEY = 293,
     T_TOUCHES = 294,
     T_NEAR = 295,
     T_ANIMATION = 296,
     T_IF = 297,
     T_FOR = 298,
     T_ELSE = 299,
     T_EXIT = 300,
     T_LPAREN = 301,
     T_RPAREN = 302,
     T_LBRACE = 303,
     T_RBRACE = 304,
     T_LBRACKET = 305,
     T_RBRACKET = 306,
     T_SEMIC = 307,
     T_COMMA = 308,
     T_PERIOD = 309,
     T_ASSIGN = 310,
     T_PLUS_ASSIGN = 311,
     T_MINUS_ASSIGN = 312,
     T_PLUS_PLUS = 313,
     T_MINUS_MINUS = 314,
     T_ASTERISK = 315,
     T_DIVIDE = 316,
     T_MOD = 317,
     T_PLUS = 318,
     T_MINUS = 319,
     T_SIN = 320,
     T_COS = 321,
     T_TAN = 322,
     T_ASIN = 323,
     T_ACOS = 324,
     T_ATAN = 325,
     T_SQRT = 326,
     T_FLOOR = 327,
     T_ABS = 328,
     T_RANDOM = 329,
     T_LESS = 330,
     T_GREATER = 331,
     T_LESS_EQUAL = 332,
     T_GREATER_EQUAL = 333,
     T_EQUAL = 334,
     T_NOT_EQUAL = 335,
     T_ERROR = 336,
     T_AND = 337,
     T_OR = 338,
     T_NOT = 339,
     UNARY_OPS = 340,
     T_ID = 341,
     T_INT_CONSTANT = 342,
     T_DOUBLE_CONSTANT = 343,
     T_STRING_CONSTANT = 344,
     T_PRINT = 345,
     IF_NO_ELSE = 346
   };
#endif
/* Tokens.  */
#define T_INT 258
#define T_DOUBLE 259
#define T_STRING 260
#define T_TRIANGLE 261
#define T_PIXMAP 262
#define T_CIRCLE 263
#define T_RECTANGLE 264
#define T_TEXTBOX 265
#define T_FORWARD 266
#define T_INITIALIZATION 267
#define T_TRUE 268
#define T_FALSE 269
#define T_ON 270
#define T_SPACE 271
#define T_LEFTARROW 272
#define T_RIGHTARROW 273
#define T_UPARROW 274
#define T_DOWNARROW 275
#define T_LEFTMOUSE_DOWN 276
#define T_MIDDLEMOUSE_DOWN 277
#define T_RIGHTMOUSE_DOWN 278
#define T_LEFTMOUSE_UP 279
#define T_MIDDLEMOUSE_UP 280
#define T_RIGHTMOUSE_UP 281
#define T_MOUSE_MOVE 282
#define T_MOUSE_DRAG 283
#define T_F1 284
#define T_AKEY 285
#define T_SKEY 286
#define T_DKEY 287
#define T_FKEY 288
#define T_HKEY 289
#define T_JKEY 290
#define T_KKEY 291
#define T_LKEY 292
#define T_WKEY 293
#define T_TOUCHES 294
#define T_NEAR 295
#define T_ANIMATION 296
#define T_IF 297
#define T_FOR 298
#define T_ELSE 299
#define T_EXIT 300
#define T_LPAREN 301
#define T_RPAREN 302
#define T_LBRACE 303
#define T_RBRACE 304
#define T_LBRACKET 305
#define T_RBRACKET 306
#define T_SEMIC 307
#define T_COMMA 308
#define T_PERIOD 309
#define T_ASSIGN 310
#define T_PLUS_ASSIGN 311
#define T_MINUS_ASSIGN 312
#define T_PLUS_PLUS 313
#define T_MINUS_MINUS 314
#define T_ASTERISK 315
#define T_DIVIDE 316
#define T_MOD 317
#define T_PLUS 318
#define T_MINUS 319
#define T_SIN 320
#define T_COS 321
#define T_TAN 322
#define T_ASIN 323
#define T_ACOS 324
#define T_ATAN 325
#define T_SQRT 326
#define T_FLOOR 327
#define T_ABS 328
#define T_RANDOM 329
#define T_LESS 330
#define T_GREATER 331
#define T_LESS_EQUAL 332
#define T_GREATER_EQUAL 333
#define T_EQUAL 334
#define T_NOT_EQUAL 335
#define T_ERROR 336
#define T_AND 337
#define T_OR 338
#define T_NOT 339
#define UNARY_OPS 340
#define T_ID 341
#define T_INT_CONSTANT 342
#define T_DOUBLE_CONSTANT 343
#define T_STRING_CONSTANT 344
#define T_PRINT 345
#define IF_NO_ELSE 346




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 63 "gpl.y"

 int             union_int;
 std::string     *union_string;  // MUST be a pointer to a string (this sucks!)s
 double          union_double;
 Gpl_type        union_gpl_type;
 Operator_type   union_operator_type;
 Expr            *union_expression_kind;
 Variable        *union_variable_type;
 Game_object     *union_game_object;
 Animation_block *union_animation_block;
 Symbol          *union_symbol;



/* Line 2068 of yacc.c  */
#line 247 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


