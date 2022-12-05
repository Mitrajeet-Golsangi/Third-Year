#include <iostream>
#include <iomanip>

using namespace std;

class MinMax
{
public:
    int min;
    int max;

    static int getMin(int a, int b)
    {
        return (a < b) ? a : b;
    }

    static int getMin(int a, int b, int c)
    {
        return getMin(getMin(a, b), c);
    }

    static int getMax(int a, int b)
    {
        return (a > b) ? a : b;
    }
};

void printDiagonal(int[3][3]);
void display(int[3][3], string);

int main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    display(mat, "A");
    cout << "\nDiagonal is\n";

    printDiagonal(mat);
    return 0;
}

void printDiagonal(int mat[3][3])
{
    int sc = 0;
    int sr = 0;
    int cnt = 0;

    for (int i = 1; i < 6; i++)
    {
        sc = MinMax::getMax(0, i - 3);
        sr = MinMax::getMin(3, i);

        cnt = MinMax::getMin(i, (3 - sc), 3);

        for (int j = 0; j < cnt; j++)
        {
            cout << left << setw(5) << mat[sr - j - 1][sc + j];
        }
        cout << endl;
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