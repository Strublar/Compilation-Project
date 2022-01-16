
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
#line 1 "psdhd.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void yyerror(char *errormsg);
int yylex();

void insert_type();
void addSymbol(char* type, char* variable_type, char* name);
int searchSymbol(char *name);
int count=0;
int query;
extern int countn;

struct symData {
        char * id_name;
        char * returnType;
        char * type;
        int lineNumber;
} sym[64];

struct node {
  struct node *left;
  struct node *right;
  char *token;     
};


struct node *root;
struct node* createNode(struct node *left, struct node *right, char *token);
void printTree(struct node *tree);



/* Line 189 of yacc.c  */
#line 112 "y.tab.c"

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
     CHARACTER = 258,
     STRING = 259,
     NUMBER = 260,
     INT_TYPE = 261,
     REAL_TYPE = 262,
     BOOLEAN_TYPE = 263,
     CHAR_TYPE = 264,
     STRING_TYPE = 265,
     VOID_TYPE = 266,
     ADDITION_OPERATOR = 267,
     SUBSTRACTION_OPERATOR = 268,
     MULTIPLICATION_OPERATOR = 269,
     DIVISION_OPERATOR = 270,
     AND_OPERATOR = 271,
     OR_OPERATOR = 272,
     NOT_OPERATOR = 273,
     INF_OPERATOR = 274,
     INFEQ_OPERATOR = 275,
     SUP_OPERATOR = 276,
     SUPEQ_OPERATOR = 277,
     EQ_OPERATOR = 278,
     DIFF_OPERATOR = 279,
     TRUE = 280,
     FALSE = 281,
     MATHEMATICAL_FUNCTION = 282,
     IDENTIFIER = 283,
     FUNCTION = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     START = 288,
     END = 289,
     RETURN = 290,
     WHILE = 291,
     DO = 292,
     READ = 293,
     WRITE = 294
   };
#endif
/* Tokens.  */
#define CHARACTER 258
#define STRING 259
#define NUMBER 260
#define INT_TYPE 261
#define REAL_TYPE 262
#define BOOLEAN_TYPE 263
#define CHAR_TYPE 264
#define STRING_TYPE 265
#define VOID_TYPE 266
#define ADDITION_OPERATOR 267
#define SUBSTRACTION_OPERATOR 268
#define MULTIPLICATION_OPERATOR 269
#define DIVISION_OPERATOR 270
#define AND_OPERATOR 271
#define OR_OPERATOR 272
#define NOT_OPERATOR 273
#define INF_OPERATOR 274
#define INFEQ_OPERATOR 275
#define SUP_OPERATOR 276
#define SUPEQ_OPERATOR 277
#define EQ_OPERATOR 278
#define DIFF_OPERATOR 279
#define TRUE 280
#define FALSE 281
#define MATHEMATICAL_FUNCTION 282
#define IDENTIFIER 283
#define FUNCTION 284
#define IF 285
#define THEN 286
#define ELSE 287
#define START 288
#define END 289
#define RETURN 290
#define WHILE 291
#define DO 292
#define READ 293
#define WRITE 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "psdhd.y"

    char *str;
	struct var_name {
	   char name[100];
	   struct node* node;
	} node_object;



