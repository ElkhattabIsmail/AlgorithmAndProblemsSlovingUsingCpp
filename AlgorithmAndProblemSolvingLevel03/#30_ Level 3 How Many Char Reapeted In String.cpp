
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

short HowManyLetterRepeated(string text , char LetterYouFind)
{
    short count = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] == LetterYouFind)
            count++;
    }
    return count;
}

int main()
{
    string text = ReadString();
    char letter;
    cout << "Enter The Letter That You Count It : ";
    cin >> letter;

    printf("Letter '%*c' Repeated ", 1, letter);
    cout << HowManyLetterRepeated(text, letter)<<" Times.";
    
}

