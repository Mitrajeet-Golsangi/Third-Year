#include <iostream>
#include <iomanip>

using namespace std;

void transpose(int[3][3], int[3][3]);
void display(int[3][3], string);

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int mat_T[3][3];

    transpose(mat, mat_T);
    display(mat, "A");
    display(mat_T, "A Transpose");

    return 0;
}

void transpose(int a[3][3], int b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[j][i] = a[i][j];
        }
    }
}

void display(int mat[3][3], string name)
{
    cout << "Matrix " << name << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}