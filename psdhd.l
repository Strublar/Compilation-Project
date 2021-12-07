/*** Definition section ***/

%{
#include <stdio.h>
%}

/* This tells flex to read only one input file */
%option noyywrap

space [ \t]
letter [a-zA-Z]
digit [0-9]
digits {digit}+

character "'"[^’]"'"
string \"(\\.|[^"\\])*\"
number [-]?{digits}("."{digits})?("E"[+-]?{digits})?
identifier {letter}({letter}|{digit}|"_")*
variable-type int|real|boolean|char|string
boolean TRUE|FALSE
comparator-operator =|<|>|<=|>=|AND|OR|NOT
arithmetic-operator  "+"|"-"|"*"|"/"|"%"
mathematical-function abs|exp|log|min|max|pow|sqrt


%%
    /*** Rules section ***/

	

{character}	{printf("Saw  : %s",yytext);}	
.|\n    {   /* Ignore all other characters. */   }

%%
/*** C Code section ***/

int main(void)
{
    /* Call the lexer, then quit. */
    yylex();
    return 0;
}