

#include <iostream>
#include <string>
using namespace std;
// 65 to 90 upper
// 97 to 122 lower

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}
char InvertChar(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}
string InvertAllStringLetter(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        text[i] = InvertChar(text[i]);
    }
    return text;
}

int main()
{
    string text = ReadString();
  
    text = InvertAllStringLetter(text);
    cout << "after inverted string \n";
    cout << text;
}

