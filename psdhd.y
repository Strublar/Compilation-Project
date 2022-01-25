%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTPRINTTREE 5

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
void test();

struct symData {
        char * id_name;
        char * returnType;
        char * type;
        int lineNumber;
		int scope;
} sym[64];

struct node {
  struct node *left;
  struct node *right;
  char *token;     
};

int scope;

struct node *root;
struct node* createNode(struct node *left, struct node *right, char *token);
void printTree(struct node *tree, int space);
char* printCpp(struct node *tree, int space);
void addString(char* destination, char* addition);
char *addIndent(int indent);
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

%token <node_object> NUMBER 




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

%type <node_object> program statement_list statement declaration_statement variable_type assignement_statement if_statement else_statement while_statement
%type <node_object> do_while_statement read_statement write_statement return_statement expression value function_declaration
%type <node_object> argument_declaration_list argument_declaration function_call_statement function_call argument_list argument condition


%%

program: 
		statement_list 	{ 
							scope = 0;
							$$.node = createNode($1.node, NULL, "program"); 
							root = $$.node;
						}
						
        ;
		
statement_list:
		statement 							{ $$.node = $1.node; }
		|  statement_list '\n' statement	{ $$.node = createNode($1.node, $3.node, "statement_list"); }
		
	

statement:
		/* empty */
		| declaration_statement 		{ $$.node = $1.node; }
		| assignement_statement 		{ $$.node = $1.node; }
		| if_statement 					{ $$.node = $1.node; }
		| while_statement 				{ $$.node = $1.node; }
		| do_while_statement			{ $$.node = $1.node; }
		| write_statement				{ $$.node = $1.node; }
		| read_statement				{ $$.node = $1.node; }
		| function_declaration			{ $$.node = $1.node; }
		| function_call_statement		{ $$.node = $1.node; }
		| return_statement				{ $$.node = $1.node; }
		;

		
declaration_statement:
		variable_type IDENTIFIER '=' expression 	{ 
														printf("\ndécl %s, scope: %d", $2.name,scope);
														addSymbol("Variable", $1.node->token, $2.name);
														
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *type_id = createNode($1.node, $2.node, "decl");
														$$.node = createNode(type_id, $4.node, "declaration_with_assign_statement");
														
														/*char *type_conversion = check_types($1.name, $4.type);
														if (type_conversion != NULL){
															struct node *type_conversion_node = createNode(NULL, $4.node, "type_conversion");
															$$.node = createNode(type_id, type_conversion_node, "declaration_with_assign_statement");
														}*/
													}
		| variable_type IDENTIFIER 					{
														addSymbol("Variable", $1.node->token, $2.name);
														$2.node = createNode(NULL, NULL, $2.name);
														$$.node = createNode($1.node, $2.node, "declaration_without_assign_statement");
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
										
										/*char *var_type = get_type($1.name);
										char *type_conversion = check_types(var_type, $3.type);
										if (type_conversion != NULL){
											struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
											$$.node = createNode($1.node, type_conversion_node, "assignement_statement");
										}*/
									}			
		;
		
		
if_statement:
		IF 
			{ test();
			printf("if_stat, scope%d", scope);}
		condition THEN '\n' statement_list '\n' else_statement END 
		{ 
				$$.node = createNode(NULL, NULL, "while_statement");
			}
		;
		
else_statement:
	| ELSE '\n' statement_list '\n'	
		
	;	
	
while_statement:
		WHILE condition DO '\n' statement_list '\n' END 	
			{ 
				$$.node = createNode($2.node, $5.node, "while_statement");
			}			
		;
		
do_while_statement:
		DO '\n' statement_list '\n' WHILE condition		
			{ 
				$$.node = createNode($3.node, $6.node, "do_while_statement");
			}			
		;

read_statement:
		READ '(' STRING ',' IDENTIFIER ')'
			{ 
				check_declaration($5.name);
				$3.node = createNode(NULL, NULL, $3.name);
				$5.node = createNode(NULL, NULL, $5.name);
				struct node *str_id = createNode($3.node, $5.node, "str_id");
				$$.node = createNode($3.node, $5.node, "read_statement");
			}		
		;
	
