
#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
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



bool IS_Identity_Matrix(int arr[3][3], short rows, short cols)
{
	for ( int i = 0; i < rows ; i++)
	{
		for ( int j = 0 ; j < cols; j++)
		{
			if (i == j && arr[i][j] != 1)
				return false;//if condition true go out                  // Any False THe Loop Is Go Out And Return False 
			else if (i != j && arr[i][j] != 0)                          // OtherWays It Return True 
				return false;// if condition true go out 
		}
	}
	return true;  // if all conditions up is false return true 
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {
		{ 1,0,0 } , 
		{ 0,1,0 } ,
		{ 0,0,1 } };

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	if (IS_Identity_Matrix(arr, 3, 3))
		cout << "YES , IS An Identity Matrix...";
	else
		cout << "NO , ISn't An Identity Matrix...";

	system("pause>0");
}