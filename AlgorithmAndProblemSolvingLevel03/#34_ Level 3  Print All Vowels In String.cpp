// #34 Level 3  Print All Vowels In String



#include <iostream>
#include <string>

using namespace std;


bool IsVowel(char Ch1)  // PROF
{
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}

void PrintVowelsInString(string text)
{

    for (short i = 0; i < text.length(); i++)
    {
        if (IsVowel(text[i]))
            cout << text[i] << "   ";
    }
    
}

int main()
{
    string text = ReadString();

    cout << "\nVowels In This String are :  ";
    PrintVowelsInString(text);

    system("pause>0");

}

