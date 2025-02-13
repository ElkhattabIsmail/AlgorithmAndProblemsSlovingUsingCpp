
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int random_number(int from, int to)
{
    int number = 0;
    number = rand() % (to)+from;
    return number;
}

void Fill_Matrix_N1(int matrix1_of[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix1_of[i][j] = random_number(1, 10);
        }
    }
}
void Fill_Matrix_N2(int matrix2_of[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix2_of[i][j] = random_number(1, 10);
        }
    }
}
void print_matrix_with_RandomNumber(int matrix_of[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d \t", 2, matrix_of[i][j]);
        }
        cout << endl;
    }
}

void Multip_Matrix_N1_and_N2(int matrix1_of[3][3] , int matrix2_of[3][3] , int result [3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1_of[i][j] * matrix2_of[i][j];
        }
        
    }
   
}
int main()
{
    srand((unsigned)time(NULL));
    int matrix1_of[3][3];
    int matrix2_of[3][3];
    int result[3][3];

    Fill_Matrix_N1(matrix1_of, 3, 3);
    cout << "\n 3/3 matrix n 1 :\n\n";
    print_matrix_with_RandomNumber(matrix1_of, 3, 3);

    Fill_Matrix_N1(matrix2_of, 3, 3);
    cout << "\n 3/3 matrix n 2 :\n\n";
    print_matrix_with_RandomNumber(matrix2_of, 3, 3);

    cout << "\n     Result :\n\n";
    Multip_Matrix_N1_and_N2(matrix1_of, matrix2_of, result, 3, 3);
    print_matrix_with_RandomNumber(result, 3, 3);
}

