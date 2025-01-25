
#include <iostream>

using namespace std;

void ChekPIN()
{
    int PIN = 0;
    int balance = 7500;
    int Trails = 3;
    do
    {
        cout << "\nEntree your PIN CODE : ";
        cin >> PIN;
        if (PIN == 1234) {
            cout << "\nyour Balance is : " << balance << endl;
            break;
        }
        Trails--;

        if (Trails != 0)
            cout << "\nWrang PIN, You Have " << Trails << " Trails Left." << endl;

    } while (Trails > 0);

    if (PIN != 1234 && Trails == 0)
        cout << "\nyour card is locked!";

}
int main()
{
    ChekPIN();
    return 0;
}