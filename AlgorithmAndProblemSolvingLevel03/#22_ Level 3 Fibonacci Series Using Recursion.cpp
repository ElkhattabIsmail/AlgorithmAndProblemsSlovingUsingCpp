#include <iostream>
using namespace std;

void PrintFibonacciWithRecursion(short num, int prev = 0, int prev1 = 0)
{
	if (!prev && !prev1)
	{
		cout << ++prev;
	}
	else
	{
		int x = prev + prev1;
		prev1 = prev;
		prev = x;
		cout << "   " << x;
	}

	if (num > 1) 
		PrintFibonacciWithRecursion(num - 1, prev, prev1);
}
void PrintFibonacciUsingRecurssion(short Number, int Prev1, int
	Prev2)
{
	int FebNumber = 0;
	if (Number > 0)
	{
		FebNumber = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FebNumber;

		cout << FebNumber << "  ";
		PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
	}
}
int main()
{
	PrintFibonacciUsingRecurssion(10, 0, 1);
	system("pause>0");
}