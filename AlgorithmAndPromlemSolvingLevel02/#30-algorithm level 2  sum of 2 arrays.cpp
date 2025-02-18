#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int RandomNumber(int From, int To)
{
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
void copyArray(int arrSource[100], int arrDestination[100], int arrLength )
{
	
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSource[i];
	}
	
}
void sumOF2Arrays(int arrsum[100], int arrSource[100], int arrDestination[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{
		arrsum[i] = arrSource[i] + arrDestination[i];
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{    
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arrsum[100],arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	copyArray(arr, arr2, arrLength);
	sumOF2Arrays(arrsum, arr, arr2, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nPrime Numbers in Array2:\n";
	PrintArray(arr2, arrLength);

	cout << "\nsum of array 1 and array 2:\n";

	PrintArray(arrsum, arrLength);

	return 0;
}