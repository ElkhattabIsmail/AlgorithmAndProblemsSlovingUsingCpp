#include<iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;  //3
}

void pattern_number(int number)
{
	for (int a = 1; a <=  number; a++)
	{

		for (int b = 1; b <= a; b++)
		{
			cout << a;
		}

		cout << endl;
	}
}





int main()
{
	//333 22 1
	int Number = ReadPositiveNumber("Please enter the a number?");
	pattern_number(Number);
}