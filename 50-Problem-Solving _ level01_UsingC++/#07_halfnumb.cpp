
#include <iostream>

using namespace std;

int Readnumber() {
    int num;
    cout << "please enter number : ";
    cin >> num;
    return num;
}

float ft_calculateHalfOfNumber(int num) {
    return (float)num / 2;
}

void PrintHalfOfNumber(int num) {
    string resoult = "half of number " + to_string(num) + " is " + to_string(ft_calculateHalfOfNumber(num));
    cout << resoult << endl;
}

int main() {
    PrintHalfOfNumber(Readnumber());
    return 0;
}