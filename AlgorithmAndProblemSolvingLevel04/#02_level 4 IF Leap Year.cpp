
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
    if (Y % 400 == 0)
    return true;
    else if (Y % 100 == 0)
        return false;
    else if (Y % 4 == 0)
        return true;
    else
        return false;
}
int main()
{
    short Year = ReadYear();
    if (IsLeapYear(Year))
        cout <<Year << " Yes Its a Leap Year.\n";
    else
        cout << Year << " Its Not a Leap Year.\n";
    system("\npause");
}
