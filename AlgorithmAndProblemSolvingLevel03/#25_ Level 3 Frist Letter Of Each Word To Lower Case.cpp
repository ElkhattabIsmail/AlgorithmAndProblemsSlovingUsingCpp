
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}
string LowerFirstLetterOfEachWord(string S1) {
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";

    for (short i = 0; i < S1.length(); i++) {

        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}


int main()
{
   
    string text = LowerFirstLetterOfEachWord(ReadString());
    cout << text;


    system("pause>0");

}


