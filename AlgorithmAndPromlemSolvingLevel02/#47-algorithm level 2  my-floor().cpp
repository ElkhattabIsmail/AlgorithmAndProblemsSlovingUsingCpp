#include<iostream>
using namespace std;

float GetFractionPart(float Number) 
{
	return Number - int(Number);
}
//10.7 gives 10  10.3 = 10  -10.3=-11;
//fraction 0.7;
int MyFloor(float Number)
{
	int IntPart;
	IntPart = int(Number);
	float FractionsPart = GetFractionPart(Number);
	if (Number > 0)
		return int(Number);
	else
			return int(--Number);
}
float  ReadNumber() 
{
	float Number;
	cout << "Please enter a float number?";
	cin >> Number;
	return Number;
}
int main() 
{
	float Number = ReadNumber();
	cout << "My floor Result : " << MyFloor(Number) << endl;
	cout << "C++ floor Result: " << floor(Number) << endl;
	return 0;
}