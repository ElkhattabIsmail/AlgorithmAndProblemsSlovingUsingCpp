#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double MySqrt(long double Number)
{
    return powl(Number, 0.5);  // Use powl for long double precision
}

long double ReadNumber()
{
    long double Number;
    cout << "Please enter a number: ";
    cin >> Number;
    return Number;
}

int main()
{
    long double Number = ReadNumber();

    cout << fixed << setprecision(100);  // Display up to 15 decimal places
    cout << "My MySqrt Result: " << MySqrt(Number) << endl;
    cout << "C++ sqrt Result: " << sqrtl(Number) << endl; // Compare with C++ sqrt function

    return 0;
}
