#include <iostream>
#include <string>
using namespace std;

string ReadPositiveNumber()
{
	string Number;

	cout << "Enter a series of numbers:\n ";
	cin >> Number;
	return (string)Number;
}

void PrintReversedDigits(string Number)
{
	int x = Number.length() - 1;

	for (int i = x; i >= 0; i--)
	{
		cout << Number[i] << endl;
	}
}


int main()
{
	PrintReversedDigits(ReadPositiveNumber());
}