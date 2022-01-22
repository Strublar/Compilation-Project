%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTPRINTTREE 10

void yyerror(char *errormsg);
int yylex();

void insert_type();
void addSymbol(char* type, char* variable_type, char* name);
int searchSymbol(char *name);
int count = 0;
int query;
extern int countn;
char *check_types(char *type1, char *type2);
char *get_type(char *var);

struct symData {
        char * id_name;
        char * returnType;
        char * type;
        int lineNumber;
} sym[64];

struct node {
  struct node *left;
  struct node *right;
  char *token;     
};


struct node *root;
struct node* createNode(struct node *left, struct node *right, char *token);
void printTree(struct node *tree, int space);
void check_declaration(char *name);
int error_index = 0;
char errors[10][100];
char reserved[11][10] = {"function", "start", "end", "return", "if", "then", "else", "while", "do", "read", "write"};

%}
%union {
    char *str;
	struct var_name {
	   char name[100];
	   struct node* node;
	   char type[5];
	} node_object;

}
%token <node_object> CHARACTER 
%token <node_object> STRING 
%token <node_object> NUMBER 

%token <node_object> INT_TYPE
%token <node_object> REAL_TYPE
%token <node_object> BOOLEAN_TYPE
%token <node_object> CHAR_TYPE
%token <node_object> STRING_TYPE
%token <node_object> VOID_TYPE


%left <node_object> ADDITION_OPERATOR 
%left <node_object> SUBSTRACTION_OPERATOR 
%left <node_object> MULTIPLICATION_OPERATOR 
%left <node_object> DIVISION_OPERATOR 

%left <node_object> AND_OPERATOR
%left <node_object> OR_OPERATOR
%left <node_object> NOT_OPERATOR
%left <node_object> INF_OPERATOR
%left <node_object> INFEQ_OPERATOR
%left <node_object> SUP_OPERATOR
%left <node_object> SUPEQ_OPERATOR
%left <node_object> EQ_OPERATOR
%left <node_object> DIFF_OPERATOR
%left <node_object> TRUE
%left <node_object> FALSE
%left <node_object> ','

%token <node_object> MATHEMATICAL_FUNCTION 
%token <node_object> IDENTIFIER 			

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
%type <node_object> do_while_statement read_statement write_statement return_statement expression value function_declaration
%type <node_object> argument_declaration_list argument_declaration function_call argument_list argument condition


%%

program: 
		statement_list 	{ 
							$$.node = createNode($1.node, NULL, "program"); 
							root = $$.node;
						}
						
        ;
		
statement_list:
		statement 							{ $$.node = $1.node; }
		|  statement_list '\n' statement	{ $$.node = createNode($1.node, $3.node, "statement_list"); }
		
	

statement:
		/* empty */
		declaration_statement 		{ $$.node = $1.node; }
		| assignement_statement 	{ $$.node = $1.node; }
		| if_statement 				{ $$.node = $1.node; }
		| while_statement 			{ $$.node = $1.node; }
		| do_while_statement		{ $$.node = $1.node; }
		| write_statement			{ $$.node = $1.node; }
		| read_statement			{ $$.node = $1.node; }
		| function_declaration		{ $$.node = $1.node; }
		| function_call				{ $$.node = $1.node; }
		| return_statement			{ $$.node = $1.node; }
		;

		
declaration_statement:
		variable_type IDENTIFIER '=' expression 	{ 
														addSymbol("Variable", $1.node->token, $2.name);
														
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *type_id = createNode($1.node, $2.node, "decl_without_assign");
														$$.node = createNode(type_id, $4.node, "decl_with_assign");
														
														char *type_conversion = check_types($1.name, $4.type);
														if (type_conversion != NULL){
															struct node *type_conversion_node = createNode(NULL, $4.node, "type_conversion");
															$$.node = createNode(type_id, type_conversion_node, "decl_with_assign");
														}
													}
		| variable_type IDENTIFIER 					{
														addSymbol("Variable", $1.node->token, $2.name);
														$2.node = createNode(NULL, NULL, $2.name);
														$$.node = createNode($1.node, $2.node, "decl_without_assign");
													}
		;
		
