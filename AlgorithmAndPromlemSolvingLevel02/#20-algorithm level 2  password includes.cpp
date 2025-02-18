#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
// 65 to 90 print A TO Z
// 97 TO 122 PRINT SMALL a to 
// int c;    convert int to enum
//enCountryChoice Coutnry;
//cin >> c;
//Coutnry = (enCountryChoice)c;
enum encode { small = 1, capital = 2, digit = 3, special_charactere = 4 };
int randomNumber(int from, int to)
{
    //Function to generate a random number

    int  randNum = rand() % (to - from + 1) + from;
    return randNum;
}
char randomChar(encode code)
{    
    switch (code)
    {
    case 1:
        return char(randomNumber(97, 122));
        break;
    case 2:
        return char(randomNumber(65, 90));
        break;
    case 3:
        return char(randomNumber(48, 57));
        break;
    case 4:
        return char(randomNumber(91, 96));
        break;
    default:
        cout<<"error\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    cout << "small = 1, capital = 2, digit = 3, special_charactere = 4\n";
    int num;
    encode code;
    cin >> num;
    code = (encode)num;
    cout << randomChar(code) << endl;
    cout << randomChar(encode::capital) << endl;
    cout << randomChar(encode::special_charactere) << endl; 
    cout << randomChar(encode::digit)<< endl;
    return 0;
}
