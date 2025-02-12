#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    //Function to generate a random number

    int  randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 1; i <= arrLength; i++)
        arr[i] = randomNumber(1,3);

}
void PrintRandomArray(int arr[100], int arrLength)
{
    for (int i = 1; i <= arrLength; i++)
        cout << arr[i] << " ";

}
int main()
{
    int arr[100], arrLength;

    ReadArray(arr,arrLength);
    cout << "\nArray elements : ";
    PrintRandomArray(arr, arrLength);
}