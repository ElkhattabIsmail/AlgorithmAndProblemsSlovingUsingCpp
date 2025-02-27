
#include<iostream>
using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year) //Two Line
{
	short NumberOfDaysInYear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Month < 1 || Month>12)
		return  0;
	return Month == 2 ? isLeapYear(Year) ? 29 : 28   : NumberOfDaysInYear[Month-1];
	//return Month != 2  ? (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31 : isLeapYear(Year) ? 29 : 28;
}

short NumberOfHoursInAMonth(short Month, short Year) 
{
	return  NumberOfDaysInAMonth(Month, Year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short Year) 
{
	return  NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year) 
{
	return  NumberOfMinutesInAMonth(Month, Year) * 60;
}
short ReadMonth() {
	short Month;
	cout << "\nPlease enter a Month to check? ";
	cin >> Month; return Month;
}
short ReadYear() {
	short Year;
	cout << "\nPlease enter a year to check? ";
	cin >> Year; return Year;
}
int main() {

	short Year = ReadYear();
	short Month = ReadMonth();

	cout << "\nNumber of Days    in Month [" << Month << "] is " << NumberOfDaysInAMonth(Month, Year);
	cout << "\nNumber of Hours   in Month [" << Month << "] is " << NumberOfHoursInAMonth(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMinutesInAMonth(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfSecondsInAMonth(Month, Year);

	system("pause>0");
	return 0;
}