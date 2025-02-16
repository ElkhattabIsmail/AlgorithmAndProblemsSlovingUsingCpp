
#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
}


void fillMatrixWithRandomNumbers1(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = randomNumber(1, 10);
		}
	}
}
void fillMatrixWithRandomNumbers2(int arr[3][3], short rows, short cols)
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




bool AreMatricesTypical(int arr[3][3], int arr2[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			while (arr[i][j] != arr2[i][j])
			{
				return false;
				//break; without break it works fine
			}
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arr2[3][3];

	fillMatrixWithRandomNumbers1(arr, 3, 3);
	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	fillMatrixWithRandomNumbers1(arr2, 3, 3);
	cout << "\n Matrix 2 : \n";
	printMatrix(arr2, 3, 3);

	if (AreMatricesTypical(arr, arr2, 3, 3))
		cout << "\n The Matrices Are Topical.";
	else
		cout << "\n The Matrices Are Not Topical.";



	system("pause>0");
}