

#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string text = "";
    cout << "Enter Your String :  \n";
    getline(cin, text);
    return text;
}
 //  el khattab ismail
void  PrintEachWordInString01 ( string text )
{
    string word;
    string spaces = "";
    short pos = 0;
    while (pos = text.find(spaces) != std::string::npos)
    {
        
    }
}
void PrintEachWordInString(string S1) 
{
    
    string delimeter = " ";                              // delimiter 

    cout <<"\nYour string words are: \n\n"; 
    short pos = 0; 
    string sWord;                     // define a string variable  
                                                    // use find() function to get the position of the delimiters  
      while (( pos = S1.find(delimeter)) != std::string::npos)  //  No position
      {
          sWord =S1.substr (0 , pos); 
          // store the word   
          if (sWord != "")         
          {             
              cout << sWord << endl;         
          } 
          S1.erase(0, pos + delimeter.length());  /* erase() until position and move to next word. */    
      } 
      if (S1!="")     
      {         
          cout <<S1<< endl; // it print last word of the string.   
      } 
} 

int main()
{
    string text = ReadString();
    

    PrintEachWordInString(text);
    
   
    system("pause>0");

}