variable_type:
		INT_TYPE 		{ $$.node = createNode(NULL, NULL, $1.name); }
		| REAL_TYPE		{ $$.node = createNode(NULL, NULL, $1.name); }
		| BOOLEAN_TYPE	{ $$.node = createNode(NULL, NULL, $1.name); }
		| CHAR_TYPE		{ $$.node = createNode(NULL, NULL, $1.name); }
		| STRING_TYPE	{ $$.node = createNode(NULL, NULL, $1.name); }
		;
		
assignement_statement:
		IDENTIFIER '=' expression 	{ 
										check_declaration($1.name);
										$1.node = createNode(NULL, NULL, $1.name);
										$$.node = createNode($1.node, $3.node, "assignement_statement"); 
										
										char *var_type = get_type($1.name);
										char *type_conversion = check_types(var_type, $3.type);
										if (type_conversion != NULL){
											struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
											$$.node = createNode($1.node, type_conversion_node, "decl_with_assign");
										}
									}			
		;
		
		
if_statement:
		IF condition THEN '\n' statement_list '\n' ELSE '\n' statement_list '\n' END 
			{ 
				$1.node = createNode(NULL, NULL, $1.name);
				$3.node = createNode(NULL, NULL, $3.name);
				$7.node = createNode(NULL, NULL, $7.name);
				$11.node = createNode(NULL, NULL, $11.name);
				struct node *then_stat = createNode($3.node, $5.node, "then_stat");
				struct node *cond_then_stat = createNode($2.node, then_stat, "cond_then_stat");
				struct node *else_stat = createNode($7.node, $9.node, "else_stat");
				struct node *cond_then_stat_else_stat = createNode(cond_then_stat, else_stat, "cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat = createNode($1.node, cond_then_stat_else_stat, "if_cond_then_stat_else_stat");
				struct node *if_cond_then_stat_else_stat_end = createNode(if_cond_then_stat_else_stat, $11.node, "if_cond_then_stat_else_stat_end");
				$$.node = if_cond_then_stat_else_stat_end;			
			}
		| IF condition THEN '\n' statement_list '\n'  END	
			{ 
				$1.node = createNode(NULL, NULL, $1.name);
				$3.node = createNode(NULL, NULL, $3.name);
				$7.node = createNode(NULL, NULL, $7.name);
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
				$1.node = createNode(NULL, NULL, $1.name);
				$3.node = createNode(NULL, NULL, $3.name);
				$7.node = createNode(NULL, NULL, $7.name);
				struct node *while_cond = createNode($1.node, $2.node, "while_cond");
				struct node *do_stat = createNode($3.node, $5.node, "do_stat");
				struct node *while_cond_do_stat = createNode(while_cond, do_stat, "while_cond_do_stat");
				struct node *while_cond_do_stat_end = createNode(while_cond_do_stat, $7.node, "while_statement");
				$$.node = while_cond_do_stat_end;
			}			
		;
		
do_while_statement:
		DO '\n' statement_list '\n' WHILE condition		
			{ 
				$1.node = createNode(NULL, NULL, $1.name);
				$5.node = createNode(NULL, NULL, $5.name);
				struct node *do_stat = createNode($1.node, $3.node, "do_stat");
				struct node *while_cond = createNode($5.node, $6.node, "while_cond");
				struct node *do_stat_while_cond = createNode(do_stat, while_cond, "do_while_statement");
				$$.node = do_stat_while_cond;
			}			
		;

read_statement:
		READ '(' STRING ',' IDENTIFIER ')'
			{ 
				check_declaration($5.name);
				$1.node = createNode(NULL, NULL, $1.name);
				$3.node = createNode(NULL, NULL, $3.name);
				$5.node = createNode(NULL, NULL, $5.name);
				struct node *str_id = createNode($3.node, $5.node, "str_id");
				struct node *read_str_id = createNode($1.node, str_id, "read_statement");
				$$.node = read_str_id;
			}		
		;
	
write_statement:
		WRITE '(' expression ')'  		{ 
											$1.node = createNode(NULL, NULL, $1.name);
											$$.node = createNode($1.node, $3.node, "write_statement");
										}
		;
		
return_statement:
		RETURN expression				{ 
											$1.node = createNode(NULL, NULL, $1.name);
											$$.node = createNode($1.node, $2.node, "return_statement"); 
										}
		;
		
		
expression :
		expression ADDITION_OPERATOR expression 			{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *plus_expr = createNode($2.node, $3.node, "plus_expr");
																
																char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	plus_expr = createNode($2.node, type_conversion_node, "plus_expr");
																}
																$$.node = createNode($1.node, plus_expr, "expr_plus_expr");
															}
		| expression SUBSTRACTION_OPERATOR expression 		{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *minus_expr = createNode($2.node, $3.node, "minus_expr");
																
																char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	minus_expr = createNode($2.node, type_conversion_node, "minus_expr");
																}
																$$.node = createNode($1.node, minus_expr, "expr_minus_expr");
															}
		| expression MULTIPLICATION_OPERATOR expression 	{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *mult_expr = createNode($2.node, $3.node, "mult_expr");
																
																char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	mult_expr = createNode($2.node, type_conversion_node, "mult_expr");
																}
																$$.node = createNode($1.node, mult_expr, "expr_mult_expr");
															}
		| expression DIVISION_OPERATOR expression 			{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *div_expr = createNode($2.node, $3.node, "div_expr");
																
																char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	div_expr = createNode($2.node, type_conversion_node, "div_expr");
																}
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
		| IDENTIFIER		{ check_declaration($1.name);
							  $$.node = createNode(NULL, NULL, $1.name); }
		;
	

