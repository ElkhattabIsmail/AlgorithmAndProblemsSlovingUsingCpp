#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
int randomNumber(int from , int to)
{
    //Function to generate a random number

    int  randNum = rand() % (to - from + 1) + from; 
    // or rand() % (to) + from; 
    return randNum;
}

int main()
{
    //Seeds the random number generator in C++, called only once   
    srand((unsigned)time(NULL));
    cout << rand() << endl;
    cout << rand() % (101)+1  << endl;
    cout << randomNumber(1, 3) << endl;     
  
    return 0;
}
