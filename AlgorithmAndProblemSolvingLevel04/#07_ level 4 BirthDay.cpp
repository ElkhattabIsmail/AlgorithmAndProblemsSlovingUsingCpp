
#include<iostream>
using namespace std;


void GetBirthDay(short Y, short M, short d)
{
	short a = (14 - M) / 12;
	Y = Y - a;
	M = M + (12 * a) - 2;

	string Days[7] = {"Sunday","Monday","Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };
	
	short Birthday = (d + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	cout << "Day Order : " << Birthday << endl;
	cout << "Day Name : " << Days[Birthday] << endl;
}

short DayOfWeekOrder(short Day, short Month, short Year) {
	short a, y, m;      
	a = (14 - Month) / 12;   
	y = Year - a;    
	m = Month + (12 * a) - 2; 
	// Gregorian://0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7; 
} 
string DayShortName(short DayOfWeekOrder) { 
	string arrDayNames[] = { "Sunday","Monday","Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };
	return arrDayNames[DayOfWeekOrder]; 
} 

short ReadDay() { 
	short Day;     
	cout << "\nPlease enter a Day? ";    
	cin >> Day;
	return Day; 
} 
short ReadMonth() { 
	short Month;    
	cout << "\nPlease enter a Month? ";  
	cin >> Month; 
	return Month; 
} 
short ReadYear() { 
	short Year;    
	cout << "\nPlease enter a year? ";    
	cin >> Year; 
	return Year; 
} 

int main() { 

	short Year = ReadYear(); 
	short Month = ReadMonth(); 
	short Day = ReadDay();    

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year;   
	cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);   
	cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));

	system("pause>0");
	return 0;
}