#include <iostream>
#include <string>
using namespace std;


int doubleNumber(int parameter)
{
	return 2 * parameter;

}



int main()
{
	cout << "Welcome to the psdhd language demo\n"<< flush;


	int inputNumber;
	cout << "Enter a number\n"<< endl;
	cin >> inputNumber;


	cout << "\nThe double is : "<< flush;

	cout << doubleNumber(inputNumber)<< flush;


	if (inputNumber > 5) 
	{
		cout << "\nInput number > 5 !"<< flush;
 
	}

	if (inputNumber > 10) 
	{
		cout << "\nInput number > 10 !"<< flush;
 
	} else {
		cout << "\nInput number < 10 !"<< flush;


	}

	cout << "\nwhile loop"<< flush;


	while (inputNumber > 0) 
	{
		inputNumber = inputNumber - 1;
		cout << "\nInput number equals : "<< flush;

		cout << inputNumber<< flush;

	}

	cout << "\nThanks for the demo !\n"<< flush;

	return 0;
}
