%{

#include <stdio.h>
#include <stdlib.h>
int yyerror(char *errormsg);


%}

%token CHARACTER 
%token STRING 
%token NUMBER 
%token VARIABLE_TYPE 
%token BOOLEAN 
%token COMPARATOR_OPERATOR 
%token ARITHMETIC_OPERATOR 
%token MATHEMATICAL_FUNCTION 
%token IDENTIFIER 



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
		
		;

declaration_statement:
		VARIABLE_TYPE IDENTIFIER '=' expression 	{printf("Declaration + assignement parsed\n");}
		| VARIABLE_TYPE IDENTIFIER 					{printf("Declaration parsed\n");}
		;
		
assignement_statement:
		IDENTIFIER '=' expression 					{printf("Assignement parsed\n");}
		;
		

		
if_statement:
		"if"			{printf("if statement parsed\n");}
		;
		
expression :
		IDENTIFIER
		| NUMBER
		| STRING
		| CHARACTER
		| BOOLEAN		
		;
		
		
		
