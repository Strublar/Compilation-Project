
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 46 "psdhd.y"

    char *str;
	struct var_name {
	   char name[100];
	   struct node* node;
	   char type[5];
	} node_object;




/* Line 1676 of yacc.c  */
#line 142 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


