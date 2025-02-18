#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int ReadPositiveNumber(string text)
{
	int n;
	do
	{
		cout << text << endl;
		cin >> n;
	} while (n <= 0);
	return n;
}
int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int arrLength) 
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
	cout << "\n";
}

void getNumberPosition(int arr[100], int arrLength, int numTOfind)
{
	// number index
	int numINDEX = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == numTOfind)
		{
			numINDEX = i;
			cout << "the number found at position: " << i << "\n";
			cout << "the number found its order: " << i + 1 << "\n";
		}
	}
	if (arr[numINDEX] != numTOfind)
		cout << "the number is not found :-(\n";


}
void PrintArray(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << "\n";
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100],arrLength=0;
	arrLength = ReadPositiveNumber("enter a number:");

	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array 1 elements:  ";
	PrintArray(arr, arrLength);

	int numTOfind = 0;
	numTOfind= ReadPositiveNumber("\nplease enter a number to search for ? :");
	cout << "\nnumber you are looking for is: " << numTOfind << "\n";

	getNumberPosition(arr, arrLength, numTOfind);

	return 0;
}
