
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

#define COUNTPRINTTREE 5

void yyerror(char *errormsg);
int yylex();

void insert_type();
void addSymbol(char* type, char* variable_type, char* name);
int searchSymbol(char *name);
int count = 0;
int query;
extern int countn;
char *check_types(char *type1, char *type2);
char *get_type(char *var);
void endScope();
void removeFromArray(int index);

struct symData {
        char * id_name;
        char * returnType;
        char * type;
        int lineNumber;
		int scope;
} sym[64];

struct node {
  struct node *left;
  struct node *right;
  char *token;     
};

int scope = 0;

struct node *root;
struct node* createNode(struct node *left, struct node *right, char *token);
void printTree(struct node *tree, int space);
char* printCpp(struct node *tree, int space);
char *addIndent(int indent);
void check_declaration(char *name);
int error_index = 0;
char errors[10][100];
char reserved[11][10] = {"function", "start", "end", "return", "if", "then", "else", "while", "do", "read", "write"};



/* Line 189 of yacc.c  */
#line 124 "y.tab.c"

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
     INT_TYPE = 260,
     REAL_TYPE = 261,
     BOOLEAN_TYPE = 262,
     CHAR_TYPE = 263,
     STRING_TYPE = 264,
     VOID_TYPE = 265,
     ADDITION_OPERATOR = 266,
     SUBSTRACTION_OPERATOR = 267,
     MULTIPLICATION_OPERATOR = 268,
     DIVISION_OPERATOR = 269,
     NUMBER = 270,
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
#define INT_TYPE 260
#define REAL_TYPE 261
#define BOOLEAN_TYPE 262
#define CHAR_TYPE 263
#define STRING_TYPE 264
#define VOID_TYPE 265
#define ADDITION_OPERATOR 266
#define SUBSTRACTION_OPERATOR 267
#define MULTIPLICATION_OPERATOR 268
#define DIVISION_OPERATOR 269
#define NUMBER 270
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
#line 50 "psdhd.y"

    char *str;
	struct var_name {
	   char name[100];
	   struct node* node;
	   char type[5];
	} node_object;




