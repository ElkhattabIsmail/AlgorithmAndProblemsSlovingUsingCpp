

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

str_Date GetDateFromNumberOfDays(short DaysNumber, short Year)
{
	str_Date Date;

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
str_Date GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	str_Date Date;

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

str_Date DateAddDays(short Days, str_Date Date) 
{ 
	short TotalDays = Days + NumberOfDaysFromTheBeginingOfTheYear (Date.Day, Date.Month, Date.Year);

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
str_Date ReadFullDate() 
{
	str_Date Date;  
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
	} while (DaystoAdd <= 0 );
	return DaystoAdd;
}

int main() {

	str_Date Date;
	Date = ReadFullDate();
	short Days = ReadDaysToAdd();

	Date = DateAddDays(Days, Date);
	
	cout << "\n\nDate After Adding  [" << Days << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
	return 0;
}