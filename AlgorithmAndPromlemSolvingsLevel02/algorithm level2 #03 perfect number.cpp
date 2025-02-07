#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number=0;
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
    for (int I = 1; I <= d; I++)
    {
        if (number % I == 0)
            sum += I;
    }
    return number == sum;
}
void printNumberType(int number)
{
    if (checkifPerfect(number))
        cout <<"\n"<< number << " is a perfect number\n";
    else
        cout << "\n" << number << " is NOT a perfect number\n";
}




int main()
{
    printNumberType(readPositiveNumber("a number pls:"));
}