condition:
		expression AND_OPERATOR expression			{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *and_expr = createNode($2.node, $3.node, "and_expr");
														$$.node = createNode($1.node, and_expr, "expr_and_expr");
													}
		| expression OR_OPERATOR expression			{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *or_expr = createNode($2.node, $3.node, "or_expr");
														$$.node = createNode($1.node, or_expr, "expr_or_expr");
													}
		| expression NOT_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *not_expr = createNode($2.node, $3.node, "not_expr");
														$$.node = createNode($1.node, not_expr, "expr_not_expr");
													}
		| expression EQ_OPERATOR expression			{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *eq_expr = createNode($2.node, $3.node, "eq_expr");
														$$.node = createNode($1.node, eq_expr, "expr_eq_expr");
													}
		| expression DIFF_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *diff_expr = createNode($2.node, $3.node, "diff_expr");
														$$.node = createNode($1.node, diff_expr, "expr_diff_expr");
													}
		| expression SUP_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *sup_expr = createNode($2.node, $3.node, "sup_expr");
														$$.node = createNode($1.node, sup_expr, "expr_sup_expr");
													}
		| expression SUPEQ_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *supeq_expr = createNode($2.node, $3.node, "supeq_expr");
														$$.node = createNode($1.node, supeq_expr, "expr_supeq_expr");
													}
		| expression INF_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *inf_expr = createNode($2.node, $3.node, "inf_expr");
														$$.node = createNode($1.node, inf_expr, "expr_inf_expr");
													}
		| expression INFEQ_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *infeq_expr = createNode($2.node, $3.node, "infeq_expr");
														$$.node = createNode($1.node, infeq_expr, "expr_infeq_expr");
													}
		| TRUE										{ $$.node = createNode(NULL, NULL, $1.name); }
		| FALSE										{ $$.node = createNode(NULL, NULL, $1.name); }
		;


function_declaration: 
		FUNCTION IDENTIFIER '(' argument_declaration_list ')' ':' variable_type '\n' {$<str>$ = $1.name;addSymbol("Function",$7.node->token,$2.name);}
		START '\n' statement_list '\n' END  
				{ 
					$1.node = createNode(NULL, NULL, $1.name);
					$2.node = createNode(NULL, NULL, $2.name);
					$10.node = createNode(NULL, NULL, $10.name);
					$14.node = createNode(NULL, NULL, $14.name);
					struct node *start_stat = createNode($10.node, $12.node, "start_stat");
					struct node *start_stat_end = createNode(start_stat, $14.node, "start_stat_end");
					struct node *id_arg = createNode($2.node, $4.node, "id_arg");
					struct node *id_arg_type = createNode(id_arg, $7.node, "id_arg_type");
					struct node *fct_id_arg_type = createNode($1.node, id_arg_type, "fct_id_arg_type");
					$$.node = createNode(fct_id_arg_type, start_stat_end, "function_declaration");
				}
		;