/* Line 214 of yacc.c  */
#line 250 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 262 "y.tab.c"

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
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

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
       0,     0,     3,     5,     7,    11,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    37,    40,    42,
      44,    46,    48,    50,    54,    55,    65,    66,    71,    72,
      81,    82,    90,    97,   102,   105,   109,   113,   117,   121,
     125,   127,   129,   131,   133,   135,   137,   139,   141,   145,
     149,   153,   157,   161,   165,   169,   173,   177,   179,   181,
     182,   197,   198,   200,   205,   208,   212,   217,   219,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    -1,    48,    41,    49,
      -1,    -1,    50,    -1,    52,    -1,    53,    -1,    56,    -1,
      58,    -1,    61,    -1,    60,    -1,    66,    -1,    70,    -1,
      62,    -1,    51,    29,    42,    63,    -1,    51,    29,    -1,
       5,    -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,
      29,    42,    63,    -1,    -1,    31,    54,    65,    32,    41,
      48,    41,    55,    35,    -1,    -1,    33,    41,    48,    41,
      -1,    -1,    37,    65,    57,    38,    41,    48,    41,    35,
      -1,    -1,    38,    59,    41,    48,    41,    37,    65,    -1,
      39,    43,     4,    27,    29,    44,    -1,    40,    43,    63,
      44,    -1,    36,    63,    -1,    63,    11,    63,    -1,    63,
      12,    63,    -1,    63,    13,    63,    -1,    63,    14,    63,
      -1,    43,    63,    44,    -1,    70,    -1,    64,    -1,    15,
      -1,     4,    -1,     3,    -1,    25,    -1,    26,    -1,    29,
      -1,    63,    16,    63,    -1,    63,    17,    63,    -1,    63,
      18,    63,    -1,    63,    23,    63,    -1,    63,    24,    63,
      -1,    63,    21,    63,    -1,    63,    22,    63,    -1,    63,
      19,    63,    -1,    63,    20,    63,    -1,    25,    -1,    26,
      -1,    -1,    30,    67,    29,    43,    68,    44,    45,    51,
      41,    34,    41,    48,    41,    35,    -1,    -1,    69,    -1,
      51,    29,    42,    64,    -1,    51,    29,    -1,    69,    27,
      69,    -1,    29,    43,    71,    44,    -1,    72,    -1,    63,
      -1,    72,    27,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   123,   124,   128,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   144,   158,   166,   167,
     168,   169,   170,   174,   190,   190,   198,   199,   204,   204,
     213,   213,   221,   232,   238,   245,   256,   267,   278,   289,
     292,   293,   298,   299,   300,   301,   302,   303,   309,   314,
     319,   324,   329,   334,   339,   344,   349,   354,   355,   360,
     360,   373,   374,   378,   383,   387,   391,   399,   403,   404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHARACTER", "STRING", "INT_TYPE",
  "REAL_TYPE", "BOOLEAN_TYPE", "CHAR_TYPE", "STRING_TYPE", "VOID_TYPE",
  "ADDITION_OPERATOR", "SUBSTRACTION_OPERATOR", "MULTIPLICATION_OPERATOR",
  "DIVISION_OPERATOR", "NUMBER", "AND_OPERATOR", "OR_OPERATOR",
  "NOT_OPERATOR", "INF_OPERATOR", "INFEQ_OPERATOR", "SUP_OPERATOR",
  "SUPEQ_OPERATOR", "EQ_OPERATOR", "DIFF_OPERATOR", "TRUE", "FALSE", "','",
  "MATHEMATICAL_FUNCTION", "IDENTIFIER", "FUNCTION", "IF", "THEN", "ELSE",
  "START", "END", "RETURN", "WHILE", "DO", "READ", "WRITE", "'\\n'", "'='",
  "'('", "')'", "':'", "$accept", "program", "statement_list", "statement",
  "declaration_statement", "variable_type", "assignement_statement",
  "if_statement", "$@1", "else_statement", "while_statement", "$@2",
  "do_while_statement", "$@3", "read_statement", "write_statement",
  "return_statement", "expression", "value", "condition",
  "function_declaration", "$@4", "argument_declaration_list",
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
      49,    49,    49,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    52,    54,    53,    55,    55,    57,    56,
      59,    58,    60,    61,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    67,
      66,    68,    68,    69,    69,    69,    70,    71,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     1,     1,
       1,     1,     1,     3,     0,     9,     0,     4,     0,     8,
       0,     7,     6,     4,     2,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     0,
      14,     0,     1,     4,     2,     3,     4,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    18,    19,    20,    21,    22,     0,    59,    24,     0,
       0,    30,     0,     0,     0,     2,     3,     6,     0,     7,
       8,     9,    10,    12,    11,    15,    13,    14,     0,     0,
       0,     0,    44,    43,    42,    45,    46,    47,     0,    34,
      41,    40,    45,    46,     0,    28,     0,     0,     0,     1,
       5,    17,    23,    68,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     4,     0,    66,     0,
      61,     0,    39,    35,    36,    37,    38,    48,    49,    50,
      55,    56,    53,    54,    51,    52,     0,     0,     0,    33,
      16,    69,     0,     0,    62,     5,     5,     5,     0,    64,
       0,     0,     0,     0,     0,    32,     0,     0,    65,     5,
       5,    31,    47,    63,     0,     0,     0,    29,     0,     5,
      25,     0,     0,     5,     5,     0,     5,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    18,    19,    20,    31,   126,
      21,    72,    22,    46,    23,    24,    25,    44,    40,    45,
      26,    30,   103,   104,    41,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
     204,   -79,   -79,   -79,   -79,   -79,    20,   -79,   -79,     3,
       5,   -79,   -33,   -26,    19,    -6,   -79,   -79,    12,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,     3,     3,
      15,     5,   -79,   -79,   -79,   -79,   -79,     8,     3,   114,
     -79,   -79,     4,    11,   239,   -79,     6,    49,     3,   -79,
     204,    22,   114,   114,    24,    30,    23,    40,    10,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,    38,   204,    53,   110,   -79,     3,   -79,     3,
       7,    41,   -79,    13,    61,    69,   -79,   114,   114,   114,
     114,   114,   114,   114,   114,   114,    43,    47,    60,   -79,
     114,   -79,    74,    65,    77,   204,   204,   240,    67,    70,
      73,     7,    89,    90,     5,   -79,    52,     7,   -79,   108,
     144,    94,   -79,   -79,    99,   101,   100,   -79,   121,   204,
     -79,   115,   116,   204,   156,   117,   192,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -68,   -49,   -79,   -78,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,    31,    44,   -28,
     -79,   -79,   -79,    48,     0,   -79,    87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      27,    76,   102,    57,   -57,    97,    32,    33,    32,    33,
      47,   -58,     1,     2,     3,     4,     5,    48,    34,    49,
      34,    59,    60,    61,    62,    60,    61,    62,    35,    36,
      42,    43,    37,   102,    37,    50,   -57,   112,   113,   124,
      39,    51,   -57,   -58,    56,   -57,    38,    73,    38,   -58,
      27,    29,   -58,    74,    82,    32,    33,    79,    76,    52,
      53,   132,    28,    29,    77,   135,    80,    34,    78,    58,
      76,    76,    81,    27,    61,    62,    96,    35,    36,    75,
      98,   122,   105,    62,   106,    76,   121,    76,   107,   108,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   109,   111,    27,    27,    27,   100,   110,
      53,   115,   116,     1,     2,     3,     4,     5,   117,    27,
      27,    59,    60,    61,    62,    59,    60,    61,    62,    27,
     119,   120,   -28,    27,    27,   130,    27,     6,     7,     8,
     128,   125,   129,   -26,     9,    10,    11,    12,    13,     1,
       2,     3,     4,     5,    99,   131,   133,   134,   136,   118,
     123,     1,     2,     3,     4,     5,   101,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     0,     0,     0,   127,
       9,    10,    11,    12,    13,     6,     7,     8,     0,     0,
       0,   -27,     9,    10,    11,    12,    13,     1,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     0,     0,     0,   137,     9,    10,
      11,    12,    13,     6,     7,     8,     0,     0,     0,     0,
       9,    10,    11,    12,    13,     1,     2,     3,     4,     5,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,     6,
       7,     8,     0,     0,     0,     0,     9,   114,    11,    12,
      13
};

