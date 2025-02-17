
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  ";
    getline(cin, text);
    return text;
}
void PrintFirstLetterOfEachWord(string S1) 
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
}


int main()
{

    PrintFirstLetterOfEachWord(" First letters of this string:");

    system("pause>0");

}

