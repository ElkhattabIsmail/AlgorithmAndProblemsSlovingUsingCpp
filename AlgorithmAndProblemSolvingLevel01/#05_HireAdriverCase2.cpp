
#include <iostream>

using namespace std;

struct stInfo {
    int age;
    bool HasDriverLicence;
    bool HasRecomandation;
};

stInfo ReadDriverInfo() {
    stInfo info;
    cout << "please enter your age : ";
    cin >> info.age;

    cout << "\nyou have a driver licence ? (yes = 1 ; no = 0) :";
    cin >> info.HasDriverLicence;
    cout << "\ndo you have recomendation ? (yes = 1 ; no = 0) :";
    cin >> info.HasRecomandation;
    return info;
}

bool ft_IsAccept(stInfo info) {
    if (info.HasRecomandation)
        return true;
    else
        return (info.age > 21 && info.HasDriverLicence == true);
}


int main() {
    stInfo info = ReadDriverInfo();
    if (ft_IsAccept(info))
        cout << "\nHired";
    else
        cout << "\nRejected";

    return 0;
}