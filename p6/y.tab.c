/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 22 "gpl.y"
  // bison syntax to indicate the start of the header
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
#include "animation_block.h"
using namespace std;
Game_object *cur_object_under_construction;
Symbol_table *symbol_table = Symbol_table::instance();
// use this global variable to store all the values in the array
// add vectors here for additional types
// bison syntax to indicate the end of the header


/* Line 268 of yacc.c  */
#line 95 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 62 "gpl.y"

 int             union_int;
 std::string     *union_string;  // MUST be a pointer to a string (this sucks!)s
 double          union_double;
 Gpl_type        union_gpl_type;
 Operator_type   union_operator_type;
 Expr            *union_expression_kind;
 Variable        *union_variable_type;
 Game_object     *union_game_object;
 Animation_block *union_animation_block;



/* Line 293 of yacc.c  */
#line 327 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 339 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    14,    17,    20,    24,
      30,    32,    34,    36,    39,    41,    42,    49,    55,    57,
      59,    61,    63,    65,    67,    69,    73,    75,    79,    86,
      89,    91,    93,    95,    97,   100,   101,   112,   115,   118,
     121,   124,   127,   130,   134,   136,   138,   140,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   172,   174,   176,   178,   180,   184,   186,
     192,   193,   194,   197,   199,   201,   203,   206,   209,   212,
     218,   226,   240,   245,   250,   254,   258,   262,   264,   269,
     273,   280,   282,   286,   290,   294,   298,   302,   306,   310,
     314,   318,   322,   326,   330,   334,   337,   340,   345,   349,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,   385,   387,   389
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    94,   106,    -1,    94,    95,    -1,   131,
      -1,    96,    52,    -1,    99,    52,    -1,   105,    52,    -1,
      97,    86,    98,    -1,    97,    86,    50,   127,    51,    -1,
       3,    -1,     4,    -1,     5,    -1,    55,   127,    -1,   131,
      -1,    -1,   101,    86,   100,    46,   102,    47,    -1,   101,
      86,    50,   127,    51,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,   103,    -1,   131,    -1,   103,
      53,   104,    -1,   104,    -1,    86,    55,   127,    -1,    11,
      41,    86,    46,   111,    47,    -1,   106,   107,    -1,   131,
      -1,   108,    -1,   109,    -1,   113,    -1,    12,   116,    -1,
      -1,    41,    86,    46,   112,    47,    48,   110,   119,    49,
     118,    -1,   101,    86,    -1,     6,    86,    -1,     7,    86,
      -1,     8,    86,    -1,     9,    86,    -1,    10,    86,    -1,
      15,   114,   116,    -1,    16,    -1,    19,    -1,    20,    -1,
      17,    -1,    18,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    29,    -1,
     117,   120,   118,    -1,   116,    -1,    48,   117,   119,    49,
     118,    -1,    -1,    -1,   119,   120,    -1,   131,    -1,   121,
      -1,   122,    -1,   125,    52,    -1,   123,    52,    -1,   124,
      52,    -1,    42,    46,   127,    47,   115,    -1,    42,    46,
     127,    47,   115,    44,   115,    -1,    43,    46,   117,   125,
     118,    52,   127,    52,   117,   125,   118,    47,   116,    -1,
      90,    46,   127,    47,    -1,    45,    46,   127,    47,    -1,
     126,    55,   127,    -1,   126,    56,   127,    -1,   126,    57,
     127,    -1,    86,    -1,    86,    50,   127,    51,    -1,    86,
      54,    86,    -1,    86,    50,   127,    51,    54,    86,    -1,
     128,    -1,   127,    83,   127,    -1,   127,    82,   127,    -1,
     127,    77,   127,    -1,   127,    78,   127,    -1,   127,    75,
     127,    -1,   127,    76,   127,    -1,   127,    79,   127,    -1,
     127,    80,   127,    -1,   127,    63,   127,    -1,   127,    64,
     127,    -1,   127,    60,   127,    -1,   127,    61,   127,    -1,
     127,    62,   127,    -1,    64,   127,    -1,    84,   127,    -1,
     130,    46,   127,    47,    -1,   126,   129,   126,    -1,    46,
     127,    47,    -1,   126,    -1,    87,    -1,    13,    -1,    14,
      -1,    88,    -1,    89,    -1,    39,    -1,    40,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    73,    -1,    72,    -1,    74,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   211,   211,   216,   217,   222,   223,   224,   229,   309,
     360,   364,   368,   376,   380,   389,   388,   415,   483,   487,
     491,   495,   499,   507,   508,   513,   514,   519,   524,   529,
     530,   535,   536,   537,   542,   547,   547,   555,   560,   561,
     562,   563,   564,   569,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   601,   602,   607,
     611,   616,   622,   623,   628,   629,   630,   631,   632,   637,
     638,   643,   648,   653,   658,   659,   660,   665,   677,   706,
     710,   718,   722,   737,   752,   756,   760,   764,   768,   772,
     776,   780,   795,   814,   831,   848,   857,   867,   929,   936,
     940,   944,   948,   952,   956,   960,   968,   969,   974,   978,
     982,   986,   990,   994,   998,  1002,  1006,  1010,  1017
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_DOUBLE", "T_STRING",
  "T_TRIANGLE", "T_PIXMAP", "T_CIRCLE", "T_RECTANGLE", "T_TEXTBOX",
  "T_FORWARD", "T_INITIALIZATION", "T_TRUE", "T_FALSE", "T_ON", "T_SPACE",
  "T_LEFTARROW", "T_RIGHTARROW", "T_UPARROW", "T_DOWNARROW",
  "T_LEFTMOUSE_DOWN", "T_MIDDLEMOUSE_DOWN", "T_RIGHTMOUSE_DOWN",
  "T_LEFTMOUSE_UP", "T_MIDDLEMOUSE_UP", "T_RIGHTMOUSE_UP", "T_MOUSE_MOVE",
  "T_MOUSE_DRAG", "T_F1", "T_AKEY", "T_SKEY", "T_DKEY", "T_FKEY", "T_HKEY",
  "T_JKEY", "T_KKEY", "T_LKEY", "T_WKEY", "T_TOUCHES", "T_NEAR",
  "T_ANIMATION", "T_IF", "T_FOR", "T_ELSE", "T_EXIT", "T_LPAREN",
  "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACKET", "T_RBRACKET",
  "T_SEMIC", "T_COMMA", "T_PERIOD", "T_ASSIGN", "T_PLUS_ASSIGN",
  "T_MINUS_ASSIGN", "T_PLUS_PLUS", "T_MINUS_MINUS", "T_ASTERISK",
  "T_DIVIDE", "T_MOD", "T_PLUS", "T_MINUS", "T_SIN", "T_COS", "T_TAN",
  "T_ASIN", "T_ACOS", "T_ATAN", "T_SQRT", "T_FLOOR", "T_ABS", "T_RANDOM",
  "T_LESS", "T_GREATER", "T_LESS_EQUAL", "T_GREATER_EQUAL", "T_EQUAL",
  "T_NOT_EQUAL", "T_ERROR", "T_AND", "T_OR", "T_NOT", "UNARY_OPS", "T_ID",
  "T_INT_CONSTANT", "T_DOUBLE_CONSTANT", "T_STRING_CONSTANT", "T_PRINT",
  "IF_NO_ELSE", "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "simple_type", "optional_initializer",
  "object_declaration", "$@1", "object_type", "parameter_list_or_empty",
  "parameter_list", "parameter", "forward_declaration", "block_list",
  "block", "initialization_block", "animation_block", "$@2",
  "animation_parameter", "check_animation_parameter", "on_block",
  "keystroke", "if_block", "statement_block", "statement_block_creator",
  "end_of_statement_block", "statement_list", "statement", "if_statement",
  "for_statement", "print_statement", "exit_statement", "assign_statement",
  "variable", "expression", "primary_expression", "geometric_operator",
  "math_operator", "empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,   100,    99,    99,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   104,   105,   106,
     106,   107,   107,   107,   108,   110,   109,   111,   112,   112,
     112,   112,   112,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     117,   118,   119,   119,   120,   120,   120,   120,   120,   121,
     121,   122,   123,   124,   125,   125,   125,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     3,     5,
       1,     1,     1,     2,     1,     0,     6,     5,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     6,     2,
       1,     1,     1,     1,     2,     0,    10,     2,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     5,
       0,     0,     2,     1,     1,     1,     2,     2,     2,     5,
       7,    13,     4,     4,     3,     3,     3,     1,     4,     3,
       6,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     4,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     128,     0,   128,     4,     1,    10,    11,    12,    18,    19,
      20,    21,    22,     0,     3,     0,     0,     0,     0,     0,
       2,    30,     0,     5,   128,     6,    15,     7,     0,     0,
       0,    29,    31,    32,    33,     0,     0,     0,     8,    14,
       0,     0,    70,    34,    44,    47,    48,    45,    46,    49,
      50,    51,    52,    53,    54,    55,    56,    66,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
     112,   113,     0,     0,   118,   119,   120,   121,   122,   123,
     124,   126,   125,   127,     0,    87,   111,   114,   115,   110,
       0,    91,     0,    13,     0,   128,   128,    43,     0,     0,
       0,     0,   105,   106,     0,     0,   116,   117,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,    23,    26,    24,
       0,    73,     0,     0,     0,     0,     0,     0,    37,    28,
     109,     0,    89,   108,   102,   103,   104,   100,   101,    96,
      97,    94,    95,    98,    99,    93,    92,     0,     0,    16,
       0,     0,     0,     0,    71,     0,    72,    74,    75,     0,
       0,     0,     0,    38,    39,    40,    41,    42,     0,    88,
     107,    27,    25,     0,    70,     0,    69,     0,    77,    78,
      76,     0,     0,     0,    35,     0,     0,     0,     0,     0,
      84,    85,    86,   128,    90,    70,    71,    83,    82,     0,
      79,    68,     0,     0,    71,    70,    71,     0,    36,    80,
      67,     0,    70,     0,    71,     0,     0,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    38,    17,    41,    18,
     126,   127,   128,    19,    20,    31,    32,    33,   203,   100,
     137,    34,    67,   210,   211,   212,   186,   130,   166,   167,
     168,   169,   170,   171,    89,    90,    91,   108,    92,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
    -192,    10,   125,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,   -19,  -192,   -26,   -58,   -17,   -48,   -12,
      12,  -192,   -39,  -192,   -38,  -192,    13,  -192,    16,   387,
     -21,  -192,  -192,  -192,  -192,    21,    99,    99,  -192,  -192,
      99,    42,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,    16,    43,    36,
    -192,  -192,    99,    99,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,    99,   -20,  -192,  -192,  -192,    15,
     221,  -192,    44,   319,   251,    17,  -192,  -192,   193,    19,
      51,   114,  -192,  -192,    99,    20,  -192,  -192,    28,  -192,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,  -192,    46,    52,    38,  -192,  -192,
     -34,  -192,    29,    30,    31,    34,    35,    55,  -192,  -192,
    -192,   281,  -192,  -192,  -192,  -192,  -192,   -11,   -11,     9,
       9,     9,     9,    33,    33,    63,   366,   148,    99,  -192,
      17,    73,    91,   100,  -192,   102,  -192,  -192,  -192,    98,
     101,   106,     3,  -192,  -192,  -192,  -192,  -192,   104,   105,
    -192,   319,  -192,    99,  -192,    99,  -192,    99,  -192,  -192,
    -192,    99,    99,    99,  -192,    68,   157,    28,   182,   191,
     319,   319,   319,  -192,  -192,    16,  -192,  -192,  -192,   -29,
     116,  -192,   -24,   110,  -192,    16,  -192,    99,  -192,  -192,
    -192,   310,  -192,    28,  -192,   132,    16,  -192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   111,
    -192,  -192,    24,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,   -10,   -28,   -40,  -183,     4,    -6,  -192,
    -192,  -192,  -192,  -191,  -105,   -36,  -192,  -192,  -192,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    93,    96,   143,    94,     3,   206,    21,   161,   162,
       4,   163,    36,   161,   162,   164,   163,    37,   161,   162,
     214,   163,    22,   213,    28,   172,    23,    29,    24,    39,
     104,   218,   224,   220,   105,    25,   101,   102,    26,    97,
      27,   225,     8,     9,    10,    11,    12,    35,   103,   110,
     111,   112,    85,    30,   106,   107,   165,    85,   191,   192,
     193,   165,    85,    40,    42,    68,   165,    69,   141,   110,
     111,   112,   113,   114,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    95,    98,
     123,   160,   172,   110,   111,   112,   113,   114,   139,   159,
     129,   158,   178,   125,   172,   138,   142,   172,   115,   116,
     117,   118,    70,    71,    85,   173,   174,   175,   172,   183,
     176,   177,   181,   110,   111,   112,   113,   114,     5,     6,
       7,     8,     9,    10,    11,    12,    13,   184,   115,   116,
     117,   118,   119,   120,   197,    72,   185,   196,   187,   198,
     188,   199,   194,   189,   204,   200,   201,   202,   190,   195,
     215,   140,   217,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   110,   111,   112,   113,   114,   226,
      99,   221,   223,    84,   182,    85,    86,    87,    88,   115,
     116,   117,   118,   119,   120,   180,   121,   122,   227,   132,
     133,   134,   135,   136,   205,   219,   216,   209,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   110,   111,   112,
     113,   114,     0,   115,   116,   117,   118,   119,   120,   207,
     121,   122,   115,   116,   117,   118,   119,   120,   208,   121,
     122,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   110,   111,   112,   113,   114,     0,   115,   116,   117,
     118,   119,   120,     0,   121,   122,   115,   116,   117,   118,
     119,   120,   109,   121,   122,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   124,   121,   122,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   179,   121,   122,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   222,   121,   122,     0,     0,     0,     0,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   110,
     111,   112,   113,   114,     0,   115,   116,   117,   118,   119,
     120,     0,   121,   122,   115,   116,   117,   118,   119,   120,
       0,   121,   122,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,     0,   121
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-192))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,    37,    42,   108,    40,     0,   197,     2,    42,    43,
       0,    45,    50,    42,    43,    49,    45,    55,    42,    43,
      49,    45,    41,   206,    12,   130,    52,    15,    86,    24,
      50,   214,   223,   216,    54,    52,    72,    73,    86,    67,
      52,   224,     6,     7,     8,     9,    10,    86,    84,    60,
      61,    62,    86,    41,    39,    40,    90,    86,    55,    56,
      57,    90,    86,    50,    48,    86,    90,    46,   104,    60,
      61,    62,    63,    64,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    46,    46,
      46,    53,   197,    60,    61,    62,    63,    64,    47,    47,
      95,    55,    47,    86,   209,    86,    86,   212,    75,    76,
      77,    78,    13,    14,    86,    86,    86,    86,   223,    46,
      86,    86,   158,    60,    61,    62,    63,    64,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    46,    75,    76,
      77,    78,    79,    80,   184,    46,    46,   183,    46,   185,
      52,   187,    48,    52,    86,   191,   192,   193,    52,    54,
      44,    47,    52,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    60,    61,    62,    63,    64,    47,
      69,   217,   222,    84,   160,    86,    87,    88,    89,    75,
      76,    77,    78,    79,    80,    47,    82,    83,   226,     6,
       7,     8,     9,    10,    47,   215,   212,   203,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    75,    76,    77,    78,    79,    80,    47,
      82,    83,    75,    76,    77,    78,    79,    80,    47,    82,
      83,    -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    75,    76,    77,
      78,    79,    80,    -1,    82,    83,    75,    76,    77,    78,
      79,    80,    51,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    51,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    51,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    52,    82,    83,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    -1,    75,    76,    77,    78,    79,
      80,    -1,    82,    83,    75,    76,    77,    78,    79,    80,
      -1,    82,    83,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,    94,   131,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    95,    96,    97,    99,   101,   105,
     106,   131,    41,    52,    86,    52,    86,    52,    12,    15,
      41,   107,   108,   109,   113,    86,    50,    55,    98,   131,
      50,   100,    48,   116,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,   114,    86,    46,
      13,    14,    46,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    84,    86,    87,    88,    89,   126,
     127,   128,   130,   127,   127,    46,   117,   116,    46,   101,
     111,   127,   127,   127,    50,    54,    39,    40,   129,    51,
      60,    61,    62,    63,    64,    75,    76,    77,    78,    79,
      80,    82,    83,    46,    51,    86,   102,   103,   104,   131,
     119,   131,     6,     7,     8,     9,    10,   112,    86,    47,
      47,   127,    86,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,    55,    47,
      53,    42,    43,    45,    49,    90,   120,   121,   122,   123,
     124,   125,   126,    86,    86,    86,    86,    86,    47,    51,
      47,   127,   104,    46,    46,    46,   118,    46,    52,    52,
      52,    55,    56,    57,    48,    54,   127,   117,   127,   127,
     127,   127,   127,   110,    86,    47,   125,    47,    47,   119,
     115,   116,   117,   118,    49,    44,   120,    52,   118,   115,
     118,   127,    52,   117,   125,   118,    47,   116
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:

