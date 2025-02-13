
#include <iostream>

using namespace std;

void ReadNumber(int num1, int num2)  {
    cout << "enter number 1 ";
    cin >> num1;
    cout << "enter number 2 ";
    cin >> num2;
}
void Swap(int &num1, int &num2) {
    int Temp;
    Temp = num1;
    num1 = num2;
    num2 = Temp;
}

void PrintNumberAfterSwap(int num1, int num2) {

    Swap(num1, num2);
    cout << "number 1 = " << num1 << "\nnumber 2 = " << num2 << endl;
}

int main()
{
    int nbr1, nbr2;
    ReadNumber(nbr1, nbr2);
    PrintNumberAfterSwap(nbr1, nbr2);
    return 0;
}