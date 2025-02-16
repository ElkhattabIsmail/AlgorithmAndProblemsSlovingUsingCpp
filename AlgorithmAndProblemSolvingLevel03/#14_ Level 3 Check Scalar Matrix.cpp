
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



bool IS_Scalar_Matrix(int arr[3][3], short rows, short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			// get first value of matrix
		    short First_Value_Diagonal = arr[0][0];

			if (i == j && arr[i][j] != First_Value_Diagonal)
				return false; 

			else if (i != j && arr[i][j] != 0)                          
				return false; 
		}
	}
	return true;  // if all conditions up is false return true  "is a scalar matrix" 
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {
		{ 9,0,0 } ,
		{ 0,9,0 } ,
		{ 0,0,9 } };

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	if (IS_Scalar_Matrix(arr, 3, 3))
		cout << "YES , IS An Scalar Matrix...";
	else
		cout << "NO , ISn't An Scalar Matrix...";

	system("pause>0");

}