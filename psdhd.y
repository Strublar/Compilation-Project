%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int yyerror(char *errormsg);
int yylex();

void insert_type();
void addSymbol(char* type,char* variable_type, char* name);
int searchSymbol(char *name);
struct symData {
        char * id_name;
        char * returnType;
        char * type;
        int lineNumber;
} sym[64];

int count=0;
int query;
extern int countn;

%}
%union {
    char *str;
}
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
%token <str> IDENTIFIER 

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

%type <str> declaration_statement variable_type expression function_declaration

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
		variable_type IDENTIFIER '=' expression 				{$$ = yylval.str; addSymbol("Variable",$1,$2);}
		| variable_type IDENTIFIER 								{$$ = yylval.str; addSymbol("Variable",$1,$2);}
		;
		
variable_type:
		INT_TYPE 		{$$ = yylval.str;}
		| REAL_TYPE		{$$ = yylval.str;}
		| BOOLEAN_TYPE	{$$ = yylval.str;}
		| CHAR_TYPE		{$$ = yylval.str;}
		| STRING_TYPE	{$$ = yylval.str;}
		;
assignement_statement:
		IDENTIFIER '=' expression 					
		;
		

		
if_statement:
		IF condition THEN '\n' statement_list '\n' ELSE '\n' statement_list '\n' END 		
		| IF condition THEN '\n' statement_list '\n'  END									
		;
		
while_statement:
		WHILE condition DO '\n' statement_list '\n' END 									
		;
		
do_while_statement:
		DO '\n' statement_list '\n' WHILE condition											
		;

read_statement:
		READ '(' STRING ',' IDENTIFIER ')' 
		;
		
write_statement:
		WRITE '(' expression ')' 
		;
		
return_statement:
		RETURN expression
		;
		
		
expression :
		expression ADDITION_OPERATOR expression 			{$$ = yylval.str;}
		| expression SUBSTRACTION_OPERATOR expression 		{$$ = yylval.str;}
		| expression MULTIPLICATION_OPERATOR expression 	{$$ = yylval.str;}
		| expression DIVISION_OPERATOR expression 			{$$ = yylval.str;}
		| '(' expression ')' 								{$$ = yylval.str;}
		| function_call 									{$$ = yylval.str;}
		| value 											{$$ = yylval.str;}
		

		
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
		FUNCTION IDENTIFIER '('argument_declaration_list ')' ':' variable_type '\n' {$<str>$ = yylval.str;addSymbol("Function",$7,$2);}
		START '\n' statement_list '\n' END  
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
		IDENTIFIER '('argument_list ')'  
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
	printf("\n\n");
	int i=0;
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s : %s (%s) defined in line %d\n",sym[i].type ,sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
	}
	printf("\n\n");
	printf("Program Valid");
	return 0;
}




int yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}



void addSymbol(char* type,char* variable_type, char* name) {
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



		
