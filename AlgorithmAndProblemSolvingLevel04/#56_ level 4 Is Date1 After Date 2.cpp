#pragma warning(disable : 4996)

#include <iostream>
#include<ctime>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};
bool IsLeabYear(int Year)
{
	return((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}
short NumberOfDaysInMonth(short month, short year)
{
	if (month < 1 || month>12)
	{
		return 0;
	}
	short arrNumberOdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (IsLeabYear(year) ? 29 : 28) : arrNumberOdays[month];
}

short DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(stDate Date)
{
	short a, y, m;
	a = (14 - Date.Month) / 12;
	y = Date.Year - a;
	m = Date.Month + (12 * a) - 2;
	// Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayName(short DayOfWeekOrder) {
	string arrDayNames[] = { "Sunday","Monday","Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };
	return arrDayNames[DayOfWeekOrder];
}
void GetDayDate(stDate Date)
{
	short DayOrder = DayOfWeekOrder(Date);
	cout << DayName(DayOrder) << " , "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";
}
bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}
stDate IncreaseDateByOneDay(stDate Date) {
	if (IsLastDayInMonth(Date)) {
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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ?
		(Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month
			? Date1.Day < Date2.Day : false)) : false);
}
bool IsDatesAreEquals(stDate Date1, stDate Date2);
bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !(IsDate1BeforeDate2( Date1,  Date2)) && !(IsDatesAreEquals(Date1, Date2));
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;

}

bool IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(stDate Date)
{
	short Day = DayOfWeekOrder(Date);
	return Day == 5 || Day == 6;
}

short VacationDays(stDate Date1, stDate Date2)
{
	short DaysCount = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if (!IsWeekEnd(Date1))
		{
			DaysCount++;
		}
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return DaysCount;
}
stDate ReturnVacationDateByNumberOfDays(stDate Date1, short VacationDays)
{
	for (short i = 0; i < VacationDays; i++)
	{
		if (IsWeekEnd(Date1))
		{
			i--;
		}
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return Date1;
}
stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;
	//in case the data  is weekend keep adding one day util you reach business day
	//we get rid of all weekends before the first business day

	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//here we increase the vacation dates to add all weekends to it.

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (IsWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//in case the return date is week end keep adding one day util you reach business day
	while (IsWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
}

bool IsBisunessDay(stDate Date)
{
	return !IsWeekEnd(Date);
}
short DaysUntilEndofWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

/*short DaysUntilEndofMonth(stDate Date)
{
	short DaysinThatMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
	return DaysinThatMonth - Date.Day;
}*/

short DaysUntilTheEndOfMonth(stDate Date, bool Way2 = false)
{
	if (!Way2)
	{
		stDate EndOfMonth;
		EndOfMonth.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		EndOfMonth.Month = Date.Month;
		EndOfMonth.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfMonth, true);
	}
	else
	{
		short UntileDays = 0;
		for (short i = Date.Day; i <= NumberOfDaysInMonth(Date.Month, Date.Year); i++)
		{
			UntileDays++;
		}
		return UntileDays;
	}
}
bool IsDatesAreEquals(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}
short DaysUntilTheEndOfYear(stDate Date, bool Way2 = false)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;
	short UntilEndYear = 0;
	if (!Way2)
	{
		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}
	else
	{
		while (!IsDatesAreEquals(Date, EndOfYearDate))
		{
			Date = IncreaseDateByOneDay(Date);
			UntilEndYear++;
		}
		return ++UntilEndYear;
	}
}

/*void SwapDates(stDate& Date1, stDate& Date2)
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
}*/
short ReadDay()
{
	short day = 0;
	do {
		cout << "\nPlease enter day ? ";
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
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes Date1 After Date2\n";
	else
		cout << "\nDate1 Not After Date2\n";





	system("pause");
}
