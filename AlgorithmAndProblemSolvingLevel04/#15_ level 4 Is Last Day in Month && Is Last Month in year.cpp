

#include<iostream>

using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

struct str_Date
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};
short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;
	int days[12] = { 31,28,31,30,31,30,31,31,30    ,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInAMonth(i, Year);
	}

	return TotalDays += Day;
}

bool IsLastDayInMonth(str_Date Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}
short ReadDay(str_Date Date)
{
	short Day;
	do
	{
		cout << "\nPlease enter a Day? ";
		cin >> Day;
	} while (Day <= 0 || Day > NumberOfDaysInAMonth(Date.Month, Date.Year));
	return Day;
}
short ReadMonth()
{
	short Month;
	do
	{
		cout << "\nPlease enter a Month? ";
		cin >> Month;
	} while (Month <= 0 || Month > 12);
	return Month;
}
short ReadYear() {
	short Year;
	do
	{
		cout << "\nPlease enter a Year? ";
		cin >> Year;
	} while (Year <= 0 || Year > 50000);
	return Year;
}
str_Date ReadFullDate()
{
	str_Date Date;
	Date.Year = ReadYear();
	Date.Month = ReadMonth();
	Date.Day = ReadDay(Date);
	
	
	return Date;
}

short ReadDaysToAdd()
{
	short DaystoAdd;
	do
	{
		cout << "\nPlease enter Days To Add? ";
		cin >> DaystoAdd;
	} while (DaystoAdd <= 0);
	return DaystoAdd;
}

int main() {

	str_Date Date = ReadFullDate();
	

	if (IsLastDayInMonth(Date))
	{
		cout << "\nYes Is The Last Day In Month.\n";
	}
	else
		cout << "\nNo Is Not The Last Day In Month.\n";

	if (IsLastMonthInYear( Date.Month))
	{
		cout << "\nYes Is The Last Month.\n";
	}
	else
		cout << "\nNo Is Not The Last Month.\n";

	


	system("pause>0");
	return 0;
}