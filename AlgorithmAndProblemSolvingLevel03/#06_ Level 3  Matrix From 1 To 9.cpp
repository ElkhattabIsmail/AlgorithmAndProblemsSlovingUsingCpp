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
void print_matrix_with_RandomNumber(int matrix_of[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(3) << matrix_of[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int matrix_of[3][3];

    fill_matrix_from1To9(matrix_of, 3, 3);
    cout << "    3/3 matrix :\n\n";
    print_matrix_with_RandomNumber(matrix_of, 3, 3);
}


