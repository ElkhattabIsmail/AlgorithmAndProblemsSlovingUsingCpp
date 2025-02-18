
#include <iostream>
#include <string>


using namespace std;

void FibonacciSeries()
{
	short Prev1 = 0;
	short Prev2 = 1;
	short Fib = 0;

	for (short i = 0; i < 20; i++)
	{
		Fib = (Prev1 | Prev2) + (Prev1 & Prev2);

		cout << Fib << "   ";

		Prev2 = Prev1;
		Prev1 = Fib;
	}
}
void PrintFibonacciUsingLoop(short Number)
{

	int FebNumber = 0;
	int Prev2 = 0, Prev1 = 1;
	cout << "1   ";
	for (short i = 2; i <= Number; ++i)
	{
		FebNumber = Prev1 + Prev2;
		cout << FebNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FebNumber;
	}
}
int main()
{
	FibonacciSeries();
	cout << "\n";
	PrintFibonacciUsingLoop(20);
	return 0;
}