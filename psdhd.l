/*** Definition section ***/

%{
#include "y.tab.h"
#include <string.h>

int yyerror(char *errormsg);

int countn =0;

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


int-type 	int
real-type	float
boolean-type	boolean
char-type		char
string-type		string
void-type		void

true TRUE
false FALSE

addition-operator "+"
substraction-operator "-"
multiplication-operator "*"
division-operator "/"


equal-operator ==
different-operator !=
inferior-operator <
inferior-equal-operator <=
superior-operator >
superior-equal-operator >=
and-operator	AND
or-operator		OR
not-operator	NOT


mathematical-function abs|exp|log|min|max|pow|sqrt

function 	function
start	begin
end		end
return	return
if		if
then	then
else	else
while	while
do		do
read	read
write	write

%%
    /*** Rules section ***/
	
	
{character}	{return(CHARACTER);}	
{string}	{return(STRING);}	

{number}	{return(NUMBER);}		

{int-type}		{yylval.str = strdup(yytext);return(INT_TYPE);}		
{real-type}		{yylval.str = strdup(yytext);return(REAL_TYPE);}
{boolean-type}		{yylval.str = strdup(yytext);return(BOOLEAN_TYPE);}
{char-type}		{yylval.str = strdup(yytext);return(CHAR_TYPE);}
{string-type}		{yylval.str = strdup(yytext);return(STRING_TYPE);}
{void-type}		{yylval.str = strdup(yytext);return(VOID_TYPE);}

{true}		{return(TRUE);}
{false}		{return(FALSE);}


{addition-operator}			{return(ADDITION_OPERATOR);}	
{substraction-operator}		{return(SUBSTRACTION_OPERATOR);}	
{multiplication-operator}	{return(MULTIPLICATION_OPERATOR);}	
{division-operator}			{return(DIVISION_OPERATOR);}	

{equal-operator}			{return(EQ_OPERATOR);}	
{different-operator}		{return(DIFF_OPERATOR);}	
{inferior-operator}			{return(INF_OPERATOR);}	
{inferior-equal-operator}	{return(INFEQ_OPERATOR);}	
{superior-operator}			{return(SUP_OPERATOR);}	
{superior-equal-operator}	{return(SUPEQ_OPERATOR);}	
{and-operator}				{return(AND_OPERATOR);}	
{or-operator}				{return(OR_OPERATOR);}	
{not-operator}				{return(NOT_OPERATOR);}	

{mathematical-function}		{return(MATHEMATICAL_FUNCTION);}	


{function}	{return(FUNCTION);}		
{start} {return(START);}		
{end}	{return(END);}	
{return}	{return(RETURN);}		
{if}	{return(IF);}		
{then}	{return(THEN);}		
{else}	{return(ELSE);}		
{while}	{return(WHILE);}		
{do}	{return(DO);}		
{read}	{return(READ);}		
{write}	{return(WRITE);}			

{identifier}	{yylval.str = strdup(yytext);return(IDENTIFIER);}


\/\/.*	{ ; }
\/\*(.*\n)*.*\*\/	{ ; } 
[ \t]*	{ ; }

[\n]    {   countn++; return *yytext;   }
.		{   return *yytext;   }
%%
/*** C Code section ***/

/*int main(int argc, char const *argv[]) {
  yyin = fopen(argv[1], "r");
  int result_code = yyparse();
  fclose(yyin);
  printf("\nProgram valid\n");
  return result_code;
}

int yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}
*/