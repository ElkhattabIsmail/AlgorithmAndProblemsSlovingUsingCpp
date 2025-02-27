
#include <iostream>
using namespace std;

short ReadYear()
{
    short Y = 0;
    cout << "Enter The Year For Check If a Leap Year Or Not ? \n";
    cin >> Y;
    return Y;
}
bool IsLeapYear(short Y)
{
    return Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0);
}
short YearToDays(short Year)
{
    return IsLeapYear(Year) ? 366 : 365 ;
}
short YearToHours(short Year)
{
    return YearToDays(Year) * 24;
}
int YearToMinutes(short Year)
{
    return YearToHours(Year) * 60;
}
int YearToSeconds(short Year)
{
    return YearToMinutes(Year) * 60;
}
int main()
{
    short Year = ReadYear();
    cout << "Number Of Days\t  in Year [" << Year << "] is " << YearToDays(Year) << endl;
    cout << "Number Of Hours\t  in Year [" << Year << "] is " << YearToHours(Year) << endl;
    cout << "Number Of Minutes in Year [" << Year << "] is " << YearToMinutes(Year) << endl;
    cout << "Number Of Seconds in Year [" << Year << "] is " << YearToSeconds(Year) << endl;
    system("pause");
    return 0;
}