static const yytype_int16 yycheck[] =
{
       0,    50,    80,    31,     0,    73,     3,     4,     3,     4,
      43,     0,     5,     6,     7,     8,     9,    43,    15,     0,
      15,    11,    12,    13,    14,    12,    13,    14,    25,    26,
      25,    26,    29,   111,    29,    41,    32,   105,   106,   117,
       9,    29,    38,    32,    29,    41,    43,    41,    43,    38,
      50,    43,    41,     4,    44,     3,     4,    27,   107,    28,
      29,   129,    42,    43,    42,   133,    43,    15,    44,    38,
     119,   120,    32,    73,    13,    14,    38,    25,    26,    48,
      27,    29,    41,    14,    41,   134,   114,   136,    41,    29,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    29,    27,   105,   106,   107,    77,    44,
      79,    44,    42,     5,     6,     7,     8,     9,    45,   119,
     120,    11,    12,    13,    14,    11,    12,    13,    14,   129,
      41,    41,    38,   133,   134,    35,   136,    29,    30,    31,
      41,    33,    41,    35,    36,    37,    38,    39,    40,     5,
       6,     7,     8,     9,    44,    34,    41,    41,    41,   111,
     116,     5,     6,     7,     8,     9,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    29,    30,    31,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    29,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,     5,     6,     7,     8,     9,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    29,    30,    31,    36,
      37,    38,    39,    40,    47,    48,    49,    50,    51,    52,
      53,    56,    58,    60,    61,    62,    66,    70,    42,    43,
      67,    54,     3,     4,    15,    25,    26,    29,    43,    63,
      64,    70,    25,    26,    63,    65,    59,    43,    43,     0,
      41,    29,    63,    63,    71,    72,    29,    65,    63,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    57,    41,     4,    63,    49,    42,    44,    27,
      43,    32,    44,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    38,    48,    27,    44,
      63,    72,    51,    68,    69,    41,    41,    41,    29,    29,
      44,    27,    48,    48,    37,    44,    42,    45,    69,    41,
      41,    65,    29,    64,    51,    33,    55,    35,    41,    41,
      35,    34,    48,    41,    41,    48,    41,    35
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
#line 115 "psdhd.y"
    { 
							(yyval.node_object).node = createNode((yyvsp[(1) - (1)].node_object).node, NULL, "program"); 
							root = (yyval.node_object).node;
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 123 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 124 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "statement_list"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 130 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 132 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 133 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 134 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 136 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 137 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 138 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 139 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 144 "psdhd.y"
    { 
														printf("\ndécl %s, scope: %d", (yyvsp[(2) - (4)].node_object).name,scope);
														addSymbol("Variable", (yyvsp[(1) - (4)].node_object).node->token, (yyvsp[(2) - (4)].node_object).name);
														
														(yyvsp[(2) - (4)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (4)].node_object).name);
														struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "decl");
														(yyval.node_object).node = createNode(type_id, (yyvsp[(4) - (4)].node_object).node, "declaration_with_assign_statement");
														
														/*char *type_conversion = check_types($1.name, $4.type);
														if (type_conversion != NULL){
															struct node *type_conversion_node = createNode(NULL, $4.node, "type_conversion");
															$$.node = createNode(type_id, type_conversion_node, "declaration_with_assign_statement");
														}*/
													}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 158 "psdhd.y"
    {
														addSymbol("Variable", (yyvsp[(1) - (2)].node_object).node->token, (yyvsp[(2) - (2)].node_object).name);
														(yyvsp[(2) - (2)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (2)].node_object).name);
														(yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "declaration_without_assign_statement");
													}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 166 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 167 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 168 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 169 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 170 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 174 "psdhd.y"
    { 
										check_declaration((yyvsp[(1) - (3)].node_object).name);
										(yyvsp[(1) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (3)].node_object).name);
										(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "assignement_statement"); 
										
										/*char *var_type = get_type($1.name);
										char *type_conversion = check_types(var_type, $3.type);
										if (type_conversion != NULL){
											struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
											$$.node = createNode($1.node, type_conversion_node, "assignement_statement");
										}*/
									}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 190 "psdhd.y"
    { scope++; }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 192 "psdhd.y"
    { 
			(yyval.node_object).node = createNode(NULL, NULL, "if_statement");
			endScope();
		}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 204 "psdhd.y"
    { scope++; }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "psdhd.y"
    { 
				(yyval.node_object).node = createNode((yyvsp[(2) - (8)].node_object).node, (yyvsp[(6) - (8)].node_object).node, "while_statement");
				endScope();
			}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 213 "psdhd.y"
    { scope++; }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 214 "psdhd.y"
    { 
				(yyval.node_object).node = createNode((yyvsp[(4) - (7)].node_object).node, (yyvsp[(7) - (7)].node_object).node, "do_while_statement");
				endScope();
			}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 222 "psdhd.y"
    { 
				check_declaration((yyvsp[(5) - (6)].node_object).name);
				(yyvsp[(3) - (6)].node_object).node = createNode(NULL, NULL, (yyvsp[(3) - (6)].node_object).name);
				(yyvsp[(5) - (6)].node_object).node = createNode(NULL, NULL, (yyvsp[(5) - (6)].node_object).name);
				struct node *str_id = createNode((yyvsp[(3) - (6)].node_object).node, (yyvsp[(5) - (6)].node_object).node, "str_id");
				(yyval.node_object).node = createNode((yyvsp[(3) - (6)].node_object).node, (yyvsp[(5) - (6)].node_object).node, "read_statement");
			}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 232 "psdhd.y"
    { 
											(yyval.node_object).node = createNode((yyvsp[(3) - (4)].node_object).node, NULL, "write_statement");
										}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 238 "psdhd.y"
    { 
											(yyval.node_object).node = createNode((yyvsp[(2) - (2)].node_object).node,NULL, "return_statement"); 
										}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 245 "psdhd.y"
    {
																(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
																struct node *plus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	plus_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, plus_expr, "binary_token");
															}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 256 "psdhd.y"
    {
																(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
																struct node *minus_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	minus_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, minus_expr, "binary_token");
															}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 267 "psdhd.y"
    {
																(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
																struct node *mult_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	mult_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, mult_expr, "binary_token");
															}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 278 "psdhd.y"
    {
																(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
																struct node *div_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	div_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, div_expr, "binary_token");
															}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 289 "psdhd.y"
    { 	
																(yyval.node_object).node = createNode((yyvsp[(2) - (3)].node_object).node, NULL, "parenthesis_expression");
															}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 292 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 293 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 298 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 299 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 300 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 301 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 302 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 303 "psdhd.y"
    { check_declaration((yyvsp[(1) - (1)].node_object).name);
							  (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 309 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *and_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, and_expr, "binary_token");
													}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 314 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *or_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, or_expr, "binary_token");
													}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 319 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *not_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, not_expr, "binary_token");
													}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 324 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *eq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, eq_expr, "binary_token");
													}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 329 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *diff_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, diff_expr, "binary_token");
													}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 334 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *sup_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, sup_expr, "binary_token");
													}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 339 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *supeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, supeq_expr, "binary_token");
													}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 344 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *inf_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, inf_expr, "binary_token");
													}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 349 "psdhd.y"
    {
														(yyvsp[(2) - (3)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (3)].node_object).name);
														struct node *infeq_expr = createNode((yyvsp[(2) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "binary_token");
														(yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, infeq_expr, "binary_token");
													}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 354 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 355 "psdhd.y"
    { (yyval.node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (1)].node_object).name); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 360 "psdhd.y"
    { scope++; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 361 "psdhd.y"
    { 
																																addSymbol("Function",(yyvsp[(8) - (14)].node_object).node->token,(yyvsp[(3) - (14)].node_object).name);
																																(yyvsp[(3) - (14)].node_object).node = createNode(NULL, NULL, (yyvsp[(3) - (14)].node_object).name);
																																
																																struct node *id_ret = createNode((yyvsp[(8) - (14)].node_object).node, (yyvsp[(3) - (14)].node_object).node, "function_id_type");
																																struct node *arg_stat = createNode((yyvsp[(5) - (14)].node_object).node, (yyvsp[(12) - (14)].node_object).node, "function_args_statements");
																																(yyval.node_object).node = createNode(id_ret, arg_stat, "function_declaration");
																																
																																endScope();
																															}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 374 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 378 "psdhd.y"
    { 
																(yyvsp[(2) - (4)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (4)].node_object).name);
																struct node *type_id = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(2) - (4)].node_object).node, "type_id");
																(yyval.node_object).node = createNode(type_id, (yyvsp[(4) - (4)].node_object).node, "arg_type_id_value");
															}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 383 "psdhd.y"
    { 
																(yyvsp[(2) - (2)].node_object).node = createNode(NULL, NULL, (yyvsp[(2) - (2)].node_object).name);
																(yyval.node_object).node = createNode((yyvsp[(1) - (2)].node_object).node, (yyvsp[(2) - (2)].node_object).node, "arg_type_id"); 
															}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 387 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "argdecl_argdecl"); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 391 "psdhd.y"
    { 
												check_declaration((yyvsp[(1) - (4)].node_object).name);
												(yyvsp[(1) - (4)].node_object).node = createNode(NULL, NULL, (yyvsp[(1) - (4)].node_object).name);
												(yyval.node_object).node = createNode((yyvsp[(1) - (4)].node_object).node, (yyvsp[(3) - (4)].node_object).node, "function_call"); 
											}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 399 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 403 "psdhd.y"
    { (yyval.node_object).node = (yyvsp[(1) - (1)].node_object).node; }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 404 "psdhd.y"
    { (yyval.node_object).node = createNode((yyvsp[(1) - (3)].node_object).node, (yyvsp[(3) - (3)].node_object).node, "arg_list"); }
    break;



