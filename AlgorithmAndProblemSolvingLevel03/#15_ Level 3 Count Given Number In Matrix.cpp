
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

short Count_Given_Number_inMatrix(short Number ,int arr[3][3], short rows, short cols)
{
	

	short count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == Number)
				count++;
		}
	}
	return count;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {    // 9 5 0 
		{ 9,0,5 } ,
		{ 5,9,0 } ,
		{ 0,9,9 } };

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	short Number = 0;
	cout << "Enter The Number You Wanna count It ?:  ";
	cin >> Number;

	cout << "Number "<<Number <<" count In Matrix : " <<   Count_Given_Number_inMatrix(Number, arr, 3, 3);


	system("pause>0");
}