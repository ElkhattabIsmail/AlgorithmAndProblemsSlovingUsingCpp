#include <iostream>
using namespace std;
void title_Table()
{
    cout << "\n\n\n\t\t\t Multuplication table from 1 to 10\n\n";
    cout << "\t";

    for (int j = 1; j <= 10; j++)
    {
        cout << j<<"\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}
string column10(int j)
{
    if (j < 10)
        return "    |";
    else
        return "   |";
}

void PrintMultiplication_table()
{
    title_Table();
    for (int a = 1; a <= 10; a++)
    {
        cout << a << column10(a) <<"  ";
        for (int b = 1; b <= 10; b++)
        {
            cout << a * b << "\t";
        }
        cout << endl;
    }
       
}
int main()
{
    PrintMultiplication_table();
}

