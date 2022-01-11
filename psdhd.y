%{

#include <stdio.h>
#include <stdlib.h>
#include"lex.yy.c"


int count=0;
int q;
char type[10];
int countn;
void yyerror(const char *s);


struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];


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
		VARIABLE_TYPE IDENTIFIER { add('C'); } '=' expression 	{printf("Declaration + assignement parsedqsd\n");}
		| VARIABLE_TYPE IDENTIFIER 	{ add('C'); }							{printf("Declaration parsed\n");}
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


%%

int main() {
  yyparse();
  printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	
	
	int a;
    int x=1;
    int y=2;
    int z=3;
    x=3;
    y=10;
    z=5;
    if(x>5) {
        for(int k=0; k<10; k++) {
            y = x+3;
            printf("Hello!");
        }
    } else {
        int idx = 1;
    }
    for(int i=0; i<10; i++) {
        printf("Hello World!");
        scanf("%d", &x);
        if (x>5) {
            printf("Hi");
        }
        for(int j=0; j<z; j++) {
            a=1;
        }
    } 
    return 1;
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void add(char c) {
  q=search(yytext);
  if(!q) {
    if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
		}
	}
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
  fprintf(stderr, "%s\n", msg);
}





		
