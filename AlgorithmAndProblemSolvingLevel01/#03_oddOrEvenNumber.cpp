
#include <iostream>

using namespace std;

int ReadNumber() {
    int Number;
    cout << "enter number \n";
    cin >> Number;
    return Number;
}
string OddOrEven(int Number) 
{
    if (Number % 2 == 0) 
        return "Even number\n";
    else 
        return "Odd number\n";
}

int main() {
    cout << OddOrEven(ReadNumber());
    return 0;
}