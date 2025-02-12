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
        arr[i] = randomNumber(1, 100);

}
void PrintRandomArray(int arr[100], int arrLength)
{
    for (int i = 1; i <= arrLength; i++)
        cout << arr[i] << " ";
}
int MAX_numberIn(int arr[100], int arrLength)
{
    int max = 0;
    for (int i = 1; i <= arrLength; i++)
    {   
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int MIN_numberIn(int arr[100], int arrLength)
{
    int MIN = 0;
    MIN = arr[1];
    for (int i = 1; i <= arrLength; i++)
    {
        if ( arr[i] < MIN)
            MIN = arr[i];
    }
    return MIN;
}

int SUM_numberIn(int arr[100], int arrLength)
{
    int SUM = 0;
    for (int i = 1; i <= arrLength; i++)
    {
        SUM += arr[i];
    }
    return SUM;
}
float numbers_AVG(int arr[100], int arrLength)
{
    return (float)SUM_numberIn(arr, arrLength) / arrLength;
}
int main()
{
    int arr[100], arrLength;

    ReadArray(arr, arrLength);
    cout << "\nArray elements : ";
    PrintRandomArray(arr, arrLength);

    cout << "\nmax number : ";
    cout<<MAX_numberIn(arr, arrLength);

    cout << "\nMIN number : ";
    cout << MIN_numberIn(arr, arrLength);

    cout << "\nSUM of numbers : ";
    cout << SUM_numberIn(arr, arrLength);

    cout << "\nAVERAGE : ";
    cout << numbers_AVG(arr, arrLength);


}