/* Line 214 of yacc.c  */
#line 236 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 248 "y.tab.c"

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
# if YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    36,    39,    41,    43,
      45,    47,    49,    53,    65,    73,    81,    88,    95,   100,
     103,   107,   111,   115,   119,   123,   125,   127,   129,   131,
     133,   135,   137,   139,   143,   147,   151,   155,   159,   163,
     167,   171,   175,   177,   179,   180,   195,   197,   202,   205,
     209,   214,   216,   218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    41,    49,
      -1,    50,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    57,    -1,    56,    -1,    62,    -1,    66,    -1,    58,
      -1,    51,    29,    42,    59,    -1,    51,    29,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,    29,
      42,    59,    -1,    31,    61,    32,    41,    48,    41,    33,
      41,    48,    41,    35,    -1,    31,    61,    32,    41,    48,
      41,    35,    -1,    37,    61,    38,    41,    48,    41,    35,
      -1,    38,    41,    48,    41,    37,    61,    -1,    39,    43,
       4,    27,    29,    44,    -1,    40,    43,    59,    44,    -1,
      36,    59,    -1,    59,    12,    59,    -1,    59,    13,    59,
      -1,    59,    14,    59,    -1,    59,    15,    59,    -1,    43,
      59,    44,    -1,    66,    -1,    60,    -1,     5,    -1,     4,
      -1,     3,    -1,    25,    -1,    26,    -1,    29,    -1,    59,
      16,    59,    -1,    59,    17,    59,    -1,    59,    18,    59,
      -1,    59,    23,    59,    -1,    59,    24,    59,    -1,    59,
      21,    59,    -1,    59,    22,    59,    -1,    59,    19,    59,
      -1,    59,    20,    59,    -1,    25,    -1,    26,    -1,    -1,
      30,    29,    43,    64,    44,    45,    51,    41,    63,    34,
      41,    48,    41,    35,    -1,    65,    -1,    51,    29,    42,
      60,    -1,    51,    29,    -1,    65,    27,    65,    -1,    29,
      43,    67,    44,    -1,    68,    -1,    59,    -1,    68,    27,
      68,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   105,   106,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   126,   131,   138,   139,   140,
     141,   142,   146,   151,   161,   172,   183,   193,   202,   206,
     211,   216,   221,   226,   231,   232,   233,   238,   239,   240,
     241,   242,   243,   248,   252,   256,   260,   264,   268,   272,
     276,   280,   284,   285,   290,   290,   302,   306,   310,   311,
     315,   319,   323,   324
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHARACTER", "STRING", "NUMBER",
  "INT_TYPE", "REAL_TYPE", "BOOLEAN_TYPE", "CHAR_TYPE", "STRING_TYPE",
  "VOID_TYPE", "ADDITION_OPERATOR", "SUBSTRACTION_OPERATOR",
  "MULTIPLICATION_OPERATOR", "DIVISION_OPERATOR", "AND_OPERATOR",
  "OR_OPERATOR", "NOT_OPERATOR", "INF_OPERATOR", "INFEQ_OPERATOR",
  "SUP_OPERATOR", "SUPEQ_OPERATOR", "EQ_OPERATOR", "DIFF_OPERATOR", "TRUE",
  "FALSE", "','", "MATHEMATICAL_FUNCTION", "IDENTIFIER", "FUNCTION", "IF",
  "THEN", "ELSE", "START", "END", "RETURN", "WHILE", "DO", "READ", "WRITE",
  "'\\n'", "'='", "'('", "')'", "':'", "$accept", "program",
  "statement_list", "statement", "declaration_statement", "variable_type",
  "assignement_statement", "if_statement", "while_statement",
  "do_while_statement", "read_statement", "write_statement",
  "return_statement", "expression", "value", "condition",
  "function_declaration", "@1", "argument_declaration_list",
  "argument_declaration", "function_call", "argument_list", "argument", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    44,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,    10,    61,    40,    41,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    52,    53,    53,    54,    55,    56,    57,    58,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    63,    62,    64,    65,    65,    65,
      66,    67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     1,     1,     1,
       1,     1,     3,    11,     7,     7,     6,     6,     4,     2,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     0,    14,     1,     4,     2,     3,
       4,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     5,     0,     6,
       7,     8,     9,    11,    10,    14,    12,    13,     0,     0,
       0,    39,    38,    37,    40,    41,    42,     0,     0,    36,
       0,    35,    40,    41,    29,     0,     0,     0,     0,     1,
       0,    16,    22,    62,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,    60,     0,
       0,     0,    56,    34,    30,    31,    32,    33,    43,    44,
      45,    50,    51,    48,    49,    46,    47,     0,     0,     0,
       0,    28,    15,    63,    58,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,    26,    27,    42,    57,
       0,     0,    24,    25,    54,     0,     0,     0,     0,     0,
       0,    23,     0,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    38,    39,    40,    26,   126,    81,    82,
      41,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int16 yypact[] =
{
     180,   -45,   -45,   -45,   -45,   -45,   -22,   -20,     8,    80,
       8,   -27,   -11,     5,    43,     6,   -45,   -45,    23,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    80,    80,
      12,   -45,   -45,   -45,     3,     4,    13,    80,   233,   -45,
      26,   -45,   -45,   -45,    10,    36,   180,    71,    80,   -45,
     180,    35,    10,    10,    48,    52,     9,    98,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    53,    54,    55,    66,   200,   -45,    80,   -45,    80,
      72,    58,    76,   -45,    75,    25,    89,   -45,    10,    10,
      10,    10,    10,    10,    10,    10,    10,   180,   180,   198,
      78,   -45,    10,   -45,    79,    63,     9,    81,    83,     8,
      82,     2,     9,   -45,   110,   128,    36,   -45,   -45,   -45,
      86,    87,   -45,   -45,   -45,   180,    97,    91,   103,   145,
     180,   -45,   115,   163,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -44,   -42,   -45,   -30,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,     1,    49,    -9,   -45,   -45,   -45,    56,
       0,   -45,    99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -54
static const yytype_int16 yytable[] =
{
      27,    45,    73,   -52,   -53,    31,    32,    33,    76,    30,
      44,    31,    32,    33,    46,     1,     2,     3,     4,     5,
      28,    29,    58,    59,    60,    61,    80,    42,    43,    52,
      53,   118,    47,    34,    35,   -52,   -53,    36,    57,    60,
      61,   -52,   -53,    49,   -52,   -53,    27,    50,    48,    75,
      27,    37,    51,   107,   108,    56,    29,    76,    71,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    76,    76,    72,    74,    80,    77,   102,    79,
      53,   127,   120,    31,    32,    33,   132,    76,    59,    60,
      61,    76,    78,   100,    97,    98,    99,    27,    27,    27,
     116,   104,   105,   106,    61,    42,    43,   110,   112,    36,
      58,    59,    60,    61,    27,    27,     1,     2,     3,     4,
       5,   111,   114,    37,   115,    27,   117,   124,   125,    27,
      27,   128,   129,    27,     1,     2,     3,     4,     5,     6,
       7,     8,    83,   121,   130,   122,     9,    10,    11,    12,
      13,     1,     2,     3,     4,     5,   133,     6,     7,     8,
     119,     0,   113,   123,     9,    10,    11,    12,    13,     1,
       2,     3,     4,     5,     6,     7,     8,     0,   103,     0,
     131,     9,    10,    11,    12,    13,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     0,     0,     0,   134,     9,
      10,    11,    12,    13,     1,     2,     3,     4,     5,     6,
       7,     8,    58,    59,    60,    61,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       0,     0,     0,     0,     9,   109,    11,    12,    13,     0,
       0,     0,     0,     0,   101,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
       0,    10,    46,     0,     0,     3,     4,     5,    50,    29,
       9,     3,     4,     5,    41,     6,     7,     8,     9,    10,
      42,    43,    12,    13,    14,    15,    56,    25,    26,    28,
      29,    29,    43,    25,    26,    32,    32,    29,    37,    14,
      15,    38,    38,     0,    41,    41,    46,    41,    43,    48,
      50,    43,    29,    97,    98,    43,    43,    99,    32,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,   114,   115,    38,     4,   106,    42,    77,    27,
      79,   125,   112,     3,     4,     5,   130,   129,    13,    14,
      15,   133,    44,    27,    41,    41,    41,    97,    98,    99,
     109,    29,    44,    27,    15,    25,    26,    29,    45,    29,
      12,    13,    14,    15,   114,   115,     6,     7,     8,     9,
      10,    42,    41,    43,    41,   125,    44,    41,    41,   129,
     130,    34,    41,   133,     6,     7,     8,     9,    10,    29,
      30,    31,    44,    33,    41,    35,    36,    37,    38,    39,
      40,     6,     7,     8,     9,    10,    41,    29,    30,    31,
     111,    -1,   106,    35,    36,    37,    38,    39,    40,     6,
       7,     8,     9,    10,    29,    30,    31,    -1,    79,    -1,
      35,    36,    37,    38,    39,    40,     6,     7,     8,     9,
      10,    -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,     6,     7,     8,     9,    10,    29,
      30,    31,    12,    13,    14,    15,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    44,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    29,    30,    31,    36,
      37,    38,    39,    40,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    62,    66,    42,    43,
      29,     3,     4,     5,    25,    26,    29,    43,    59,    60,
      61,    66,    25,    26,    59,    61,    41,    43,    43,     0,
      41,    29,    59,    59,    67,    68,    43,    59,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    32,    38,    48,     4,    59,    49,    42,    44,    27,
      51,    64,    65,    44,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    41,    41,    41,
      27,    44,    59,    68,    29,    44,    27,    48,    48,    37,
      29,    42,    45,    65,    41,    41,    61,    44,    29,    60,
      51,    33,    35,    35,    41,    41,    63,    48,    34,    41,
      41,    35,    48,    41,    35
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
        case 2:

/* Line 1455 of yacc.c  */
#line 97 "psdhd.y"
    { 
							(yyval.node_object).node = createNode((yyvsp[(1) - (1)].node_object).node, NULL, "program"); 
							root = (yyval.node_object).node;
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 105 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 106 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "statement_list"); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 112 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 113 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 114 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 115 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 116 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 117 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 118 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 119 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 120 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 121 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 126 "psdhd.y"
    { 
														addSymbol("Variable", (yyvsp[(1) - (4)].node_object).name, (yyvsp[(2) - (4)].node_object).name);
														struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "decl_without_assign");
														(yyval.node_object).node = createNode(type_id, (yyvsp[(2) - (4)].node_object).node, "decl_with_assign");
													}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 131 "psdhd.y"
    {
														addSymbol("Variable",(yyvsp[(1) - (2)].node_object).name,(yyvsp[(2) - (2)].node_object).name);
														(yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "decl_without_assign");
													}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 138 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 139 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 140 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 141 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 142 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 146 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "assignement_statement"); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 152 "psdhd.y"
    { 
				struct node *then_stat = createNode((yyvsp[(3) - (11)].node_object).node, (yyvsp[(5) - (11)].node_object).node, "then_stat");
				struct node *cond_then_stat = createNode((yyvsp[(2) - (11)].node_object).node, then_stat, "cond_then_stat");
				struct node *else_stat = createNode((yyvsp[(7) - (11)].node_object).node, (yyvsp[(9) - (11)].node_object).node, "else_stat");
				struct node *cond_then_stat_else_stat = createNode(cond_then_stat, else_stat, "cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat = createNode((yyvsp[(1) - (11)].node_object).node, cond_then_stat_else_stat, "if_cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat_end = createNode(if_cond_then_stat_else_stat, (yyvsp[(11) - (11)].node_object).node, "if_cond_then_stat_else_stat_end");
				(yyval.node_object).node = if_cond_then_stat_else_stat_end;			
			}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 162 "psdhd.y"
    { 
				struct node *then_stat = createNode((yyvsp[(3) - (7)].node_object).node, (yyvsp[(5) - (7)].node_object).node, "then_stat");
				struct node *cond_then_stat = createNode((yyvsp[(2) - (7)].node_object).node, then_stat, "cond_then_stat");
				struct node *if_cond_then_stat = createNode((yyvsp[(1) - (7)].node_object).node, cond_then_stat, "if_cond_then_stat");
				struct node *if_cond_then_stat_end = createNode(if_cond_then_stat, (yyvsp[(7) - (7)].node_object).node, "if_statement");
				(yyval.node_object).node = if_cond_then_stat_end;
			}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 173 "psdhd.y"
    { 
				struct node *while_cond = createNode((yyvsp[(1) - (7)].node_object).node, (yyvsp[(2) - (7)].node_object).node, "while_cond");
				struct node *do_stat = createNode((yyvsp[(3) - (7)].node_object).node, (yyvsp[(5) - (7)].node_object).node, "do_stat");
				struct node *while_cond_do_stat = createNode(while_cond, do_stat, "while_cond_do_stat");
				struct node *while_cond_do_stat_end = createNode(while_cond_do_stat, (yyvsp[(7) - (7)].node_object).node, "while_statement");
				(yyval.node_object).node = while_cond_do_stat_end;
			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 184 "psdhd.y"
    { 
				struct node *do_stat = createNode((yyvsp[(1) - (6)].node_object).node, (yyvsp[(3) - (6)].node_object).node, "do_stat");
				struct node *while_cond = createNode((yyvsp[(5) - (6)].node_object).node, (yyvsp[(6) - (6)].node_object).node, "while_cond");
				struct node *do_stat_while_cond = createNode(do_stat, while_cond, "do_while_statement");
				(yyval.node_object).node = do_stat_while_cond;
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 194 "psdhd.y"
    { 
				struct node *str_id = createNode((yyvsp[(3) - (6)].node_object).node, (yyvsp[(5) - (6)].node_object).node, "str_id");
				struct node *read_str_id = createNode((yyvsp[(1) - (6)].node_object).node, str_id, "read_statement");
				(yyval.node_object).node = read_str_id;
			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 202 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(3) - (4)].node_object).node, "write_statement"); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "return_statement"); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 211 "psdhd.y"
    {
																 
																struct node *plus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "plus_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, plus_expr, "expr_plus_expr");
															}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 216 "psdhd.y"
    {
																 
																struct node *minus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "minus_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, minus_expr, "expr_minus_expr");
															}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 221 "psdhd.y"
    {
																 
																struct node *mult_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "mult_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, mult_expr, "expr_mult_expr");
															}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 226 "psdhd.y"
    {
																 
																struct node *div_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "div_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, div_expr, "expr_div_expr");
															}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 231 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(2) - (3)].node_object).node; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 232 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 233 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 238 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 239 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 240 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 241 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 242 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 243 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 248 "psdhd.y"
    {
														struct node *and_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "and_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, and_expr, "expr_and_expr");
													}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 252 "psdhd.y"
    {
														struct node *or_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "or_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, or_expr, "expr_or_expr");
													}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 256 "psdhd.y"
    {
														struct node *not_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "not_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, not_expr, "expr_not_expr");
													}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 260 "psdhd.y"
    {
														struct node *eq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "eq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, eq_expr, "expr_eq_expr");
													}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 264 "psdhd.y"
    {
														struct node *diff_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "diff_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, diff_expr, "expr_diff_expr");
													}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 268 "psdhd.y"
    {
														struct node *sup_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "sup_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, sup_expr, "expr_sup_expr");
													}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 272 "psdhd.y"
    {
														struct node *supeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "supeq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, supeq_expr, "expr_supeq_expr");
													}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 276 "psdhd.y"
    {
														struct node *inf_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "inf_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, inf_expr, "expr_inf_expr");
													}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 280 "psdhd.y"
    {
														struct node *infeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "infeq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, infeq_expr, "expr_infeq_expr");
													}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 284 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 285 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 290 "psdhd.y"
    {(yyval.str) = yylval.str;addSymbol("Function",(yyvsp[(7) - (8)].node_object).name,(yyvsp[(2) - (8)].node_object).name);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 292 "psdhd.y"
    { 
					struct node *start_stat = createNode((yyvsp[(10) - (14)].node_object).node, (yyvsp[(12) - (14)].node_object).node, "start_stat");
					struct node *start_stat_end = createNode(start_stat, (yyvsp[(14) - (14)].node_object).node, "start_stat_end");
					struct node *id_arg = createNode((yyvsp[(2) - (14)].node_object).node, (yyvsp[(4) - (14)].node_object).node, "id_arg");
					struct node *id_arg_type = createNode(id_arg, (yyvsp[(7) - (14)].node_object).node, "id_arg_type");
					struct node *fct_id_arg_type = createNode((yyvsp[(1) - (14)].node_object).node, id_arg_type, "fct_id_arg_type");
					(yyval.node_object).node = createNode(fct_id_arg_type, start_stat_end, "function_declaration");
				}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 302 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 306 "psdhd.y"
    { 
																struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "type_id");
																(yyval.node_object).node = createNode(type_id, (yyvsp[(4) - (4)].node_object).node, "arg_type_id_value");
															}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 310 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "arg_type_id"); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 311 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "argdecl_argdecl"); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 315 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(3) - (4)].node_object).node, "function_call"); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 319 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 323 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 324 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "arg_list"); }
    break;



