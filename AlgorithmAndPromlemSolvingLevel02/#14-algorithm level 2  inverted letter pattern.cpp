#include<iostream>
using namespace std;
int ReadPositiveNumber(string Message)
{
	//   ex number = 3       result CCC  BB  A
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;                       //my solution
	} while (Number <= 0);
	return Number;
}
void print_InvertedPattern_letter(int number)
{
	for (int a = 64+number; a >= 65; a--)
	{

		for (int b = 65; b <= a; b++)
		{
			cout <<char (a);
		}
		cout << endl;
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter the a number?");
	print_InvertedPattern_letter((Number));
}

