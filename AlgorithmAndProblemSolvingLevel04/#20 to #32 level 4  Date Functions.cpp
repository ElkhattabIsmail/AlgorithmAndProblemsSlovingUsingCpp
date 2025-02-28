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
stDate Increase_X_DaysToDate(stDate Date, int HowManyDaysToIncrease)
{
	for (short i = 0; i < HowManyDaysToIncrease; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
stDate Adding1WeekToDate(stDate Date)
{
	for (short i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}
stDate AddingXWeekToDate(stDate Date,short Weeks)
{
	for (short i = 0; i < Weeks; i++)
	{
		Date = Adding1WeekToDate(Date);
	}
	return Date;
}
stDate Adding1MonthToDate(stDate Date)
{
	if (Date.Month == 12) 
	{ 
		Date.Month = 1;
		Date.Year++;
	}
	else 
	{ 
		Date.Month++; 
	} 
	short NumberDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month );
	if (Date.Day > NumberDaysInCurrentMonth)
	{
		Date.Day = NumberDaysInCurrentMonth;
	}
	return Date; 
} 
  

stDate Adding5MonthToDate(stDate Date)
{
	for (short i = 0; i < 5; i++)
	{
		Date = Adding1MonthToDate(Date);
	}
	return Date;
}
stDate Adding1YearToDate(stDate Date)
{
	Date.Year++;
	return Date;
}
stDate Adding10YearToDate(stDate Date)
{
	for (short i = 0; i < 10; i++)
	{
		Date = Adding1YearToDate(Date);
	}
	return Date;
}
stDate AddingXYearToDateInFasterWay(stDate Date ,short year)
{
	Date.Year += year;
	return Date;
}
stDate Adding1DecadeToDate(stDate Date )
{
	Date.Year += 10;
	return Date;
}

stDate Adding10Decades(stDate Date,short Dacades)
{
	for (short i = 0; i < Dacades ; i++)
	{
		Date = Adding1DecadeToDate(Date);
	}
	return Date;
}
stDate AddingXDecades(stDate Date, short Dacades)
{
	for (short i = 0; i < Dacades * 10; i++)
	{
		Date = Adding1YearToDate(Date);
	}
	return Date;
}
stDate AddingXDecadesFasterWay(stDate Date, short Dacades)
{
	Date.Year += Dacades * 10;
	return Date;
}
stDate AddingCenturyToDate(stDate Date)
{
	Date.Year += 100;
	return Date;
}
stDate Adding_MILLENNIUM(stDate Date)  // MILLENNIUM = 1000 Year
{
	Date.Year = Date.Year + 1000;
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
stDate GetSystem_NewDate()
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
	stDate Date = ReadFullDate();
	
	cout << "\nDate After :\n\n";
	Date = IncreaseDateByOneDay(Date);
	cout << "Adding one Day is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Increase_X_DaysToDate(Date, 10);
	cout << "Adding 10 Day is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding1WeekToDate(Date);
	cout << "Adding One Week is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = AddingXWeekToDate(Date, 10);
	cout << "Adding 10 Week is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding1MonthToDate(Date);
	cout << "Adding 1 Month is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding5MonthToDate(Date);
	cout << "Adding 5 Month is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding1YearToDate(Date);
	cout << "Adding One Year is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding10YearToDate(Date);
	cout << "Adding 10 Or X Year is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = AddingXYearToDateInFasterWay(Date, 10);
	cout << "Adding 10 Year (in faster Way) is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding1DecadeToDate(Date);
	cout << "Adding One Decade is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding10Decades(Date, 10);
	cout << "Adding 10 Decade is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = AddingXDecades(Date, 10);
	cout << "Adding X Decade (in faster Way) is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = AddingCenturyToDate(Date);
	cout << "Adding One Century is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding_MILLENNIUM(Date);
	cout << "Adding One MILLENNIUM is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
}