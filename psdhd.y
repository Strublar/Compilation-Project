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


<<<<<<< Updated upstream
=======
%token <node_object> FUNCTION 
%token <node_object> IF 
%token <node_object> THEN 
%token <node_object> ELSE 
%token <node_object> START
%token <node_object> END 
%token <node_object> RETURN 
%token <node_object> WHILE 
%token <node_object> DO 
%token <node_object> READ 
%token <node_object> WRITE 

%type <node_object> program statement_list statement declaration_statement variable_type assignement_statement if_statement while_statement
%type <node_object> do_while_statement read_statement write_statement return_statement expression value condition function_declaration
%type <node_object> argument_declaration_list argument_declaration function_call argument_list argument
%type <node_object> identifier
%type <node_object> and_operator or_operator not_operator eq_operator diff_operator sup_operator supeq_operator inf_operator infeq_operator
%type <node_object> addition_operator substraction_operator multiplication_operator division_operator 	

>>>>>>> Stashed changes

%%

identifier:					IDENTIFIER					{ $$.node = createNode(NULL, NULL, $$.name); };

addition_operator: 			ADDITION_OPERATOR			{ $$.node = createNode(NULL, NULL, $$.name); };
substraction_operator: 		SUBSTRACTION_OPERATOR		{ $$.node = createNode(NULL, NULL, $$.name); };
multiplication_operator: 	MULTIPLICATION_OPERATOR		{ $$.node = createNode(NULL, NULL, $$.name); };
division_operator: 			DIVISION_OPERATOR			{ $$.node = createNode(NULL, NULL, $$.name); };	

and_operator: 				AND_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
or_operator: 				OR_OPERATOR					{ $$.node = createNode(NULL, NULL, $$.name); };
not_operator: 				NOT_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
eq_operator: 				EQ_OPERATOR					{ $$.node = createNode(NULL, NULL, $$.name); };
diff_operator: 				DIFF_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
sup_operator: 				SUP_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
supeq_operator: 			SUPEQ_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
inf_operator: 				INF_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };
infeq_operator: 			INFEQ_OPERATOR				{ $$.node = createNode(NULL, NULL, $$.name); };




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

<<<<<<< Updated upstream
=======

		
>>>>>>> Stashed changes
declaration_statement:
		VARIABLE_TYPE IDENTIFIER { add('C'); } '=' expression 	{printf("Declaration + assignement parsedqsd\n");}
		| VARIABLE_TYPE IDENTIFIER 	{ add('C'); }							{printf("Declaration parsed\n");}
		;
		
assignement_statement:
<<<<<<< Updated upstream
		IDENTIFIER '=' expression 					{printf("Assignement parsed\n");}
=======
		identifier '=' expression 	{ $$.node = createNode($1.node, $3.node, "assignement_statement"); }			
		;
		
		