/* Line 1806 of yacc.c  */
#line 230 "gpl.y"
    {
        string id = *(yyvsp[(2) - (3)].union_string);
        if(!symbol_table->lookup(id) && !symbol_table->lookup(id+"[0]"))
        {          
            if((yyvsp[(1) - (3)].union_gpl_type) == INT)
            {
                int initial_value = 0;
                
                if((yyvsp[(3) - (3)].union_expression_kind) != NULL)
                {
                    if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getKind() == DOUBLE_CONST
                        || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == DOUBLE)
                    {
                        Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, id);
                    }
                    else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == INT_CONST)
                    {   
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_int();
                    }
                    else
                    {
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_int();
                    }               
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
            else if((yyvsp[(1) - (3)].union_gpl_type) == DOUBLE)
            {
                double initial_value = 0;
                
                if((yyvsp[(3) - (3)].union_expression_kind) != NULL)
                {
                    if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
                    {
                        Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, id);
                    }
                    else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == INT_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == INT)
                    {
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_int();
                    }
                    else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == DOUBLE_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == DOUBLE)
                    {   
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_double();
                    }
                    else
                    {
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_double();
                    }        
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
            else if((yyvsp[(1) - (3)].union_gpl_type) == STRING)
            {
                string initial_value = "";
                if((yyvsp[(3) - (3)].union_expression_kind) != NULL)
                {
                    if((yyvsp[(3) - (3)].union_expression_kind)->getGplType() == INT)
                    {
                        ostringstream oss;
                        oss << (yyvsp[(3) - (3)].union_expression_kind)->eval_int();
                        initial_value = oss.str();
                    }
                    else if((yyvsp[(3) - (3)].union_expression_kind)->getGplType() == DOUBLE)
                    {
                        ostringstream oss;
                        oss << (yyvsp[(3) - (3)].union_expression_kind)->eval_double();
                        initial_value = oss.str();
                    }
                    else
                        initial_value = (yyvsp[(3) - (3)].union_expression_kind)->eval_string();  
                }
                symbol_table->insert(new Symbol(id,initial_value));
            }
        }
        else
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, id);
        }
    }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 310 "gpl.y"
    {   
        string id = *(yyvsp[(2) - (5)].union_string);     
        if((yyvsp[(4) - (5)].union_expression_kind)->getGplType() == STRING || (yyvsp[(4) - (5)].union_expression_kind)->getGplType() == DOUBLE)
        {
            Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expression_kind)->eval_string());
        }
        else if(!symbol_table->lookup(id) && !symbol_table->lookup(id+"[0]"))
        {
            if((yyvsp[(4) - (5)].union_expression_kind)->eval_int() == 0)
            {
                Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expression_kind)->eval_string());
            }
            if((yyvsp[(1) - (5)].union_gpl_type) == INT)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),0));
                }
                
            }
            else if((yyvsp[(1) - (5)].union_gpl_type) == DOUBLE)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss  << id  << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),0));
                }
            }
            else if((yyvsp[(1) - (5)].union_gpl_type) == STRING)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss  << id  << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),""));
                }
            }
        }
        else
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, id);
        }
    }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 361 "gpl.y"
    {
        (yyval.union_gpl_type) = INT;
    }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 365 "gpl.y"
    {
        (yyval.union_gpl_type) = DOUBLE;
    }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 369 "gpl.y"
    {
        (yyval.union_gpl_type) = STRING;
    }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 377 "gpl.y"
    {
      (yyval.union_expression_kind) = (yyvsp[(2) - (2)].union_expression_kind);
    }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 381 "gpl.y"
    {
      (yyval.union_expression_kind) = NULL;
    }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 389 "gpl.y"
    {
        string id = *(yyvsp[(2) - (2)].union_string);
        switch((yyvsp[(1) - (2)].union_int))
        {
            case T_TRIANGLE:
                cur_object_under_construction = new Triangle();
                break;
            case T_PIXMAP:
                cur_object_under_construction = new Pixmap();
                break;
            case T_CIRCLE:
                cur_object_under_construction = new Circle();
                break;
            case T_RECTANGLE:
                cur_object_under_construction = new Rectangle();
                break;
            case T_TEXTBOX:
                cur_object_under_construction = new Textbox();
                break;
        }
        symbol_table->insert(new Symbol(id, (yyvsp[(1) - (2)].union_int)));
    }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 412 "gpl.y"
    {
        
    }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 416 "gpl.y"
    {
        string id = *(yyvsp[(2) - (5)].union_string);
        if((yyvsp[(4) - (5)].union_expression_kind)->getGplType() == STRING || (yyvsp[(4) - (5)].union_expression_kind)->getGplType() == DOUBLE)
        {
            Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expression_kind)->eval_string());
        }
        else if(!symbol_table->lookup(id) && !symbol_table->lookup(id+"[0]"))
        {
            if((yyvsp[(4) - (5)].union_expression_kind)->eval_int() == 0)
            {
                Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expression_kind)->eval_string());
            }
            if((yyvsp[(1) - (5)].union_int) == T_TRIANGLE)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),new Triangle()));
                }
            }
            else if((yyvsp[(1) - (5)].union_int) == T_PIXMAP)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),new Pixmap()));
                }
            }
            else if((yyvsp[(1) - (5)].union_int) == T_CIRCLE)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),new Circle()));
                }
            }
            else if((yyvsp[(1) - (5)].union_int) == T_RECTANGLE)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),new Rectangle()));
                }
            }
            else if((yyvsp[(1) - (5)].union_int) == T_TEXTBOX)
            {
                for(int i = 0; i < (yyvsp[(4) - (5)].union_expression_kind)->eval_int(); i++)
                {
                    stringstream ss;
                    ss << id << "[" << i << "]";
                    symbol_table->insert(new Symbol(ss.str(),new Textbox()));
                }
            }
        }
        else
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, id);
        }
    }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 484 "gpl.y"
    {
        (yyval.union_int) = T_TRIANGLE;
    }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 488 "gpl.y"
    {
        (yyval.union_int) = T_PIXMAP;
    }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 492 "gpl.y"
    {
        (yyval.union_int) = T_CIRCLE;
    }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 496 "gpl.y"
    {
        (yyval.union_int) = T_RECTANGLE;
    }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 500 "gpl.y"
    {
        (yyval.union_int) = T_TEXTBOX;
    }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 547 "gpl.y"
    { }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 548 "gpl.y"
    {
        //$$ = new Animation_block();
    }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 666 "gpl.y"
    {
        if(symbol_table->lookup(*(yyvsp[(1) - (1)].union_string)))
        {
            (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (1)].union_string));
        }
        else 
        {
            Error::error(Error::UNDECLARED_VARIABLE,*(yyvsp[(1) - (1)].union_string));
            (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (1)].union_string));
        }
    }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 678 "gpl.y"
    {
        if((yyvsp[(3) - (4)].union_expression_kind)->getGplType() == INT)
        {
            string name = *(yyvsp[(1) - (4)].union_string);
            int i = (yyvsp[(3) - (4)].union_expression_kind)->eval_int();
            stringstream ss;
            ss << name << "[" << i << "]";
            name = ss.str();
            
            if(!symbol_table->lookup(name))
            {
                (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression_kind));
                Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression_kind)->eval_string());
            }
            else
                (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression_kind));
        }
        else if((yyvsp[(3) - (4)].union_expression_kind)->getGplType() == DOUBLE)
        {
            (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression_kind));
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*(yyvsp[(1) - (4)].union_string), "A double expression");
        }
        else if((yyvsp[(3) - (4)].union_expression_kind)->getGplType() == STRING)
        {         
            (yyval.union_variable_type) = new Variable(*(yyvsp[(1) - (4)].union_string), (yyvsp[(3) - (4)].union_expression_kind));
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*(yyvsp[(1) - (4)].union_string), "A string expression");
        }
    }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 707 "gpl.y"
    {
        (yyval.union_variable_type) = NULL;
    }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 711 "gpl.y"
    {
        (yyval.union_variable_type)= NULL;
    }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 719 "gpl.y"
    {
        (yyval.union_expression_kind) = (yyvsp[(1) - (1)].union_expression_kind);
    }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 723 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
            (yyval.union_expression_kind) = new Expr(OR,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 738 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
            (yyval.union_expression_kind) = new Expr(AND,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 753 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(LESS_THAN_EQUAL,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 757 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(GREATER_THAN_EQUAL,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 761 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(LESS_THAN,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 765 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(GREATER_THAN,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 769 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(EQUAL,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 773 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(NOT_EQUAL,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 777 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(PLUS,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 781 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "-");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
            (yyval.union_expression_kind) = new Expr(MINUS,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
    }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 796 "gpl.y"
    {
        
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "*");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "*");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
        {
            (yyval.union_expression_kind) = new Expr(MULTIPLY,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
        }
        
    }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 815 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
        {
            (yyval.union_expression_kind) = new Expr(DIVIDE,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
        }
    }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 832 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(1) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "%");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else if((yyvsp[(3) - (3)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (3)].union_expression_kind)->getGplType() == STRING)
        {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "%");
            (yyval.union_expression_kind) = new Expr(0);
        }
        else
        {
            (yyval.union_expression_kind) = new Expr(MOD,(yyvsp[(1) - (3)].union_expression_kind),(yyvsp[(3) - (3)].union_expression_kind));
        }
    }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 849 "gpl.y"
    {       
        if((yyvsp[(2) - (2)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(2) - (2)].union_expression_kind)->getGplType() == STRING)
        {    
            (yyval.union_expression_kind) = new Expr(0);
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
        }
        (yyval.union_expression_kind) = new Expr(UNARY_MINUS, (yyvsp[(2) - (2)].union_expression_kind));
    }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 858 "gpl.y"
    {
        if((yyvsp[(2) - (2)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(2) - (2)].union_expression_kind)->getGplType() == STRING)
        {   
            (yyval.union_expression_kind) = new Expr(0);
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "!");
        }
        else
            (yyval.union_expression_kind) = new Expr(NOT, (yyvsp[(2) - (2)].union_expression_kind));
    }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 868 "gpl.y"
    {
        if((yyvsp[(3) - (4)].union_expression_kind)->getKind() == STRING_CONST || (yyvsp[(3) - (4)].union_expression_kind)->getGplType() == STRING)
        {
            if((yyvsp[(1) - (4)].union_operator_type) == SIN)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sin");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == COS)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "cos");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == TAN)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "tan");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == ASIN)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "asin");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == ACOS)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "acos");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == ATAN)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "atan");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == SQRT)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "sqrt");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == FLOOR)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "floor");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == RANDOM)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "random");
                (yyval.union_expression_kind) = new Expr(0);
            }
            else if((yyvsp[(1) - (4)].union_operator_type) == ABS)
            {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "abs");
                (yyval.union_expression_kind) = new Expr(0);
            }
            
           
        }
        else
        {
            (yyval.union_expression_kind) = new Expr((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expression_kind));
        }
    }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 930 "gpl.y"
    {
    }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 937 "gpl.y"
    {
        (yyval.union_expression_kind) = (yyvsp[(2) - (3)].union_expression_kind);
    }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 941 "gpl.y"
    {        
        (yyval.union_expression_kind) = new Expr((yyvsp[(1) - (1)].union_variable_type));   
    }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 945 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr((yyvsp[(1) - (1)].union_int));
    }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 949 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(1);
    }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 953 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(0);
    }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 957 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr((yyvsp[(1) - (1)].union_double));
    }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 961 "gpl.y"
    {
        (yyval.union_expression_kind) = new Expr(*(yyvsp[(1) - (1)].union_string));
    }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 975 "gpl.y"
    {
        (yyval.union_operator_type) = SIN;
    }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 979 "gpl.y"
    {
        (yyval.union_operator_type) = COS;
    }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 983 "gpl.y"
    {
        (yyval.union_operator_type) = TAN;
    }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 987 "gpl.y"
    {
        (yyval.union_operator_type) = ASIN;
    }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 991 "gpl.y"
    {
        (yyval.union_operator_type) = ACOS;
    }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 995 "gpl.y"
    {
        (yyval.union_operator_type) = ATAN;
    }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 999 "gpl.y"
    {
        (yyval.union_operator_type) = SQRT;
    }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1003 "gpl.y"
    {
        (yyval.union_operator_type) = ABS;
    }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1007 "gpl.y"
    {
        (yyval.union_operator_type) = FLOOR;
    }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1011 "gpl.y"
    {
        (yyval.union_operator_type) = RANDOM;
    }
    break;



/* Line 1806 of yacc.c  */
#line 2713 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



