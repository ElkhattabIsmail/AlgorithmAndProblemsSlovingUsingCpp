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
return Number; 
} 
int numberReversed(int Number)
{ 
	int Remainder = 0, Number2 = 0;
	while (Number > 0) 
	{ 
		Remainder = Number % 10;
		Number = Number / 10;         
		Number2 = Number2 * 10 + Remainder;    // first we take the reversed digits as a number
	} 
	return Number2;
}

 
int main() 
{ 
	int Number = ReadPositiveNumber("Please enter the a number?");
	cout << "Reversed Number = " <<numberReversed(Number);

}