if_statement:
		IF condition THEN '\n' statement_list '\n' ELSE '\n' statement_list '\n' END 
			{ 
				struct node *then_stat = createNode($3.node, $5.node, "then_stat");
				struct node *cond_then_stat = createNode($2.node, then_stat, "cond_then_stat");
				struct node *else_stat = createNode($7.node, $9.node, "else_stat");
				struct node *cond_then_stat_else_stat = createNode(cond_then_stat, else_stat, "cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat = createNode($1.node, cond_then_stat_else_stat, "if_cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat_end = createNode(if_cond_then_stat_else_stat, $11.node, "if_cond_then_stat_else_stat_end");
				$$.node = if_cond_then_stat_else_stat_end;			
			}
		| IF condition THEN '\n' statement_list '\n' END	
			{ 
				struct node *then_stat = createNode($3.node, $5.node, "then_stat");
				struct node *cond_then_stat = createNode($2.node, then_stat, "cond_then_stat");
				struct node *if_cond_then_stat = createNode($1.node, cond_then_stat, "if_cond_then_stat");
				struct node *if_cond_then_stat_end = createNode(if_cond_then_stat, $7.node, "if_statement");
				$$.node = if_cond_then_stat_end;
			}		
		;
		
while_statement:
		WHILE condition DO '\n' statement_list '\n' END 	
			{ 
				struct node *while_cond = createNode($1.node, $2.node, "while_cond");
				struct node *do_stat = createNode($3.node, $5.node, "do_stat");
				struct node *while_cond_do_stat = createNode(while_cond, do_stat, "while_cond_do_stat");
				struct node *while_cond_do_stat_end = createNode(while_cond_do_stat, $7.node, "while_statement");
				$$.node = while_cond_do_stat_end;
			}			
>>>>>>> Stashed changes
		;
		

		
if_statement:
		"if"			{printf("if statement parsed\n");}
		;
		
<<<<<<< Updated upstream
expression :
		IDENTIFIER 
		| NUMBER
		| STRING
		| CHARACTER
		| BOOLEAN		
=======


expression :
		expression addition_operator expression 			{
																 
																struct node *plus_expr = createNode($2.node, $3.node, "plus_expr");
																$$.node = createNode($1.node, plus_expr, "expr_plus_expr");
															}
		| expression substraction_operator expression 		{
																 
																struct node *minus_expr = createNode($2.node, $3.node, "minus_expr");
																$$.node = createNode($1.node, minus_expr, "expr_minus_expr");
															}
		| expression multiplication_operator expression 	{
																 
																struct node *mult_expr = createNode($2.node, $3.node, "mult_expr");
																$$.node = createNode($1.node, mult_expr, "expr_mult_expr");
															}
		| expression division_operator expression 			{
																 
																struct node *div_expr = createNode($2.node, $3.node, "div_expr");
																$$.node = createNode($1.node, div_expr, "expr_div_expr");
															}
		| '(' expression ')' 								{ $$.node = $2.node; }
		| function_call 									{ $$.node = $1.node; }
		| value 											{ $$.node = $1.node; }
		

	
value:
		NUMBER				{ $$.node = createNode(NULL, NULL, $1.name); }
		| STRING			{ $$.node = createNode(NULL, NULL, $1.name); }
		| CHARACTER			{ $$.node = createNode(NULL, NULL, $1.name); }
		| TRUE				{ $$.node = createNode(NULL, NULL, $1.name); }
		| FALSE				{ $$.node = createNode(NULL, NULL, $1.name); }
		| identifier		{ $$.node = createNode(NULL, NULL, $1.name); }
		;
	



condition:
		expression and_operator expression			{
														struct node *and_expr = createNode($2.node, $3.node, "and_expr");
														$$.node = createNode($1.node, and_expr, "expr_and_expr");
													}
		| expression or_operator expression			{
														struct node *or_expr = createNode($2.node, $3.node, "or_expr");
														$$.node = createNode($1.node, or_expr, "expr_or_expr");
													}
		| expression not_operator expression		{
														struct node *not_expr = createNode($2.node, $3.node, "not_expr");
														$$.node = createNode($1.node, not_expr, "expr_not_expr");
													}
		| expression eq_operator expression			{
														struct node *eq_expr = createNode($2.node, $3.node, "eq_expr");
														$$.node = createNode($1.node, eq_expr, "expr_eq_expr");
													}
		| expression diff_operator expression		{
														struct node *diff_expr = createNode($2.node, $3.node, "diff_expr");
														$$.node = createNode($1.node, diff_expr, "expr_diff_expr");
													}
		| expression sup_operator expression		{
														struct node *sup_expr = createNode($2.node, $3.node, "sup_expr");
														$$.node = createNode($1.node, sup_expr, "expr_sup_expr");
													}
		| expression supeq_operator expression		{
														struct node *supeq_expr = createNode($2.node, $3.node, "supeq_expr");
														$$.node = createNode($1.node, supeq_expr, "expr_supeq_expr");
													}
		| expression inf_operator expression		{
														struct node *inf_expr = createNode($2.node, $3.node, "inf_expr");
														$$.node = createNode($1.node, inf_expr, "expr_inf_expr");
													}
		| expression infeq_operator expression		{
														struct node *infeq_expr = createNode($2.node, $3.node, "infeq_expr");
														$$.node = createNode($1.node, infeq_expr, "expr_infeq_expr");
													}
		| TRUE										{ $$.node = createNode(NULL, NULL, $1.name); }
		| FALSE										{ $$.node = createNode(NULL, NULL, $1.name); }
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
=======
void yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
>>>>>>> Stashed changes
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





		
