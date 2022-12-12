#include <iomanip>
#include <iostream>

#define WIDTH 10
#define TOTAL_PROC 4

using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int priority;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;

    process(int pid, int at, int bt, int priority)
    {
        this->pid = pid;
        this->at = at;
        this->bt = bt;
        this->priority = priority;
    }
};

void getMaxPriority(process p[], int current_time, int *is_completed, int *idx, int *mx)
{
    for (int i = 0; i < TOTAL_PROC; i++)
    {
        if (p[i].at <= current_time && is_completed[i] == 0)
        {
            if (p[i].priority > *mx)
            {
                *mx = p[i].priority;
                *idx = i;
            }

            if (p[i].priority == *mx)
            {
                if (p[i].at < p[*idx].at)
                {
                    *mx = p[i].priority;
                    *idx = i;
                }
            }
        }
    }
}

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
         << setw(WIDTH) << "Priority"
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
             << setw(WIDTH) << p[i].priority
             << setw(WIDTH) << p[i].st
             << setw(WIDTH) << p[i].ct
             << setw(WIDTH) << p[i].tat
             << setw(WIDTH) << p[i].wt
             << setw(WIDTH) << p[i].rt
             << endl;
    }
    drawLine();
}

int main()
{
    process p[] = {
        process(1, 0, 2, 1),
        process(2, 1, 2, 3),
        process(3, 2, 3, 5),
        process(4, 3, 1, 2),
    };

    int burst_time[TOTAL_PROC];
    int is_completed[TOTAL_PROC] = {0};

    int completed = 0;
    int current_time = 0;

    for (int i = 0; i < TOTAL_PROC; i++)
    {
        burst_time[i] = p[i].bt;
    }

    while (completed != TOTAL_PROC)
    {
        int idx = -1;
        int mx = -1;

        getMaxPriority(p, current_time, is_completed, &idx, &mx);

        cout << setw(WIDTH) << setfill((char)(idx + 49)) << " ";

        if (idx != -1)
        {
            // Check if process is getting CPU for first time
            if (p[idx].bt == burst_time[idx])
            {
                p[idx].st = current_time;
            }
            // Decrement burst time and increment current time
            burst_time[idx] -= 1;
            current_time++;

            // Actions todo if process has completed
            if (burst_time[idx] == 0)
            {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].rt = p[idx].st - p[idx].at;

                is_completed[idx] = 1;
                completed++;
            }
        }
        // If no process is present in ready queue increment the current time
        else
            current_time++;
    }

    display(p);
    return 0;
}