#include <iostream>

using namespace std;

void fibonacci(int, int, int);

int main()
{
    system("cls");

    int max;
    cout << "Enter the upper limit : ";
    cin >> max;

    fibonacci(1, 1, max);

    return 0;
}

void fibonacci(int prev, int current, int max)
{
    if (current >= max)
    return;
    else {
        if (prev == current == 1)
            cout << prev << " ";
            
        cout << current << " ";
        
        int temp_prev = current;
        current = prev + current;
        prev = temp_prev;

        return fibonacci(prev, current, max);
    }
}