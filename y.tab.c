
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

#define COUNTPRINTTREE 10

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
void printTree(struct node *tree, int space);



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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

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
      21,    23,    25,    27,    29,    31,    33,    38,    41,    43,
      45,    47,    49,    51,    55,    67,    75,    83,    90,    97,
     102,   105,   109,   113,   117,   121,   125,   127,   129,   131,
     133,   135,   137,   139,   141,   145,   149,   153,   157,   161,
     165,   169,   173,   177,   179,   181,   182,   197,   199,   204,
     207,   211,   216,   218,   220
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    41,    49,
      -1,    51,    -1,    53,    -1,    54,    -1,    55,    -1,    56,
      -1,    58,    -1,    57,    -1,    63,    -1,    67,    -1,    59,
      -1,    29,    -1,    52,    50,    42,    60,    -1,    52,    50,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,
      -1,    50,    42,    60,    -1,    31,    62,    32,    41,    48,
      41,    33,    41,    48,    41,    35,    -1,    31,    62,    32,
      41,    48,    41,    35,    -1,    37,    62,    38,    41,    48,
      41,    35,    -1,    38,    41,    48,    41,    37,    62,    -1,
      39,    43,     4,    27,    50,    44,    -1,    40,    43,    60,
      44,    -1,    36,    60,    -1,    60,    12,    60,    -1,    60,
      13,    60,    -1,    60,    14,    60,    -1,    60,    15,    60,
      -1,    43,    60,    44,    -1,    67,    -1,    61,    -1,     5,
      -1,     4,    -1,     3,    -1,    25,    -1,    26,    -1,    50,
      -1,    60,    16,    60,    -1,    60,    17,    60,    -1,    60,
      18,    60,    -1,    60,    23,    60,    -1,    60,    24,    60,
      -1,    60,    21,    60,    -1,    60,    22,    60,    -1,    60,
      19,    60,    -1,    60,    20,    60,    -1,    25,    -1,    26,
      -1,    -1,    30,    50,    43,    65,    44,    45,    52,    41,
      64,    34,    41,    48,    41,    35,    -1,    66,    -1,    52,
      50,    42,    61,    -1,    52,    50,    -1,    66,    27,    66,
      -1,    50,    43,    68,    44,    -1,    69,    -1,    60,    -1,
      69,    27,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,   106,   107,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   126,   130,   135,   142,   143,
     144,   145,   146,   150,   155,   165,   176,   187,   197,   206,
     210,   215,   220,   225,   230,   235,   236,   237,   242,   243,
     244,   245,   246,   247,   252,   256,   260,   264,   268,   272,
     276,   280,   284,   288,   289,   294,   294,   306,   310,   314,
     315,   319,   323,   327,   328
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
  "statement_list", "statement", "identifier", "declaration_statement",
  "variable_type", "assignement_statement", "if_statement",
  "while_statement", "do_while_statement", "read_statement",
  "write_statement", "return_statement", "expression", "value",
  "condition", "function_declaration", "@1", "argument_declaration_list",
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
      49,    49,    49,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    53,    54,    54,    55,    56,    57,    58,
      59,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    64,    63,    65,    66,    66,
      66,    67,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     1,     1,
       1,     1,     1,     3,    11,     7,     7,     6,     6,     4,
       2,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     0,    14,     1,     4,     2,
       3,     4,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,    21,    22,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     5,     0,
       6,     7,     8,     9,    11,    10,    14,    12,    13,     0,
      40,    39,    38,    41,    42,     0,    43,     0,    37,     0,
      36,    41,    42,    30,     0,     0,     0,     0,     1,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,    23,    63,     0,    62,     0,     0,
       0,    57,    35,    31,    32,    33,    34,    44,    45,    46,
      51,    52,    49,    50,    47,    48,     0,     0,     0,     0,
      29,    61,     0,    16,    59,     0,     0,     0,     0,     0,
       0,    64,     0,     0,    60,     0,     0,    27,    28,    43,
      58,     0,     0,    25,    26,    55,     0,     0,     0,     0,
       0,     0,    24,     0,     0,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    36,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    37,    38,    39,    27,   127,    80,
      81,    40,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
     240,   -41,   -41,   -41,   -41,   -41,   -41,   -13,    84,   120,
      84,   -24,   -19,   -18,    37,    31,   -41,   -39,   -41,   -13,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,    -2,
     -41,   -41,   -41,     2,    42,   120,     1,   281,   -41,    41,
     -41,   -41,   -41,    -4,    38,   240,    73,   120,   -41,   240,
     120,   120,    40,    21,     8,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,    43,    44,
      49,    67,   146,   -41,    -4,    -4,    51,    74,   120,   -13,
      62,    81,   -41,    33,    18,    99,   -41,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,   240,   240,   252,   -13,
     -41,   -41,   120,    -4,    75,    83,    21,    77,    78,    84,
      76,   -41,    10,    21,   -41,   144,   158,    38,   -41,   -41,
     -41,    88,    92,   -41,   -41,   -41,   240,   101,    97,    98,
     193,   240,   -41,   100,   205,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -40,   -23,     0,   -41,   -35,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,     3,    30,    -9,   -41,   -41,   -41,
      50,     6,   -41,    45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      17,    44,   -53,    50,    51,    70,    28,    29,    55,    56,
      57,    58,    43,    30,    31,    32,     6,    45,    79,    52,
      55,    56,    57,    58,    46,    47,    73,     1,     2,     3,
       4,     5,    57,    58,   -53,    41,    42,    48,    54,     6,
     -53,    53,   -54,   -53,    51,    17,    56,    57,    58,    17,
      72,    28,    82,    74,    75,    28,   107,   108,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    79,    49,    68,   -54,    73,    69,    71,   121,   104,
     -54,   103,    78,   -54,    96,    97,   128,    30,    31,    32,
      98,   133,    73,    73,    99,   101,    17,    17,    17,   110,
     117,   102,    28,    28,    28,    75,   105,    73,   106,    33,
      34,    73,   119,     6,    58,    17,    17,   112,   115,   116,
     118,    28,    28,    30,    31,    32,    17,    35,   113,   125,
      17,    17,    28,   126,    17,   129,    28,    28,   130,   131,
      28,   134,   120,     0,     0,    41,    42,   111,     0,     6,
       1,     2,     3,     4,     5,     0,   114,     0,    55,    56,
      57,    58,     0,    35,     1,     2,     3,     4,     5,     0,
       0,     0,     0,     6,     7,     8,     0,   122,     0,   123,
       9,    10,    11,    12,    13,     0,     0,     6,     7,     8,
     100,     0,     0,   124,     9,    10,    11,    12,    13,     1,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     0,     0,     0,   132,     9,
      10,    11,    12,    13,     6,     7,     8,     0,     0,     0,
     135,     9,    10,    11,    12,    13,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     0,     0,     0,     0,     9,    10,    11,    12,
      13,     6,     7,     8,     0,     0,     0,     0,     9,   109,
      11,    12,    13,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67
};