write_statement:
		WRITE '(' expression ')'  		{ 
											$$.node = createNode($3.node, NULL, "write_statement");
										}
		;
		
return_statement:
		RETURN expression				{ 
											$$.node = createNode($2.node,NULL, "return_statement"); 
										}
		;
		
		
expression :
		expression ADDITION_OPERATOR expression 			{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *plus_expr = createNode($2.node, $3.node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	plus_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																$$.node = createNode($1.node, plus_expr, "binary_token");
															}
		| expression SUBSTRACTION_OPERATOR expression 		{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *minus_expr = createNode($2.node, $3.node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	minus_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																$$.node = createNode($1.node, minus_expr, "binary_token");
															}
		| expression MULTIPLICATION_OPERATOR expression 	{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *mult_expr = createNode($2.node, $3.node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	mult_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																$$.node = createNode($1.node, mult_expr, "binary_token");
															}
		| expression DIVISION_OPERATOR expression 			{
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *div_expr = createNode($2.node, $3.node, "binary_token");
																
																/*char *type_conversion = check_types($1.type, $3.type);
																if (type_conversion != NULL){
																	struct node *type_conversion_node = createNode(NULL, $3.node, "type_conversion");
																	div_expr = createNode($2.node, type_conversion_node, "binary_token");
																}*/
																$$.node = createNode($1.node, div_expr, "binary_token");
															}
		| '(' expression ')' 								{ 	
																$$.node = createNode($2.node, NULL, "parenthesis_expression");
															}
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
														struct node *and_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, and_expr, "binary_token");
													}
		| expression OR_OPERATOR expression			{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *or_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, or_expr, "binary_token");
													}
		| expression NOT_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *not_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, not_expr, "binary_token");
													}
		| expression EQ_OPERATOR expression			{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *eq_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, eq_expr, "binary_token");
													}
		| expression DIFF_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *diff_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, diff_expr, "binary_token");
													}
		| expression SUP_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *sup_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, sup_expr, "binary_token");
													}
		| expression SUPEQ_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *supeq_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, supeq_expr, "binary_token");
													}
		| expression INF_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *inf_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, inf_expr, "binary_token");
													}
		| expression INFEQ_OPERATOR expression		{
														$2.node = createNode(NULL, NULL, $2.name);
														struct node *infeq_expr = createNode($2.node, $3.node, "binary_token");
														$$.node = createNode($1.node, infeq_expr, "binary_token");
													}
		| TRUE										{ $$.node = createNode(NULL, NULL, $1.name); }
		| FALSE										{ $$.node = createNode(NULL, NULL, $1.name); }
		;


function_declaration: 
		FUNCTION IDENTIFIER '(' argument_declaration_list ')' ':' variable_type '\n' START '\n' statement_list '\n' END		{ 
																																addSymbol("Function",$7.node->token,$2.name);
																																$2.node = createNode(NULL, NULL, $2.name);
																																
																																struct node *id_ret = createNode($7.node, $2.node, "function_id_type");
																																struct node *arg_stat = createNode($4.node, $11.node, "function_args_statements");
																																$$.node = createNode(id_ret, arg_stat, "function_declaration");
																															}
				
		;
argument_declaration_list:
		| argument_declaration		{ $$.node = $1.node; }
		;
		
argument_declaration:
		variable_type IDENTIFIER '=' value					{ 
																$1.node = createNode(NULL, NULL, $1.name);
																$2.node = createNode(NULL, NULL, $2.name);
																struct node *type_id = createNode($1.node, $2.node, "binary_token");
																$$.node = createNode(type_id, $4.node, "equals");
															}			
		| variable_type IDENTIFIER							{ 
																$2.node = createNode(NULL, NULL, $2.name);
																$$.node = createNode($1.node, $2.node, "binary_token"); 
															}
		| argument_declaration ',' argument_declaration		{ $$.node = createNode($1.node, $3.node, "arguments"); }
		;

