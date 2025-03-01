
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
stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
	}
	else
		Date.Day--;

	return Date;
}
stDate Decrease_X_DaysToDate(stDate Date, short HowManyDaysToDecrease)
{
	for (short i = 0; i < HowManyDaysToDecrease; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate Decrease1WeekToDate(stDate Date)
{
	for (short i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}
stDate Decrease10WeekToDate(stDate Date)
{
	for (short i = 0; i < 10; i++)
	{
		Date = Decrease1WeekToDate(Date);
	}
	return Date;
}

stDate Decrease1MonthToDate(stDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	short NumberDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	if (Date.Day > NumberDaysInCurrentMonth)
	{
		Date.Day = NumberDaysInCurrentMonth;
	}
	return Date;
}


stDate Substracting5MonthFromDate(stDate Date)
{
	for (short i = 0; i < 5; i++)
	{
		Date = Decrease1MonthToDate(Date);
	}
	return Date;
}
stDate Decrease1YearToDate(stDate Date)
{
	Date.Year--;
	return Date;
}
stDate Decrease10YearToDate(stDate Date)
{
	for (short i = 0; i < 10; i++)
	{
		Date = Decrease1YearToDate(Date);
	}
	return Date;
}
stDate DecreaseXYearToDateInFasterWay(stDate Date, short year)
{
	Date.Year -= year;
	return Date;
}
stDate Decrease1DecadeToDate(stDate Date)
{
	Date.Year -= 10;
	return Date;
}
stDate Decrease10Decades(stDate Date)
{
	for (short i = 0; i < 10; i++)
	{
		Date = Decrease1DecadeToDate(Date);
	}
	return Date;
}
stDate DecreaseXDecades(stDate Date, short Dacades)
{
	for (short i = 0; i < Dacades * 10; i++)
	{
		Date = Decrease1YearToDate(Date);
	}
	return Date;
}
stDate DecreaseXDecadesFasterWay(stDate Date, short Dacades)
{
	Date.Year -= Dacades * 10;
	return Date;
}
stDate DecreaseCenturyToDate(stDate Date)
{
	Date.Year -= 100;
	return Date;
}
stDate Adding_MILLENNIUM(stDate Date)  // MILLENNIUM = 1000 Year
{
	Date.Year -= 1000;
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
		Date1 = DecreaseDateByOneDay(Date1);
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
	Date = DecreaseDateByOneDay(Date);
	cout << "Substracting one Day is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;

	Date = Decrease_X_DaysToDate(Date, 10);
	cout << "Substracting 10 Day is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease1WeekToDate(Date);
	cout << "Substracting One Week is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease10WeekToDate(Date);
	cout << "Substracting 10 Week is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;

	Date = Decrease1MonthToDate(Date);
	cout << "Substracting 1 Month is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Substracting5MonthFromDate(Date);
	cout << "Substracting 5 Month is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease1YearToDate(Date);
	cout << "Substracting One Year is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease10YearToDate(Date);
	cout << "Substracting 10 Or X Year is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = DecreaseXYearToDateInFasterWay(Date, 10);
	cout << "Substracting 10 Year (in faster Way) is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease1DecadeToDate(Date);
	cout << "Substracting One Decade is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Decrease10Decades(Date);
	cout << "Substracting 10 Decade is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = DecreaseXDecades(Date, 10);
	cout << "Substracting X Decade (in faster Way) is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = DecreaseCenturyToDate(Date);
	cout << "Substracting One Century is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
	Date = Adding_MILLENNIUM(Date);
	cout << "Substracting One MILLENNIUM is :" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
}