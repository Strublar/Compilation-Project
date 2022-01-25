
#include <iostream>
#include <string>

using namespace std;

int main() {
	string test = "Hello ";
	int testInt = 0;
    cout << test<<testInt<<endl;
	cin >> testInt;
	cout <<testInt*2 <<endl;
    return 0;
	
	
	printf("\nCPP TESTS\n");
	
	char* code = printCpp(root,0);
	int size = strlen(code);
	
	printf("Size of code : %d\n",size);
	printf(code);
	
	char* codeString = malloc(size);
	strcpy(codeString,code);
	
	FILE *codeGenerated = malloc(size);
	codeGenerated = fopen("Program.cpp","w");
	fprintf(codeGenerated,codeString);
	fclose(codeGenerated);
	
	
	printf("\n\nProgram Valid");
}