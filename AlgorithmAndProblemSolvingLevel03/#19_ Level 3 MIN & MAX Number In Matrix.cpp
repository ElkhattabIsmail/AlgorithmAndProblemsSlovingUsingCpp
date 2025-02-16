
#include <iostream>
#include <cstdlib>
using namespace std;


void printMatrix(int arr[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			printf(" %0*d\t", 2, arr[i][j]);
		}

		cout << "\n";
	}

	cout << endl;
}

int MaxNumberInMatrix(int arr[3][3], short rows, short cols)
{
	int MAX = arr[0][0];

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (arr[i][j] > MAX)
			{
				MAX = arr[i][j];
			}
				
		}
	}
	return MAX;
}
int MinNumberInMatrix(int arr[3][3], short rows, short cols)
{
	int MIN = arr[0][0];

	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (arr[i][j] < MIN)   // arr first ???
			{
				MIN = arr[i][j];
			}

		}
	}
	return MIN;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {    // 9 5 0 

		{ 1,2,17 },
		{ 38,9,7 },
		{ 10,10,100 }  };

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);
	

	cout << "MAX Number In Matrix is : "<< MaxNumberInMatrix(arr, 3, 3);
	cout << "\nMin Number In Matrix is : " << MinNumberInMatrix(arr, 3, 3);
	system("pause>0");
}