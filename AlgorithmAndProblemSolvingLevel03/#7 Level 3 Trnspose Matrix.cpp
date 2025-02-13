#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

void fill_matrix_from1To9(int matrix_of[3][3], short rows, short cols)
{
    short count = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix_of[i][j] = count;
            count++;
        }

    }
}
void print9_9_OrderMatrix(int matrix_of[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(1) << matrix_of[i][j] << "\t";
        }
        cout << endl;
    }
}
void FillTrnsposedMatrix(int matrix_of[3][3], short rows, short cols)
{
    short count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix_of[j][i] = matrix_of[j][count];
        }
        count++;
    }
}
void PrintTrnsposedMatrix(int matrix_of[3][3], short rows, short cols)
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(1) << matrix_of[j][i] << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int matrix_of[3][3];

    fill_matrix_from1To9(matrix_of, 3, 3);
    cout << "    3/3 matrix :\n\n";
    print9_9_OrderMatrix(matrix_of, 3, 3);

    FillTrnsposedMatrix(matrix_of, 3, 3);

    cout << "\n transposed matrix :\n\n";
    PrintTrnsposedMatrix(matrix_of, 3, 3);
}


