#include <iostream>

using namespace std;

int reverse(int, int);

int main()
{
    system("cls");
    int num, rev;

    cout << "Enter a Number : ";
    cin >> num;

    rev = reverse(num, 0);
    if (rev == num)
        cout << "Number is a Palindrome !";
    else
        cout << "Number is not a Palindrome !";

    return 0;
}

int reverse(int num, int temp)
{
    if (num == 0)
        return temp;
    else
    {
        temp = (num % 10) + (10 * temp);
        return reverse(num / 10, temp);
    }
}