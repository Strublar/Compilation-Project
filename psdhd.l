/*** Definition section ***/

%{
#include "y.tab.h"
#include <stdio.h>
%}

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
comparator-operator ==|<|>|<=|>=|AND|OR|NOT
arithmetic-operator  "+"|"-"|"*"|"/"|"%"
mathematical-function abs|exp|log|min|max|pow|sqrt


%%
    /*** Rules section ***/
	
	
{character}	{return(CHARACTER);}	
{string}	{return(STRING);}	

{number}	{return(NUMBER);}		

{variable-type}		{return(VARIABLE_TYPE);}		
{boolean}		{return(BOOLEAN);}	
{comparator-operator}	{return(COMPARATOR_OPERATOR);}	
{arithmetic-operator}	{return(ARITHMETIC_OPERATOR);}	
{mathematical-function}		{return(MATHEMATICAL_FUNCTION);}	

{identifier}	{return(IDENTIFIER);}		

\/\/.*	{ ; }
\/\*(.*\n)*.*\*\/	{ ; } 
[ \t]*	{ ; }
.|\n    {   return *yytext;   }

%%
/*** C Code section ***/

