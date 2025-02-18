#include<iostream>
#include<string>
using namespace std;
int ReadPositiveNumber(string Message)
{
	//  3  ==     A  BB  CCC
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
void PrintLetterPattern(int Number)
{
	cout << "\n";
	for (int i = 65;  i <= 64+Number; i++)    //from a to c
	{
		for (int j = 1; j <= Number - (64+Number - i); j++)               // i increasing constantly
		{                 // OR J <= i - 65 +1  that's better
			cout << char(i);
		}
		cout << "\n";

	}
}
int main()
{
	PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
	return 0;
}