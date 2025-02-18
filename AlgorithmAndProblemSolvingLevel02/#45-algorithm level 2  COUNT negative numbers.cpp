#include<iostream>
using namespace std;
int RandomNumber(int From, int To) {
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(-100, 100);
}
void PrintArray(int  arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int Count_negativeNumbers(int arr[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {

        if (arr[i] < 0)
            count++;

    }
    return count;
}
int main() {
    srand((unsigned)time(NULL)); int arr[100], arrLength = 0, arr2Length = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nnegative numbers in the array is: ";
    cout << Count_negativeNumbers(arr, arrLength);

    return 0;
}





