
#include <iostream>
#include <string>
using namespace std;
// 65 to 90 upper
// 97 to 122 lower

char InvertChar(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}
char ReadChar()
{
    char letter;
    cout << "Enter Your Char :  \n";
    cin >> letter;
    return letter;
}
short HowManyLetterRepeated( string text, char LetterYouFind , bool All = true  )
{
  
    short count = 0;
    
    for (short i = 0; i < text.length(); i++)
    {
       
        if (All)  // count just small letter
        {
            if (text[i] == LetterYouFind)
                count++;
        }
        else 
        {
            if (tolower(text[i]) == tolower(LetterYouFind))
                count++;
        }
    
    }
    return count;
}

int main()
{
    string text = ReadString();
    char letter = ReadChar();

   
    cout <<"Letter '" <<letter << "' Repeated : "<< HowManyLetterRepeated(text, letter) << " Times.";

    cout << "\n\nLetter '" << letter << "' OR '" << InvertChar(letter) << "' Repeated : " 
         << HowManyLetterRepeated(text, letter, false) << " Times.";

    
 

}

