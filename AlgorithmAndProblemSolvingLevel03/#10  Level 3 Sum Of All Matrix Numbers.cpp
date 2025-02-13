
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
int SumOfMattix(int arr[3][3], short rows, short cols)
{
	int sum = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];

	fillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	cout << "\n The Sum OF Matrix =  ";
	cout << SumOfMattix(arr , 3, 3);

	system("pause>0");
}