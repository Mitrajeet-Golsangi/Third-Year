/*
    Criterion   : Arrival Time
    Mode        : Non - Preemptive

    --------------------------------------------------------------------------------------
      Process      Arrival Time     Burst Time   Completion Time     TAT     WT      RT
    --------------------------------------------------------------------------------------
        P1              0               2               -             -      -       -
        P2              1               2               -             -      -       -
        P3              5               3               -             -      -       -
        P4              6               4               -             -      -       -
    --------------------------------------------------------------------------------------

    Gantt Chart

    ---------------------------------------------------------------------------------------------------
    ****** P1 ******
                    ****** P2 ******
                                    - Idle -
                                            ********** P3 **********
                                                                    ************** P3 ***************
    ---------------------------------------------------------------------------------------------------
    0       1       2       3       4       5       6       7       8       9       10      11      12


    --------------------------------------------------------------------------------------------------------------------
      Process      Arrival Time     Burst Time   Completion Time     TAT = CT - AT     WT = TAT - BT      Response Time
    --------------------------------------------------------------------------------------------------------------------
        P1              0               2               2                  2                0                   0
        P2              1               2               4                  3                1                   1
        P3              5               3               8                  3                0                   0
        P4              6               4               12                 6                2                   2
    --------------------------------------------------------------------------------------------------------------------

*/

#include <iomanip>
#include <iostream>

#define WIDTH 20

using namespace std;

int main()
{
    int n, at[20], bt[20], wt[20], tat[20], i, j;

    cout << "Enter total number of processes(maximum 20):";
    cin >> n;

    cout << "\nEnter Process Burst Time\n";
    for (i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "]:";
        cin >> bt[i];
    }

    wt[0] = 0; // waiting time for first process is 0

    // calculating waiting time
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    cout << left << endl
         << setw(WIDTH) << "Process"
         << setw(WIDTH) << "Burst Time"
         << setw(WIDTH) << "Waiting Time"
         << "Turnaround Time";
    cout << endl
         << setw(4 * WIDTH) << setfill('-')
         << "-";
    // calculating turnaround time
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        cout << setfill(' ') << left << endl
             << setw(WIDTH) << i + 1
             << setw(WIDTH) << bt[i]
             << setw(WIDTH) << wt[i]
             << tat[i];
    }

    cout << endl
         << setw(4 * WIDTH) << setfill('-')
         << "-" << endl;

    return 0;
}