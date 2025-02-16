
#include <iostream>
#include <cstdlib>
using namespace std;


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


int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {    // 9 5 0 
		{ 1,2,3 },
		{ 5,9,7 },
		{ 0,10,8 }
	};

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	cout << "enter a number you search for it : ";
	short n;
	cin >> n;

	if (IsNumberExistInMatrix(n, arr, 3, 3))
		cout << "YES: The Number Is There.";
	else
		cout << "NO: Number Is NOT Exist.";
	

	system("pause>0");
}