function_call_statement:
		function_call						{$$.node = createNode($1.node, NULL, "function_call_statement");}
		;
function_call:
		IDENTIFIER '(' argument_list ')'  	{ 
												check_declaration($1.name);
												$1.node = createNode(NULL, NULL, $1.name);
												$$.node = createNode($1.node, $3.node, "function_call"); 
											}
		;
	
argument_list:
		| argument							{ $$.node = $1.node; }
		;
		
argument:
		expression					{ $$.node = $1.node; }
		| argument ',' argument		{ $$.node = createNode($1.node, $3.node, "arguments"); }
		;

%%
/*** C Code section ***/

int main(int argc, char const *argv[]) {
	yyparse();
	int i=0;

	printf("\n");
	printf("---------- SYMBOL TABLE ----------\n");
	for(i=0; i<count; i++) {
		printf("%s (scope %d): %s (%s) defined in line %d\n",sym[i].type , sym[i].scope, sym[i].id_name , sym[i].returnType, sym[i].lineNumber);
	}
	for(i=0;i<count;i++) {
		free(sym[i].id_name);
		free(sym[i].type);
		free(sym[i].returnType);
		free(sym[i].scope);
	}
	
	printf("\n");
	printf("---------- PARSING TREE ----------\n");
	//printTree(root, 0);
	
	printf("\n\n");
	printf("---------- SEMANTIC ANALYSIS ----------\n");
	if(error_index > 0) {
		printf("%d error(s) encountered during the execution.\n", error_index);
		for(i = 0; i < error_index; i++){
			printf("       -> %s", errors[i]);
		}
	} else {
		printf("No error found.");
	}
	
	//printf("\nCPP TESTS\n");
	
	const char* code = malloc(300000);
	code = printCpp(root,0);
	int size = strlen(code);
	
	printf("Size of code : %d\n",size);
	
	
	char* codeString = malloc(size);
	strcpy(codeString,code);
	printf(code);
	
	FILE *codeGenerated = fopen("Program.cpp","w");
	fprintf(codeGenerated,codeString);
	fclose(codeGenerated);
	
	
	printf("\n\nProgram Valid");
	
	free(codeGenerated);
	free(codeString);
	
	return 0;
}

void yyerror(char *errormsg)
{
    fprintf(stderr, "%s\n", errormsg);
    exit(1);
}

