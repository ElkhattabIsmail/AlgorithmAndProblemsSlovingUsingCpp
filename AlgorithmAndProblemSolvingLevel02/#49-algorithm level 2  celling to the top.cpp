// algorithm level 2 #49 celling to the top.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
using namespace std;

float GetFractionPart(float Number)
{
	return Number - int(Number);
}
//-10.7=-10;

int ceiling(float Number)
{
	if (abs(GetFractionPart(Number)) > 0)
	{
		if (Number > 0)
			return int(++Number);
		else
			return int(Number);
	}
	else
		return Number;
		
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
	cout << "My floor Result : " << ceiling(Number) << endl;
	cout << "C++ floor Result: " << ceil(Number) << endl;
	return 0;
}