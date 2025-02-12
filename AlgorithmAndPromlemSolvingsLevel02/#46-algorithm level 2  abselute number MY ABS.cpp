#include <iostream>
using namespace std;
float readnumber()
{
    int number = 0;
    cout << "enter a number: \n";
    cin >> number;
    return number;
}
float MYabs(float number)
{
    if (number >= 0)
        return number;
    else
        return number * -1;
}

int main()
{
    float number=  readnumber();
    cout << "MYabs : "<< MYabs(number);
    cout << "\nC++ abs : " << abs(number);
}

