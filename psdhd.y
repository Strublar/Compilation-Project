%{

#include <stdio.h>
#include <stdlib.h>

int yyerror(char *errormsg);
int yylex();

%}

%token CHARACTER 
%token STRING 
%token NUMBER 

%token INT_TYPE
%token REAL_TYPE
%token BOOLEAN_TYPE
%token CHAR_TYPE
%token STRING_TYPE
%token VOID_TYPE


%left ADDITION_OPERATOR 
%left SUBSTRACTION_OPERATOR 
%left MULTIPLICATION_OPERATOR 
%left DIVISION_OPERATOR 

%left AND_OPERATOR
%left OR_OPERATOR
%left NOT_OPERATOR
%left INF_OPERATOR
%left INFEQ_OPERATOR
%left SUP_OPERATOR
%left SUPEQ_OPERATOR
%left EQ_OPERATOR
%left DIFF_OPERATOR
%left TRUE
%left FALSE
%left ','

%token MATHEMATICAL_FUNCTION 
%token IDENTIFIER 

%token FUNCTION 
%token IF 
%token THEN 
%token ELSE 
%token START
%token END 
%token RETURN 
%token WHILE 
%token DO 
%token READ 
%token WRITE 




%%

program: 
		statement_list 	
        ;
		
statement_list:
		statement
		|  statement_list '\n' statement
		
	

statement:
		/* empty */
		| declaration_statement 
		| assignement_statement 
		| if_statement 
		| while_statement 
		| do_while_statement
		| write_statement
		| read_statement
		| function_declaration
		| function_call
		| return_statement
		;

		
declaration_statement:
		variable_type IDENTIFIER '=' expression 	{printf("Declaration + assignement parsed\n");}
		| variable_type IDENTIFIER 					{printf("Declaration parsed\n");}
		;
		
variable_type:
		INT_TYPE
		| REAL_TYPE
		| BOOLEAN_TYPE
		| CHAR_TYPE
		| STRING_TYPE
		;
assignement_statement:
		IDENTIFIER '=' expression 					{printf("Assignement parsed\n");}
		;
		

		
if_statement:
		IF condition THEN '\n' statement_list '\n' ELSE '\n' statement_list '\n' END 		{printf("if else statement parsed\n");}
		| IF condition THEN '\n' statement_list '\n'  END									{printf("if statement parsed\n");}
		;
		
while_statement:
		WHILE condition DO '\n' statement_list '\n' END 									{printf("while statement parsed\n");}
		;
		
do_while_statement:
		DO '\n' statement_list '\n' WHILE condition											{printf("do while statement parsed\n");}
		;

read_statement:
		READ '(' STRING ',' IDENTIFIER ')' {printf("read statement parsed\n");}
		;
		
write_statement:
		WRITE '(' expression ')' {printf("Write statement parsed\n");}
		;
		
return_statement:
		RETURN expression
		;
		
		
expression :
		expression ADDITION_OPERATOR expression
		| expression SUBSTRACTION_OPERATOR expression
		| expression MULTIPLICATION_OPERATOR expression
		| expression DIVISION_OPERATOR expression
		| '(' expression ')'
		| function_call
		| value
		

		
value:
		NUMBER
		| STRING
		| CHARACTER
		| TRUE
		| FALSE
		| IDENTIFIER
		;
	

condition:
		| expression AND_OPERATOR expression
		| expression OR_OPERATOR expression
		| expression NOT_OPERATOR expression
		| expression EQ_OPERATOR expression
		| expression DIFF_OPERATOR expression
		| expression SUP_OPERATOR expression
		| expression SUPEQ_OPERATOR expression
		| expression INF_OPERATOR expression
		| expression INFEQ_OPERATOR expression
		| TRUE
		| FALSE
		;


		
function_declaration: 
		FUNCTION IDENTIFIER '('argument_declaration_list ')' ':' variable_type '\n' START '\n' statement_list '\n' END  {printf("Function declaration statement parsed\n");}
		;
argument_declaration_list:

		| argument_declaration
		;
		
argument_declaration:
		variable_type IDENTIFIER '=' value
		| variable_type IDENTIFIER
		| argument_declaration ',' argument_declaration
		;

function_call:
		IDENTIFIER '('argument_list ')'  {printf("Function call parsed\n");}
		;
	
argument_list:
		
		| argument
		
		;
argument:
		expression
		| argument ',' argument
		;

%%
/*** C Code section ***/

int main(int argc, char const *argv[]) {
  yyparse();
  
  printf("Program Valid");
  return 0;
}

int yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}

		
