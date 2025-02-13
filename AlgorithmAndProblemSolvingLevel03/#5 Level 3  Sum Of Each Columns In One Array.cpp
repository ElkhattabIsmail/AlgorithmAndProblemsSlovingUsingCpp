
#include<iostream> 
#include<string>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}

int ColumnSum(int arr[3][3], short ColsNumber, short Row)
{
	int Sum = 0;

	for (short j = 0; j < Row; j++)
	{
		Sum += arr[j][ColsNumber];
	}
	return Sum;
}

void GetEachColumnSumIn1Array (int arr[3][3],int arrSum[3] , short Cols)
{
	cout << "\nThe the following are the sum of each column in the matrix:\n";
	for (short i = 0; i < Cols; i++)
	{
		 arrSum[i] = ColumnSum(arr, i, Cols) ;
	}
}
void PrintColumnSumIn1Array(int arr[3][3], int arrSum[3], short Row)
{
	for (short j = 0; j < Row; j++)
	{
		cout << "The Sum Of Column " << j + 1 << " = " << arrSum[j]<<"\n";
	}
}
int main() { //Seeds the random number generator in C++, called only once     
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	GetEachColumnSumIn1Array(arr, arrSum, 3);
	PrintColumnSumIn1Array(arr, arrSum, 3);
	system("pause>0");
}