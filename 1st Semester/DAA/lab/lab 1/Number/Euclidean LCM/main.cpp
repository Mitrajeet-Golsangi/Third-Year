#include <iostream>

using namespace std;

int gcd(int, int);
int lcm(int, int);

int main()
{
    system("cls");

    int a, b;

    cout << "Enter 1st number : ";
    cin >> a;
    cout << "Enter 2nd number : ";
    cin >> b;

    cout << "LCM is : " << lcm(a, b);

    return 0;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}