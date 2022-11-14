#include <iostream>

using namespace std;

void printAllKLengthRec(char set[], string prefix,
                        int n, int k)
{

    if (k == 0)
    {
        cout << (prefix) << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + set[i];
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
}

void printAllKLength(char set[], int k, int n)
{
    printAllKLengthRec(set, "", n, k);
}

int main()
{
    char set[] = {'0', '1'};
    int k = 3;
    printAllKLength(set, k, 2);
}
