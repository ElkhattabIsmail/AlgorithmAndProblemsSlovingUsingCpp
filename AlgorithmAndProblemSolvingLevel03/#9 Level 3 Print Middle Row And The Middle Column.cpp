
#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
}


void fillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = randomNumber(1, 10);
		}
	}
}


void printMatrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf(" %0*d\t", 2, arr[i][j]);
		}

		cout << "\n";
	}

	cout << endl;
}


void printMiddleRowOfMatrix(int arr[3][3], short rows, short cols)
{
	short middleRow = rows / 2;

	for (int j = 0; j < cols; j++)
	{
		printf(" %0*d\t", 2, arr[middleRow][j]);
	}

	cout << endl;
}


void printMiddleColOfMatrix(int arr[3][3], short rows, short cols)
{
	short middleCol = cols / 2;

	for (int i = 0; i < rows; i++)
	{
		printf(" %0*d\t", 2, arr[i][middleCol]);
	}

	cout << endl;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	fillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n Matrix 1 : \n";

	printMatrix(arr, 3, 3);

	cout << "\n Middle Row of Matrix1 is : \n";
	printMiddleRowOfMatrix(arr, 3, 3);
	 
	cout << "\n Middle Column of Matrix1 is : \n";
	printMiddleColOfMatrix(arr, 3, 3);


	return 0;
}
