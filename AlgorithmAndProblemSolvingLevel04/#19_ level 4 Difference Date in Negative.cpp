#pragma warning(disable : 4996)

#include <iostream>
#include<ctime>
using namespace std;

bool IsLeabYear(int Year)
{
	return((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}
short NumberOfDaysInMonth(short year, short month)
{
	if (month < 1 || month>12)
	{
		return 0;
	}

	short arrNumberOdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeabYear(year) ? 29 : 28) : arrNumberOdays[month];
}
struct stDate
{
	short Day;
	short Month;
	short Year;
};
bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsLastDayInMonth(stDate Date)
{

	return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));

}
bool IsLastMonthInYear(short month)
{
	return month == 12;
}
stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;

}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
	int Days = 0; 
	short SawpFlagValue = 1;
	if (!IsDate1BeforeDate2(Date1, Date2)) 
	{ //Swap Dates     
		SwapDates(Date1, Date2);    
		SawpFlagValue = -1;    
	} 
	while (IsDate1BeforeDate2(Date1, Date2))   
	{        
		Days++; 
		Date1 = IncreaseDateByOneDay(Date1); 
	} 
	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue; 
}

short ReadDay()
{
	short day = 0;
	do {
		cout << "Please enter day ? ";
		cin >> day;
	} while (day > 31 || day < 1);
	return day;
}
short ReadMonth()
{
	short Month;
	do {
		cout << "Please enter a Month? ";
		cin >> Month;
	} while (Month > 12 || Month < 1);
	return Month;
}
short ReadYear()
{
	short year;
	do {
		cout << "Please enter year? ";
		cin >> year;
	} while (year < 1);
	return year;
}
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}
stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}
int main()
{
	
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	cout << "Difference is :" << GetDifferenceInDays(Date1, Date2) << " day(s)" << endl;
	cout << "Difference (include end Day) is :" << GetDifferenceInDays(Date1, Date2 ,true) << " day(s)" << endl;

}