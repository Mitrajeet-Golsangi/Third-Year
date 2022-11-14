#include <iostream>

using namespace std;

int check_prime(int, int);

int main()
{
    int n;
    cout << "Enter the higher limit : ";
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (check_prime(2, i) == 0)
            cout << i << " ";
    }

    return 0;
}

int check_prime(int i, int n)
{
    if (n == i)
        return 0;
    else if (n % i == 0)
        return 1;
    else
    {
        return check_prime(i + 1, n);
    }
}