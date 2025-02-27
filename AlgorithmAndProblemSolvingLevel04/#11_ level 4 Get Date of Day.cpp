

#include<iostream>

using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
struct str_Date
{
	short Days = 0;
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

str_Date GetDateFromNumberOfDays (short DaysNumber , short Year) 
{
	str_Date Date;

	for (short i = 1; i <= 12; i++)
	{
		if (DaysNumber <= 31)
		{
			Date.Month = i;
			Date.Days = DaysNumber;
			break;
		}
		else
		{
			DaysNumber -= NumberOfDaysInAMonth(i, Year);

			if (DaysNumber <= 31)
			{
				Date.Month = ++i;
				Date.Days = DaysNumber;
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
			Date.Days = RemainingDays;
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
int main() {

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysNumber = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);

	cout << "\nNumber of Days From of The Begining of The Year Is :" << DaysNumber;

	str_Date Date;

	Date = GetDateFromNumberOfDays(DaysNumber, Year);
	cout << "\n\nDate of [" << DaysNumber << "] is : " << Date.Days << "/" << Date.Month << "/" << Year << endl;
	
	system("pause>0");
	return 0;
}