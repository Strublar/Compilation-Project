/*** Definition section ***/

%{
#include <stdio.h>
%}

/* This tells flex to read only one input file */
%option noyywrap

space [ \t]
spaces {space}+
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

	

{character}	{printf("\nSaw a character : %s\n",yytext);}	
{string}	{printf("\nSaw a string : %s\n",yytext);}	

{number}	{printf("\nSaw a number : %s\n",yytext);}	

{variable-type}		{printf("\nSaw a variable-type : %s\n",yytext);}	
{boolean}		{printf("\nSaw a boolean : %s\n",yytext);}	
{comparator-operator}	{printf("\nSaw a comparator-operator : %s\n",yytext);}	
{arithmetic-operator}	{printf("\nSaw a arithmetic-operator : %s\n",yytext);}	
{mathematical-function}		{printf("\nSaw a mathematical-function : %s\n",yytext);}

{identifier}	{printf("\nSaw a identifier : %s\n",yytext);}		

.|\n    {   /* Ignore all other characters. */   }

%%
/*** C Code section ***/

int main(int argc, char* argv[])
{
    if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yylex();
	return 1;
}