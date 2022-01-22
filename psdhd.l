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
	


{character}	{strcpy(yylval.node_object.name,(yytext)); return(CHARACTER);}	
{string}	{strcpy(yylval.node_object.name,(yytext)); return(STRING);}	

{number}	{strcpy(yylval.node_object.name,(yytext)); return(NUMBER);}		

{int-type}		{strcpy(yylval.node_object.name,(yytext)); return(INT_TYPE);}		
{real-type}		{strcpy(yylval.node_object.name,(yytext)); return(REAL_TYPE);}
{boolean-type}	{strcpy(yylval.node_object.name,(yytext)); return(BOOLEAN_TYPE);}
{char-type}		{strcpy(yylval.node_object.name,(yytext)); return(CHAR_TYPE);}
{string-type}	{strcpy(yylval.node_object.name,(yytext)); return(STRING_TYPE);}
{void-type}		{strcpy(yylval.node_object.name,(yytext)); return(VOID_TYPE);}

{true}		{strcpy(yylval.node_object.name,(yytext)); return(TRUE);}
{false}		{strcpy(yylval.node_object.name,(yytext)); return(FALSE);}


{addition-operator}			{strcpy(yylval.node_object.name,(yytext)); return(ADDITION_OPERATOR);}	
{substraction-operator}		{strcpy(yylval.node_object.name,(yytext)); return(SUBSTRACTION_OPERATOR);}	
{multiplication-operator}	{strcpy(yylval.node_object.name,(yytext)); return(MULTIPLICATION_OPERATOR);}	
{division-operator}			{strcpy(yylval.node_object.name,(yytext)); return(DIVISION_OPERATOR);}	

{equal-operator}			{strcpy(yylval.node_object.name,(yytext)); return(EQ_OPERATOR);}	
{different-operator}		{strcpy(yylval.node_object.name,(yytext)); return(DIFF_OPERATOR);}	
{inferior-operator}			{strcpy(yylval.node_object.name,(yytext)); return(INF_OPERATOR);}	
{inferior-equal-operator}	{strcpy(yylval.node_object.name,(yytext)); return(INFEQ_OPERATOR);}	
{superior-operator}			{strcpy(yylval.node_object.name,(yytext)); return(SUP_OPERATOR);}	
{superior-equal-operator}	{strcpy(yylval.node_object.name,(yytext)); return(SUPEQ_OPERATOR);}	
{and-operator}				{strcpy(yylval.node_object.name,(yytext)); return(AND_OPERATOR);}	
{or-operator}				{strcpy(yylval.node_object.name,(yytext)); return(OR_OPERATOR);}	
{not-operator}				{strcpy(yylval.node_object.name,(yytext)); return(NOT_OPERATOR);}	

{mathematical-function}		{strcpy(yylval.node_object.name,(yytext)); return(MATHEMATICAL_FUNCTION);}	

{function}	{strcpy(yylval.node_object.name,(yytext)); return(FUNCTION);}		
{start} 	{strcpy(yylval.node_object.name,(yytext)); return(START);}		
{end}		{strcpy(yylval.node_object.name,(yytext)); return(END);}	
{return}	{strcpy(yylval.node_object.name,(yytext)); return(RETURN);}		
{if}		{strcpy(yylval.node_object.name,(yytext)); return(IF);}		
{then}		{strcpy(yylval.node_object.name,(yytext)); return(THEN);}		
{else}		{strcpy(yylval.node_object.name,(yytext)); return(ELSE);}		
{while}		{strcpy(yylval.node_object.name,(yytext)); return(WHILE);}		
{do}		{strcpy(yylval.node_object.name,(yytext)); return(DO);}		
{read}		{strcpy(yylval.node_object.name,(yytext)); return(READ);}		
{write}		{strcpy(yylval.node_object.name,(yytext)); return(WRITE);}			

{identifier}	{strcpy(yylval.node_object.name,(yytext)); return(IDENTIFIER);}

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