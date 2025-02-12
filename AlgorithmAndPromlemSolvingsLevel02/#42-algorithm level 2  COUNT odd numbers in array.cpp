
#include<iostream>
using namespace std;
enum encheck { odd = 1, even = 2, all = 100 };
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
        arr[i] = RandomNumber(1, 100);
}
void PrintArray(int  arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
encheck num_type(int number)
{
    if (number % 2 == 0)
        return encheck::even;
    else if (number % 2 != 0)
        return encheck::odd;
    else
        return encheck::all;

}
int Count_OddNumbers(int arrSource[100],int arrLength) 
{
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        
        if (num_type(arrSource[i]) == encheck::odd)
            count++;  
    }
    return count;
}
int main() {
    srand((unsigned)time(NULL)); int arr[100], arrLength = 0, arr2Length = 0;

    FillArrayWithRandomNumbers(arr, arrLength);
    cout << "\nArray elements:\n";
    PrintArray(arr, arrLength);
    cout << "\nOdd numbers count is: ";
    cout << Count_OddNumbers(arr, arrLength);

    return 0;
}
