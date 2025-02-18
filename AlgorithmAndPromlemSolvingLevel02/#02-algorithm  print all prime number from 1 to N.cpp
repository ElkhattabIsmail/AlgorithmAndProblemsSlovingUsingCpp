#include <iostream>
using namespace std;
enum encheck_if_prime { prime=1,not_prime=2};
int readPpsitiveNumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
encheck_if_prime checkifprime(int number)
{
    int d = round(number / 2);    // divide number on number 1 until the half number   ex: 9%2.3,4.5
    //if found 9%2.3,4.5 == 0 it's prime
    for (int count = 2; count <= d; count++)
    {
        if (number % count == 0)
            return encheck_if_prime::not_prime;
    }
    return encheck_if_prime::prime;
}
void print_primeNumber(int number)
{
    
    
    for (int b = 1; b <= number; b++)
    {
        if (checkifprime(b) == encheck_if_prime::prime)
        {
            cout << b << " : its prime." <<endl;
        }
        
    }
    
}

int main()
{
    print_primeNumber(readPpsitiveNumber("enter a positive number:"));
    cout<<checkifprime(49);
}
