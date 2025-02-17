

//#32 Level 3  How Many Vowels In String

#include <iostream>
#include <string>

using namespace std;

char InvertChar(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

bool IsVowel(char Ch1)  // PROF
{
    Ch1 = tolower(Ch1);
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    cout << "  ";
    getline(cin, text);
    return text;
}
char ReadChar()
{
    char letter;
    cout << "Enter Your Char :  ";
    cin >> letter;
    return letter;
}
short HowManyVowelsInString (string text )
{

    short count = 0;

    for (short i = 0; i < text.length(); i++)
    {
        if (IsVowel(text[i]))
            count++;
    }
    return count;
}

int main()
{
    string text = ReadString();

    cout << " Number Of Vowels is : " << HowManyVowelsInString(text) ;

    system("pause>0");

}

