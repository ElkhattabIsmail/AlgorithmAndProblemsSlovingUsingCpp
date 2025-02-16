
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
bool IsNumberExistInMatrix(short n, int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == n)
				return true;
		}
	}
	return false;
}
void IntersectedNumber(int arr[3][3], int arr2[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++)
		{
			if (IsNumberExistInMatrix(arr[i][j], arr2, rows, cols))
				printf("%0*d\t", 2, arr[i][j]);
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {    // 9 5 0 
		{ 1,2,17 },
		{ 38,9,7 },
		{ 0,10,8 }
	};
	int arr2[3][3] = {    // 9 5 0 
		{ 1,10,18 },
		{ 5, 9, 17 },
		{ 0,10,38 }
	};

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);
	cout << "\n Matrix 2 : \n";
	printMatrix(arr2, 3, 3);

	cout << "\nIntersected Numbers Are : \n";
	IntersectedNumber(arr, arr2, 3, 3);
	
	system("pause>0");
}