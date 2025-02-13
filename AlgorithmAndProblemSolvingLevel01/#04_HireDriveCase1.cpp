
#include <iostream>

using namespace std;

struct stinfo {
    int age;
    bool HasDriverLicence;
};

stinfo ReadDriverInfo() {
    stinfo info;
    cout << "please enter your age : ";
    cin >> info.age;
    cin.ignore(1, '\n');
    cout << "you have a driver licence ? (yes = 1 ; no = 0)";
    cin >> info.HasDriverLicence;
    return info;
}

bool IsAccepted(stinfo info) {
    return (info.age > 21 && info.HasDriverLicence == 1);
}


int main() {
    stinfo info = ReadDriverInfo();
    if (IsAccepted(info))
        cout << "Hired";
    else
        cout << "Refected";
    return 0;
}