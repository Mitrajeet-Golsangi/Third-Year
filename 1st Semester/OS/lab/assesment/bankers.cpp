#include <iomanip>
#include <iostream>

using namespace std;

#define WIDTH 10
const int n = 5; // number of processes
const int m = 3; // number of resources

int main()
{
    int allocation[n][m] = {{0, 1, 0}, // Allocation Matrix
                            {2, 0, 0},
                            {3, 0, 2},
                            {2, 1, 1},
                            {0, 0, 2}}; // Each row represents a process

    int max[n][m] = {{7, 5, 3}, // MAX Matrix
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}}; // Maximum resources that can be allocated

    int need[n][m] = {0};
    int available[m] = {3, 3, 2};

    // calculate need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int result[n] = {0};
    int ans[n] = {0};
    int idx = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (result[i] == 0)
            {

                bool satisfied = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        satisfied = false;
                        break;
                    }
                }

                // If the process is satisfied add it to completed queue and put its resources as available
                if (satisfied)
                {
                    ans[idx++] = i;
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }
                    result[i] = 1;
                }
            }
        }
    }
    bool safe = true;
    for (int i = 0; i < n; i++)
    {
        if (result[i] == 0)
        {
            safe = false;
            cout << "Deadlock Exists in the System ! Last Execution was " << i;
            break;
        }
    }

    if (safe)
    {
        cout << "Safe execution sequence is : ";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << ans[i] << " -> ";
        }
    }
    return 0;
}