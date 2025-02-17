

#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
    char letter;
    cout << "Enter a Letter :  \n";
    cin >> letter;
    return letter;
}
bool IsVowel(char Ch1) 
{ 
    Ch1 = tolower(Ch1); // Normalize Text
    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u')); 
}
bool Is_a_Vowel(char letter)
{
    char Vowels[5] = { 'a','e','i','o','u' };

    for (short i = 0; i < 5; i++)
    {
        if (letter == Vowels[i] || letter == toupper(Vowels[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char letter = ReadChar();

    if (IsVowel(letter))
        cout << letter << " Is a Vowel.";
    else
        cout << letter << " Is Consonant.";

    system("pause > 0");
}

