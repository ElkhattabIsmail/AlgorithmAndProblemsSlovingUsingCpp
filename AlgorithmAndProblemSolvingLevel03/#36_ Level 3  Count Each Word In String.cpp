// #36 Level 3  Count Each Word In String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


short CountEachWordInString( string S1)
{

    string delimeter = " ";                              // delimiter 
    short Count = 0;
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord;                     // define a string variable  
    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(delimeter)) != std::string::npos)  //  No position
    {
        sWord = S1.substr(0, pos);
        // store the word   
        if (sWord != "")
        {
            Count++;
        }
        S1.erase(0, pos + delimeter.length());  /* erase() until position and move to next word. */
    }
    if (S1 != "")
    {
        Count++; // it print last word of the string.   
    }
    return Count;
}
string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}
int main()
{
    string text = ReadString();


    cout<< "Number Of Word In String is : "<<CountEachWordInString(text);


    system("pause>0");

}