static const yytype_int16 yycheck[] =
{
       0,    10,     0,    42,    43,    45,     0,     7,    12,    13,
      14,    15,     9,     3,     4,     5,    29,    41,    53,    19,
      12,    13,    14,    15,    43,    43,    49,     6,     7,     8,
       9,    10,    14,    15,    32,    25,    26,     0,    35,    29,
      38,    43,     0,    41,    43,    45,    13,    14,    15,    49,
      47,    45,    44,    50,    51,    49,    96,    97,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   106,    41,    32,    32,    98,    38,     4,   113,    79,
      38,    78,    42,    41,    41,    41,   126,     3,     4,     5,
      41,   131,   115,   116,    27,    44,    96,    97,    98,    99,
     109,    27,    96,    97,    98,   102,    44,   130,    27,    25,
      26,   134,   112,    29,    15,   115,   116,    42,    41,    41,
      44,   115,   116,     3,     4,     5,   126,    43,    45,    41,
     130,   131,   126,    41,   134,    34,   130,   131,    41,    41,
     134,    41,   112,    -1,    -1,    25,    26,   102,    -1,    29,
       6,     7,     8,     9,    10,    -1,   106,    -1,    12,    13,
      14,    15,    -1,    43,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    39,    40,    -1,    -1,    29,    30,    31,
      44,    -1,    -1,    35,    36,    37,    38,    39,    40,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    29,    30,    31,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    29,    30,    31,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    29,    30,    31,    36,
      37,    38,    39,    40,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    63,    67,    50,
       3,     4,     5,    25,    26,    43,    50,    60,    61,    62,
      67,    25,    26,    60,    62,    41,    43,    43,     0,    41,
      42,    43,    50,    43,    60,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    32,    38,
      48,     4,    60,    49,    60,    60,    68,    69,    42,    52,
      65,    66,    44,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    41,    41,    41,    27,
      44,    44,    27,    60,    50,    44,    27,    48,    48,    37,
      50,    69,    42,    45,    66,    41,    41,    62,    44,    50,
      61,    52,    33,    35,    35,    41,    41,    64,    48,    34,
      41,    41,    35,    48,    41,    35
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
#line 98 "psdhd.y"
    { 
							(yyval.node_object).node = createNode((yyvsp[(1) - (1)].node_object).node, NULL, "program"); 
							root = (yyval.node_object).node;
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 106 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 107 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "statement_list"); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 113 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 114 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 115 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 116 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 117 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 118 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 119 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 120 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 121 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 122 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 126 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyval.node_object).name); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 130 "psdhd.y"
    { 
														addSymbol("Variable", (yyvsp[(1) - (4)].node_object).node->token, (yyvsp[(2) - (4)].node_object).name);
														struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "decl_without_assign");
														(yyval.node_object).node = createNode(type_id, (yyvsp[(4) - (4)].node_object).node, "decl_with_assign");
													}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 135 "psdhd.y"
    {
														addSymbol("Variable", (yyvsp[(1) - (2)].node_object).node->token, (yyvsp[(2) - (2)].node_object).name);
														(yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "decl_without_assign");
													}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 142 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 143 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 144 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 146 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 150 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "assignement_statement"); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 156 "psdhd.y"
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

  case 25:

