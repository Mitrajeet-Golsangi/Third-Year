/*
    Criterion   : Priority
    Mode        : Non - Preemptive

    --------------------------------------------------------------------------------------
      Process      Arrival Time     Burst Time      Priority     TAT     WT      RT
    --------------------------------------------------------------------------------------
        P1              0               2               1         -      -       -
        P2              1               1               3         -      -       -
        P3              2               3               5         -      -       -
        P4              3               1               2         -      -       -
    --------------------------------------------------------------------------------------

    Gantt Chart

    ---------------------------------------------------------------------------------------------------
    ****** P1 ******
                    ********** P3 **********
                                            ** P2 **
                                                    ** P4 **
    ---------------------------------------------------------------------------------------------------
    0       1       2       3       4       5       6       7       8       9       10      11      12


    ---------------------------------------------------------------------------------------------------------------------------------------
      Process      Arrival Time     Burst Time      Priority        Completion Time     TAT = CT - AT     WT = TAT - BT      Response Time
    ---------------------------------------------------------------------------------------------------------------------------------------
        P1              0               2               1                  2                  2                0                   0
        P2              1               1               3                  6                  5                4                   4
        P3              2               3               5                  5                  3                0                   0
        P4              3               1               2                  7                  4                3                   3
    ---------------------------------------------------------------------------------------------------------------------------------------

*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main()
{

    int n;
    struct process p[20];
    int is_completed[20];
    memset(is_completed, 0, sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout << "Enter the number of processes max[20]: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << setw(5) << ": ";
        cin >> p[i].arrival_time;

        cout << "Enter burst time of process " << i + 1 << setw(7) << ": ";
        cin >> p[i].burst_time;

        cout << "Enter priority of the process " << i + 1 << setw(5) << ": ";
        cin >> p[i].priority;

        p[i].pid = i + 1;
        cout << endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int idx = -1;
        int mx = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].priority > mx)
                {
                    mx = p[i].priority;
                    idx = i;
                }
                if (p[i].priority == mx)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_arrival_time = min(min_arrival_time, p[i].arrival_time);
        max_completion_time = max(max_completion_time, p[i].completion_time);
    }

    cout << setw(90) << setfill('-')
         << "-"
         << endl;

    cout << left << setfill(' ')
         << setw(10) << "P"
         << setw(10) << "AT"
         << setw(10) << "BT"
         << setw(10) << "PRI"
         << setw(10) << "ST"
         << setw(10) << "CT"
         << setw(10) << "TAT"
         << setw(10) << "WT"
         << setw(10) << "RT"
         << endl;
    cout << setw(90) << setfill('-')
         << "-"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setfill(' ')
             << setw(10) << p[i].pid
             << setw(10) << p[i].arrival_time
             << setw(10) << p[i].burst_time
             << setw(10) << p[i].priority
             << setw(10) << p[i].start_time
             << setw(10) << p[i].completion_time
             << setw(10) << p[i].turnaround_time
             << setw(10) << p[i].waiting_time
             << setw(10) << p[i].response_time
             << endl;
    }
    cout << setw(90) << setfill('-')
         << "-"
         << endl;
}