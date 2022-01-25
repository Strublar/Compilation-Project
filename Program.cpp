#include <iostream>
#include <string>
using namespace std;


int doubleNumber(int inputNumber)
{
	return 2 * inputNumber;

}



int main()
{
	cout << "Welcome to the psdhd language demo\n"<< flush;


	int inputNumber;
	cout << "Enter a number\n"<< endl;
	cin >> inputNumber;


	cout << "\nThe double is : "<< flush;

	cout << doubleNumber(inputNumber)<< flush;


	return 0;
}