/* Line 1455 of yacc.c  */
#line 2202 "y.tab.c"
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
#line 407 "psdhd.y"

/*** C Code section ***/

int main(int argc, char const *argv[]) {
	yyparse();
	int i=0;

	printf("\n");
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s (scope %d): %s (%s) defined in line %d\n",sym[i].type , sym[i].scope, sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
		free(sym[i].scope);
	}
	
	printf("\n");
	printf("---------- PARSING TREE ----------\n");
	//printTree(root, 0);
	
	printf("\n\n");
	printf("---------- SEMANTIC ANALYSIS ----------\n");
	if(error_index > 0) {
		printf("%d error(s) encountered during the execution.\n", error_index);
		for(i = 0; i < error_index; i++){
			printf("       -> %s", errors[i]);
		}
	} else {
		printf("No error found.");
	}
	
	//printf("\nCPP TESTS\n");
	
	char* code = printCpp(root,0);
	int size = strlen(code);
	
	//printf("Size of code : %d\n",size);
	//printf(code);
	
	char* codeString = malloc(size);
	strcpy(codeString,code);

	FILE *codeGenerated = malloc(size);
	codeGenerated = fopen("Program.cpp","w");
	//fprintf(codeGenerated,codeString);
	fclose(codeGenerated);
	
	
	printf("\n\nProgram Valid");
	
	free(codeGenerated);
	free(codeString);
	
	return 0;
}

void yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}

void addSymbol(char* type, char* variable_type, char* name) {

	int i;
	for(i = 0; i < 11; i++) {   
		if(strcmp(reserved[i], strdup(name)) == 0) {
			sprintf(errors[error_index], "Line %d: Variable name \"%s\" is a reserved keyword.\n", countn + 1, name);
			error_index++;    
			return;
		}  
	} 
	query = searchSymbol(name);
	if(query==0) {
		sym[count].id_name=strdup(name);
		sym[count].returnType=strdup(variable_type);
		sym[count].lineNumber=countn;
		sym[count].type=strdup(type); 
		sym[count].scope=scope;   		
		count++; 
	}
	else
	{
		sprintf(errors[error_index], "Line %d: Variable \"%s\" already declared.\n", countn + 1, name);  
		error_index++;  
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
	int i;
    for (i = COUNTPRINTTREE; i < space; i++)
        printf(" ");
    printf("%s\n", tree->token);
 
    // Process left child
    printTree(tree->left, space);
}

void check_declaration(char *name) {
    query = searchSymbol(name);
    if(!query) { 
        sprintf(errors[error_index], "Line %d: Variable \"%s\" has not been declared.\n", countn + 1, name);  
        error_index++;    
    }
}

char *check_types(char *type1, char *type2) { 

    if(!strcmp(type2, "null"))
		return NULL; 
		
    if(!strcmp(type1, type2)) 
		return NULL; 

    if(!strcmp(type1, "int") && !strcmp(type2, "float")) 
		return "floattoint";
		
    if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return "inttofloat";
		
    if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return "chattoint";
		
    if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return "inttochar";
		
    if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return "chartofloat";
		
    if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return "floattochar";
}

char *get_type(char *var) {
	int i;
    for(i = 0; i < count; i++) {  
        if(!strcmp(sym[i].id_name, var)) {   
            return sym[i].type;  
        }
    }
}


char*  printCpp(struct node *tree, int space){
	if(!tree)
		return "";
		
	if(!strcmp(tree->token, "program"))
	{
		char code[1000] = "#include <iostream>\n#include <string>\nusing namespace std;\n\nint main()\n{\n";
		strcat(code, printCpp(tree->left,space+1));
		strcat(code, printCpp(tree->right,space+1));
		strcat(code,"\n\treturn 0;\n}");
		return code;
	}
	
	if(!strcmp(tree->token, "statement_list"))
	{
		char code[1000] = "";
		strcat(code, printCpp(tree->left,space));
		strcat(code, "\n");
		strcat(code, printCpp(tree->right,space));
		return code;
	}
	
	
	if(!strcmp(tree->token, "declaration_without_assign_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code,printCpp(tree->left,0));
		strcat(code," " );
		strcat(code, printCpp(tree->right,0));
		strcat(code, ";");
		return code;
	}
	
	
	
	if(!strcmp(tree->token, "declaration_with_assign_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, printCpp(tree->left,0));
		strcat(code, " = ");
		strcat(code, printCpp(tree->right,0));
		strcat(code,";");
		return code;
	}
	
	if(!strcmp(tree->token, "decl"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code,printCpp(tree->left,0));
		strcat(code," " );
		strcat(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "type_conversion"))
	{
		char code[1000] = "";
		strcat(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "assignement_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, printCpp(tree->left,0));
		strcat(code, " = ");
		strcat(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "binary_token"))
	{
		char code[1000] = "";
		strcat(code, printCpp(tree->left,0));
		strcat(code, " ");
		strcat(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "parenthesis_expression"))
	{
		char code[1000] = "(";
		strcat(code, printCpp(tree->left,0));
		strcat(code, ")");
		return code;
	}
	
	if(!strcmp(tree->token, "if_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "if (");
		strcat(code, printCpp(tree->left,0));
		strcat(code, ") \n");
		strcat(code,addIndent(space));
		strcat(code, "{\n");
		strcat(code,printCpp(tree->right,space+1));
		strcat(code, "\n");
		strcat(code,addIndent(space));
		strcat(code, "}");
		return code;
	}
	
	
	if(!strcmp(tree->token, "else_stat"))
	{
		char code[1000] = "";
		strcat(code, printCpp(tree->left,space));
		strcat(code, "\n");
		strcat(code,addIndent(space-1));
		strcat(code, "} else {\n");
		strcat(code,printCpp(tree->right,space));
		strcat(code, "\n");
		return code;
	}
	
	if(!strcmp(tree->token, "while_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "while (");
		strcat(code, printCpp(tree->left,0));
		strcat(code, ") \n");
		strcat(code,addIndent(space));
		strcat(code, "{\n");
		strcat(code,printCpp(tree->right,space+1));
		strcat(code, "\n");
		strcat(code,addIndent(space));
		strcat(code, "}");
		return code;
	}
	
	if(!strcmp(tree->token, "do_while_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "do {\n");
		strcat(code, printCpp(tree->left,space+1));
		strcat(code, "\n");
		strcat(code,addIndent(space));
		strcat(code, "} while (");
		strcat(code, printCpp(tree->right,0));
		strcat(code, ");\n");
		return code;
	}
	
	if(!strcmp(tree->token, "write_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "cout << ");
		strcat(code, printCpp(tree->left,0));
		strcat(code, "<< endl;\n");
		return code;
	}
	
	
	if(!strcmp(tree->token, "read_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "cout << ");
		strcat(code, printCpp(tree->left,0));
		strcat(code, "<< endl;\n");
		strcat(code,addIndent(space));
		strcat(code, "cin >> ");
		strcat(code, printCpp(tree->right,0));
		strcat(code, ";\n");
		return code;
	}
	
	if(!strcmp(tree->token, "function_declaration"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, printCpp(tree->left,space));
		strcat(code, printCpp(tree->right,space));
		return code;
	}
	
	if(!strcmp(tree->token, "function_id_type"))
	{
		char code[1000] = "";
		strcat(code, printCpp(tree->left,0));
		strcat(code, " ");
		strcat(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "function_args_statements"))
	{
		char code[1000] = "";
		strcat(code, "(");
		strcat(code, printCpp(tree->left,0));
		strcat(code, ")\n");
		strcat(code,addIndent(space));
		strcat(code, "{\n");
		strcat(code, printCpp(tree->right,space+1));
		strcat(code,addIndent(space));
		strcat(code, "}\n");
		return code;
	}
	
	
	if(!strcmp(tree->token, "return_statement"))
	{
		char code[1000] = "";
		strcat(code,addIndent(space));
		strcat(code, "return ");
		strcat(code, printCpp(tree->left,0));
		strcat(code, ";\n");
		return code;
	}
	
	
	
	
	//printf(processToken(tree->token));
	return tree->token;
}


char *addIndent(int indent)
{
	char string[1000] = "";
	int i;
	for(i=0;i<indent;i++)
	{
		strcat(string,"\t");
	}
	return string;		
}

void endScope(){

	for(int i=count-1; i>=0; i--) {
        if(sym[i].scope == scope) { 
			removeFromArray(i);
        }
    } 
	scope--;
}

void removeFromArray(int index){
	printf("deleting %s  ", sym[index].id_name);

	for(int i = index; i < count - 1; i++){
		sym[i] = sym[i + 1];
	}
	count--;
}