void addSymbol(char* type, char* variable_type, char* name) {

	int i;
	for(i = 0; i < 11; i++) {   
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
		sym[count].scope=scope;   		
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
	int i;
    for (i = COUNTPRINTTREE; i < space; i++)
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
	int i;
    for(i = 0; i < count; i++) {  
        if(!strcmp(sym[i].id_name, var)) {   
            return sym[i].type;  
        }
    }
}


char*  printCpp(struct node *tree, int space){
	if(!tree)
		return "";
		
	if(!strcmp(tree->token, "program"))
	{
		char code[10000] = "#include <iostream>\n#include <string>\nusing namespace std;\n\n";
		addString(code, printCpp(tree->left,space));
		addString(code, printCpp(tree->right,space));
		return code;
	}
	
	if(!strcmp(tree->token, "statement_list"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,space));
		addString(code, "\n");
		addString(code, printCpp(tree->right,space));
		return code;
	}
	
	
	if(!strcmp(tree->token, "declaration_without_assign_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code,printCpp(tree->left,0));
		addString(code," " );
		addString(code, printCpp(tree->right,0));
		addString(code, ";");
		return code;
	}
	
	
	
	if(!strcmp(tree->token, "declaration_with_assign_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, printCpp(tree->left,0));
		addString(code, " = ");
		addString(code, printCpp(tree->right,0));
		addString(code,";");
		return code;
	}
	
	if(!strcmp(tree->token, "decl"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code,printCpp(tree->left,0));
		addString(code," " );
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "type_conversion"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "assignement_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, printCpp(tree->left,0));
		addString(code, " = ");
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "binary_token"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,0));
		addString(code, " ");
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "parenthesis_expression"))
	{
		char code[10000] = "(";
		addString(code, printCpp(tree->left,0));
		addString(code, ")");
		return code;
	}
	
	if(!strcmp(tree->token, "if_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "if (");
		addString(code, printCpp(tree->left,0));
		addString(code, ") \n");
		addString(code,addIndent(space));
		addString(code, "{\n");
		addString(code,printCpp(tree->right,space+1));
		addString(code, "\n");
		addString(code,addIndent(space));
		addString(code, "}");
		return code;
	}
	
	
	if(!strcmp(tree->token, "else_stat"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,space));
		addString(code, "\n");
		addString(code,addIndent(space-1));
		addString(code, "} else {\n");
		addString(code,printCpp(tree->right,space));
		addString(code, "\n");
		return code;
	}
	
	if(!strcmp(tree->token, "while_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "while (");
		addString(code, printCpp(tree->left,0));
		addString(code, ") \n");
		addString(code,addIndent(space));
		addString(code, "{\n");
		addString(code,printCpp(tree->right,space+1));
		addString(code, "\n");
		addString(code,addIndent(space));
		addString(code, "}");
		return code;
	}
	
	if(!strcmp(tree->token, "do_while_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "do {\n");
		addString(code, printCpp(tree->left,space+1));
		addString(code, "\n");
		addString(code,addIndent(space));
		addString(code, "} while (");
		addString(code, printCpp(tree->right,0));
		addString(code, ");\n");
		return code;
	}
	
	if(!strcmp(tree->token, "write_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "cout << ");
		addString(code, printCpp(tree->left,0));
		addString(code, "<< endl;\n");
		return code;
	}
	
	
	if(!strcmp(tree->token, "read_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "cout << ");
		addString(code, printCpp(tree->left,0));
		addString(code, "<< endl;\n");
		addString(code,addIndent(space));
		addString(code, "cin >> ");
		addString(code, printCpp(tree->right,0));
		addString(code, ";\n");
		return code;
	}
	
	if(!strcmp(tree->token, "function_declaration"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, printCpp(tree->left,space));
		addString(code, printCpp(tree->right,space));
		return code;
	}
	
	if(!strcmp(tree->token, "function_id_type"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,0));
		addString(code, " ");
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "function_args_statements"))
	{
		char code[10000] = "";
		addString(code, "(");
		addString(code, printCpp(tree->left,0));
		addString(code, ")\n");
		addString(code,addIndent(space));
		addString(code, "{\n");
		addString(code, printCpp(tree->right,space+1));
		addString(code,addIndent(space));
		addString(code, "}\n");
		return code;
	}
	
	
	if(!strcmp(tree->token, "return_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, "return ");
		addString(code, printCpp(tree->left,0));
		addString(code, ";\n");
		return code;
	}
	
	if(!strcmp(tree->token, "arguments"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,0));
		addString(code, ", ");
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "equals"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,0));
		addString(code, " = ");
		addString(code, printCpp(tree->right,0));
		return code;
	}
	
	if(!strcmp(tree->token, "function_call_statement"))
	{
		char code[10000] = "";
		addString(code,addIndent(space));
		addString(code, printCpp(tree->left,0));
		addString(code, ";\n");
		return code;
	}
	
	if(!strcmp(tree->token, "function_call"))
	{
		char code[10000] = "";
		addString(code, printCpp(tree->left,0));
		addString(code, "(");
		addString(code, printCpp(tree->right,0));
		addString(code, ")");
		return code;
	}
	
	
	
	//printf(processToken(tree->token));
	return tree->token;
}

void addString(char* destination, char* addition)
{
	//printf("\nBEGIN\n");
	//printf(addition);
	//printf("\nEND\n");
	
	realloc(destination, strlen(addition)*sizeof(char));

	strcat(destination, addition);
}

char *addIndent(int indent)
{
	char string[1000] = "";
	int i;
	for(i=0;i<indent;i++)
	{
		strcat(string,"\t");
	}
	return string;		
}

void test(){
	printf("\n");
	printf("scoppppppppppppppe %d", scope);
	printf("\n");
	scope++;
}