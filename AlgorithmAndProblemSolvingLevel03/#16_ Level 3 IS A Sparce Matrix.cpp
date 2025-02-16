
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

short CountNumberInMatrix(short number, int arr[3][3], short rows, short cols)
{
	short count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == number)
				count++;
		}
	}
	return count;
}
bool IsSparceMatrix( int arr[3][3], short rows, short cols)
{
	short AllElement = rows* cols;
	return   CountNumberInMatrix(0, arr, 3 , 3) > (AllElement / 2);

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3] = {    // 9 5 0 
		{ 9,0,0 },
		{ 0,9,0 },
		{ 0,9,1 } 
	};

	cout << "\n Matrix 1 : \n";
	printMatrix(arr, 3, 3);

	if (IsSparceMatrix( arr, 3,3))
		cout << "YES: It Is Sparce ";
	else
		cout << "NO: It Is NOT Sparce ";

	system("pause>0");
}