argument_declaration_list:
		argument_declaration		{ $$.node = $1.node; }
		;
		
argument_declaration:
		variable_type IDENTIFIER '=' value					{ 
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *type_id = createNode($1.node, $2.node, "type_id");
																$$.node = createNode(type_id, $4.node, "arg_type_id_value");
															}			
		| variable_type IDENTIFIER							{ 
																$2.node = createNode(NULL, NULL, $2.name);
																$$.node = createNode($1.node, $2.node, "arg_type_id"); 
															}
		| argument_declaration ',' argument_declaration		{ $$.node = createNode($1.node, $3.node, "argdecl_argdecl"); }
		;
		
function_call:
		IDENTIFIER '(' argument_list ')'  	{ 
												check_declaration($1.name);
												$1.node = createNode(NULL, NULL, $1.name);
												$$.node = createNode($1.node, $3.node, "function_call"); 
											}
		;
	
argument_list:
		argument							{ $$.node = $1.node; }
		;
		
argument:
		expression					{ $$.node = $1.node; }
		| argument ',' argument		{ $$.node = createNode($1.node, $3.node, "arg_list"); }
		;

%%
/*** C Code section ***/

int main(int argc, char const *argv[]) {
	yyparse();
	int i=0;

	printf("\n");
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s : %s (%s) defined in line %d\n",sym[i].type ,sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
	}
	
	printf("\n");
	printf("---------- PARSING TREE ----------\n");
	printTree(root, 0);
	
	printf("\n\n");
	printf("---------- SEMANTIC ANALYSIS ----------\n");
	if(error_index > 0) {
		printf("%d error(s) encountered during the execution.\n", error_index);
		for(int i = 0; i < error_index; i++){
			printf("       -> %s", errors[i]);
		}
	} else {
		printf("No error found.");
	}
	
	
	printf("\n\n");
	printf("Program Valid");
	return 0;
}

void yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}

void addSymbol(char* type, char* variable_type, char* name) {

	for(int i = 0; i < 11; i++) {   
		if(strcmp(reserved[i], strdup(name)) == 0) {
			sprintf(errors[error_index], "Line %d: Variable name \"%s\" is a reserved keyword.\n", countn + 1, name);
			error_index++;    
			return;
		}  
	} 
	query = searchSymbol(name);
	if(query==0) {
		sym[count].id_name=strdup(name);
		sym[count].returnType=strdup(variable_type);
		sym[count].lineNumber=countn;
		sym[count].type=strdup(type);   
		count++; 
	}
	else
	{
		sprintf(errors[error_index], "Line %d: Variable \"%s\" already declared.\n", countn + 1, name);  
		error_index++;  
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

struct node* createNode(struct node *left, struct node *right, char *token) {
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	char *newstr = (char*) malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void printTree(struct node *tree, int space) {
   /* int i; 
    if (tree->left) {
        printTree(tree->left); 
    } 
    printf("%s, ", tree->token); 
    if (tree->right) {  
        printTree(tree->right); 
    }*/

	if (tree == NULL)
        return;
 
    // Increase distance between levels
    space += COUNTPRINTTREE;
 
    // Process right child first
    printTree(tree->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNTPRINTTREE; i < space; i++)
        printf(" ");
    printf("%s\n", tree->token);
 
    // Process left child
    printTree(tree->left, space);
}

void check_declaration(char *name) {
    query = searchSymbol(name);
    if(!query) { 
        sprintf(errors[error_index], "Line %d: Variable \"%s\" has not been declared.\n", countn + 1, name);  
        error_index++;    
    }
}

char *check_types(char *type1, char *type2) { 

    if(!strcmp(type2, "null"))
		return NULL; 
		
    if(!strcmp(type1, type2)) 
		return NULL; 

    if(!strcmp(type1, "int") && !strcmp(type2, "float")) 
		return "floattoint";
		
    if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return "inttofloat";
		
    if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return "chattoint";
		
    if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return "inttochar";
		
    if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return "chartofloat";
		
    if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return "floattochar";
}

char *get_type(char *var) { 
    for(int i = 0; i < count; i++) {  
        if(!strcmp(sym[i].id_name, var)) {   
            return sym[i].type;  
        }
    }
}