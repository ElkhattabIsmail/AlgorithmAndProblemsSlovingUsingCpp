#include <iostream>
using namespace std;

int readPpsitiveNumber(string message)
{
    int number = 0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}


bool checkifPerfect(int number)
{
    int sum = 0;
    int d = round(number / 2);
    for (int b = 1; b <= d; b++)
    {
        if (number % b == 0)
            sum += b;
    }
    return number == sum;
}
void printNumberType(int number)
{
    for (int b = 1; b <= number; b++)
    {
        if (checkifPerfect(b))
            cout << b << " \n";
        
    }
}




int main()
{
    printNumberType(readPpsitiveNumber("a number pls:"));
}