/* Line 1455 of yacc.c  */
#line 166 "psdhd.y"
    { 
				struct node *then_stat = createNode((yyvsp[(3) - (7)].node_object).node, (yyvsp[(5) - (7)].node_object).node, "then_stat");
				struct node *cond_then_stat = createNode((yyvsp[(2) - (7)].node_object).node, then_stat, "cond_then_stat");
				struct node *if_cond_then_stat = createNode((yyvsp[(1) - (7)].node_object).node, cond_then_stat, "if_cond_then_stat");
				struct node *if_cond_then_stat_end = createNode(if_cond_then_stat, (yyvsp[(7) - (7)].node_object).node, "if_statement");
				(yyval.node_object).node = if_cond_then_stat_end;
			}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 177 "psdhd.y"
    { 
				struct node *while_cond = createNode((yyvsp[(1) - (7)].node_object).node, (yyvsp[(2) - (7)].node_object).node, "while_cond");
				struct node *do_stat = createNode((yyvsp[(3) - (7)].node_object).node, (yyvsp[(5) - (7)].node_object).node, "do_stat");
				struct node *while_cond_do_stat = createNode(while_cond, do_stat, "while_cond_do_stat");
				struct node *while_cond_do_stat_end = createNode(while_cond_do_stat, (yyvsp[(7) - (7)].node_object).node, "while_statement");
				(yyval.node_object).node = while_cond_do_stat_end;
			}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 188 "psdhd.y"
    { 
				struct node *do_stat = createNode((yyvsp[(1) - (6)].node_object).node, (yyvsp[(3) - (6)].node_object).node, "do_stat");
				struct node *while_cond = createNode((yyvsp[(5) - (6)].node_object).node, (yyvsp[(6) - (6)].node_object).node, "while_cond");
				struct node *do_stat_while_cond = createNode(do_stat, while_cond, "do_while_statement");
				(yyval.node_object).node = do_stat_while_cond;
			}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 198 "psdhd.y"
    { 
				struct node *str_id = createNode((yyvsp[(3) - (6)].node_object).node, (yyvsp[(5) - (6)].node_object).node, "str_id");
				struct node *read_str_id = createNode((yyvsp[(1) - (6)].node_object).node, str_id, "read_statement");
				(yyval.node_object).node = read_str_id;
			}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(3) - (4)].node_object).node, "write_statement"); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 210 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "return_statement"); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 215 "psdhd.y"
    {
																 
																struct node *plus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "plus_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, plus_expr, "expr_plus_expr");
															}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 220 "psdhd.y"
    {
																 
																struct node *minus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "minus_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, minus_expr, "expr_minus_expr");
															}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 225 "psdhd.y"
    {
																 
																struct node *mult_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "mult_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, mult_expr, "expr_mult_expr");
															}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 230 "psdhd.y"
    {
																 
																struct node *div_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "div_expr");
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, div_expr, "expr_div_expr");
															}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 235 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(2) - (3)].node_object).node; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 236 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 237 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 242 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 243 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 244 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 245 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 246 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 247 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 252 "psdhd.y"
    {
														struct node *and_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "and_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, and_expr, "expr_and_expr");
													}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 256 "psdhd.y"
    {
														struct node *or_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "or_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, or_expr, "expr_or_expr");
													}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 260 "psdhd.y"
    {
														struct node *not_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "not_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, not_expr, "expr_not_expr");
													}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 264 "psdhd.y"
    {
														struct node *eq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "eq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, eq_expr, "expr_eq_expr");
													}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 268 "psdhd.y"
    {
														struct node *diff_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "diff_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, diff_expr, "expr_diff_expr");
													}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 272 "psdhd.y"
    {
														struct node *sup_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "sup_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, sup_expr, "expr_sup_expr");
													}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 276 "psdhd.y"
    {
														struct node *supeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "supeq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, supeq_expr, "expr_supeq_expr");
													}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 280 "psdhd.y"
    {
														struct node *inf_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "inf_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, inf_expr, "expr_inf_expr");
													}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 284 "psdhd.y"
    {
														struct node *infeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "infeq_expr");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, infeq_expr, "expr_infeq_expr");
													}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 288 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 289 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 294 "psdhd.y"
    {(yyval.str) = (yyvsp[(1) - (8)].node_object).name;addSymbol("Function",(yyvsp[(7) - (8)].node_object).node->token,(yyvsp[(2) - (8)].node_object).name);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 296 "psdhd.y"
    { 
					struct node *start_stat = createNode((yyvsp[(10) - (14)].node_object).node, (yyvsp[(12) - (14)].node_object).node, "start_stat");
					struct node *start_stat_end = createNode(start_stat, (yyvsp[(14) - (14)].node_object).node, "start_stat_end");
					struct node *id_arg = createNode((yyvsp[(2) - (14)].node_object).node, (yyvsp[(4) - (14)].node_object).node, "id_arg");
					struct node *id_arg_type = createNode(id_arg, (yyvsp[(7) - (14)].node_object).node, "id_arg_type");
					struct node *fct_id_arg_type = createNode((yyvsp[(1) - (14)].node_object).node, id_arg_type, "fct_id_arg_type");
					(yyval.node_object).node = createNode(fct_id_arg_type, start_stat_end, "function_declaration");
				}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 306 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 310 "psdhd.y"
    { 
																struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "type_id");
																(yyval.node_object).node = createNode(type_id, (yyvsp[(4) - (4)].node_object).node, "arg_type_id_value");
															}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 314 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "arg_type_id"); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 315 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "argdecl_argdecl"); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 319 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(3) - (4)].node_object).node, "function_call"); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 323 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 327 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 328 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "arg_list"); }
    break;



/* Line 1455 of yacc.c  */
#line 2128 "y.tab.c"
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
#line 331 "psdhd.y"

/*** C Code section ***/

int main(int argc, char const *argv[]) {
	yyparse();
	int i=0;

	printf("\n");
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s : %s (%s) defined in line %d\n",sym[i].type ,sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
	}
	
	printf("\n");
	printf("---------- PARSING TREE ----------\n");
	printTree(root, 0);
	
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

void printTree(struct node *tree, int space) {
   /* int i; 
    if (tree->left) {
        printTree(tree->left); 
    } 
    printf("%s, ", tree->token); 
    if (tree->right) {  
        printTree(tree->right); 
    }*/

	if (tree == NULL)
        return;
 
    // Increase distance between levels
    space += COUNTPRINTTREE;
 
    // Process right child first
    printTree(tree->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNTPRINTTREE; i < space; i++)
        printf(" ");
    printf("%s\n", tree->token);
 
    // Process left child
    printTree(tree->left, space);
}
