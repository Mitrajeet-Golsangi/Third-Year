#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

#define WIDTH 10
#define TOTAL_PROC 4

struct process
{
    int pid;
    int at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;

    process(int pid, int at, int bt)
    {
        this->pid = pid;
        this->at = at;
        this->bt = bt;
    }
};

void drawLine()
{
    cout << left << setw(WIDTH * 9) << setfill('-') << "" << setfill(' ') << endl;
}

void display(process p[])
{
    cout << endl;
    drawLine();
    cout << left
         << setw(WIDTH) << "Process"
         << setw(WIDTH) << "AT"
         << setw(WIDTH) << "BT"
         << setw(WIDTH) << "ST"
         << setw(WIDTH) << "CT"
         << setw(WIDTH) << "TAT"
         << setw(WIDTH) << "WT"
         << setw(WIDTH) << "RT"
         << endl;
    drawLine();

    for (int i = 0; i < TOTAL_PROC; i++)
    {
        cout << left
             << setw(WIDTH) << p[i].pid
             << setw(WIDTH) << p[i].at
             << setw(WIDTH) << p[i].bt
             << setw(WIDTH) << p[i].st
             << setw(WIDTH) << p[i].ct
             << setw(WIDTH) << p[i].tat
             << setw(WIDTH) << p[i].wt
             << setw(WIDTH) << p[i].rt
             << endl;
    }
    drawLine();
}

bool arrivalTimeSort(process a, process b)
{
    return a.at < b.at;
}

int main()
{
    int time_quantum = 4;

    process p[] = {
        process(1, 0, 8),
        process(1, 1, 4),
        process(1, 2, 9),
        process(1, 3, 5),
    };

    // Sort the given processes according to arrival time
    sort(p, p + TOTAL_PROC, arrivalTimeSort);

    queue<int> q;
    q.push(0);

    int completed = 0;
    int current_time = 0;

    int burst_time[TOTAL_PROC] = {0};
    for (int i = 0; i < TOTAL_PROC; i++)
    {
        burst_time[i] = p[i].bt;
    }

    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != TOTAL_PROC)
    {
        int idx = q.front();
        q.pop();

        cout << setw(WIDTH) << setfill((char)(idx + 49)) << " ";

        // Check if the process is getting the CPU for first time
        if (burst_time[idx] == p[idx].bt)
        {
            if (p[idx].at < current_time)
                p[idx].st = current_time;
            else
                p[idx].st = p[idx].at;

            current_time = p[idx].st;
        }

        // Run the Process for the given time quantum if the burst time is greater than the time quantum
        if (burst_time[idx] - time_quantum > 0)
        {
            burst_time[idx] -= time_quantum;
            current_time += time_quantum;
        }
        else
        {
            current_time += burst_time[idx];
            burst_time[idx] = 0;
            completed++;

            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;
        }

        for (int i = 0; i < TOTAL_PROC; i++)
        {
            if (burst_time[i] > 0 && p[i].at <= current_time && mark[i] == 0)
            {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (burst_time[idx] > 0)
        {
            q.push(idx);
        }
        if (q.empty())
        {
            for (int i = 0; i < TOTAL_PROC; i++)
            {
                if (burst_time[i] > 0)
                {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
        display(p);
    }
    return 0;
}