/* Line 1455 of yacc.c  */
#line 2111 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 327 "psdhd.y"

/*** C Code section ***/

int main(int argc, char const *argv[]) {
	printf("salut, le yyparse passe pas");
	yyparse();
	printf("\n\n");
	int i=0;
	printf("salut2");

	
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s : %s (%s) defined in line %d\n",sym[i].type ,sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
	}
	
	printf("---------- PARSING TREE ----------\n");
	printTree(root);
	
	printf("\n\n");
	printf("Program Valid");
	return 0;
}

void yyerror(char *errormsg)
{
	printf("salut3");
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}

void addSymbol(char* type, char* variable_type, char* name) {
	query=searchSymbol(name);
	if(query==0) {
		sym[count].id_name=strdup(name);
		sym[count].returnType=strdup(variable_type);
		sym[count].lineNumber=countn;
		sym[count].type=strdup(type);   
		count++; 
	}
	else
	{
		char* str = "syntax error : Identifier already defined";
		yyerror(str);
	}
}

int searchSymbol(char *name) { 
    int i; 
    for(i=count-1; i>=0; i--) {
        if(strcmp(sym[i].id_name, name)==0) {   
            return -1;
            break;  
        }
    } 
    return 0;
}

struct node* createNode(struct node *left, struct node *right, char *token) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	char *newstr = (char*) malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printTree(struct node *tree) {
    int i; 
    if (tree->left) {
        printTree(tree->left); 
    } 
    printf("%s, ", tree->token); 
    if (tree->right) {  
        printTree(tree->right); 
    }
}
