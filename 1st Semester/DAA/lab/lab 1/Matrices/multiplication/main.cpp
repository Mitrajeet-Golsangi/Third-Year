#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector<vector<int>> mat;

public:
    Matrix() {}

    Matrix(vector<vector<int>> data)
    {
        for (size_t i = 0; i < data.size(); i++)
        {
            for (size_t j = 0; j < data[i].size(); j++)
                mat[i][j] = data[i][j];
        }
    }

    Matrix operator*(Matrix const &m)
    {
        Matrix res = Matrix();
        for (int i = 0; i < m.mat.size(); i++)
        {
            for (int j = 0; j < m.mat[i].size(); j++)
            {
                res.mat[i][j] += mat[i][j] * m.mat[j][i];
            }
        }
        return res;
    }

    void display(string name)
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
};

int main()
{
    Matrix A = Matrix({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    });

    Matrix I = Matrix({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    });

    Matrix res = A * I;

    res.display("Result");

    return 0;
}