

#include<iostream>

using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

struct stDate
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
stDate GetDateFromNumberOfDays(short DaysNumber, short Year)
{
	stDate Date;

	Date.Year = Year;

	for (short i = 1; i <= 12; i++)
	{
		if (DaysNumber <= 31)
		{
			Date.Month = i;
			Date.Day = DaysNumber;
			break;
		}
		else
		{
			DaysNumber -= NumberOfDaysInAMonth(i, Year);

			if (DaysNumber <= 31)
			{
				Date.Month = ++i;
				Date.Day = DaysNumber;
				break;
			}
		}
	}
	return Date;
}
stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	stDate Date;

	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1;

	while (true) {

		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}
stDate DateAddDays(short Days, stDate Date)
{
	short TotalDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

	short NumberOfDaysInMonth = 0;
	Date.Month = 1;

	while (true)
	{
		NumberOfDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (TotalDays > NumberOfDaysInMonth)
		{
			TotalDays -= NumberOfDaysInMonth;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = TotalDays; //Romaining Days
			break;
		}
	}
	return Date;
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true :
		((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
			(Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}
bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}
bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}
bool IsDatesAreEquals(stDate Date1, stDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
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
			? Date1.Day < Date2.Day : false)) : false); }
int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false) { 
	int Days = 0; 
	while (IsDate1BeforeDate2(Date1, Date2)) 
	{ 
		Days++; 
		Date1 = IncreaseDateByOneDay(Date1);
	} 
	return IncludeEndDay ? ++Days : Days; 
}

stDate AddOneDayToDate(stDate Date)
{

	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day = 1;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
		Date.Day++;

	return Date;
}
short ReadDay()
{
	short Day;
	do
	{
		cout << "\nPlease enter a Day? ";
		cin >> Day;
	} while (Day <= 0 || Day > 31);
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
stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
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

	stDate Date1 = ReadFullDate();
	cout << "\n";
	stDate Date2 = ReadFullDate();

	int DifferenceDays = GetDifferenceInDays(Date1, Date2);

	cout << "\nDifference is " << DifferenceDays << " Day(s)";
	cout << "\nDifference (include end Day) is " << GetDifferenceInDays(Date1, Date2,true) << " Day(s)";

	system("pause>0");
	return 0;
}