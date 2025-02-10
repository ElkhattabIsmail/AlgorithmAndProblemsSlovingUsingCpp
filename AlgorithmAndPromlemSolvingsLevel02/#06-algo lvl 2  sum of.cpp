#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0; do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}
void PrintDigits(int Number)
{
    int sum = 0;
    int  Remainder = 0;
    while (Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        sum+= Remainder;
    }
    cout << "total of all digits is " << sum << endl;
}
int main() {
    PrintDigits(ReadPositiveNumber("Please enter a positive number?")); return 0;
}