#include <iomanip>
#include <iostream>

using namespace std;

#define TOTAL_PROC 4
#define WIDTH 10

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

void getShortestJob(process p[], int *idx, int *mn, int current_time, int *is_completed)
{
    for (int i = 0; i < TOTAL_PROC; i++)
    {
        if (p[i].at <= current_time && is_completed[i] == 0)
        {
            if (p[i].bt < *mn)
            {
                *mn = p[i].bt;
                *idx = i;
            }

            if (p[i].bt == *mn)
            {
                if (p[i].at < p[*idx].at)
                {
                    *mn = p[i].bt;
                    *idx = i;
                }
            }
        }
    }
}

int main()
{

    process p[] = {
        process(1, 0, 2),
        process(2, 1, 2),
        process(3, 2, 10),
        process(4, 3, 1),
    };

    int completed = 0;
    int is_completed[TOTAL_PROC] = {0};
    int current_time = 0;

    int burst_time[TOTAL_PROC] = {0};
    for (int i = 0; i < TOTAL_PROC; i++)
    {
        burst_time[i] = p[i].bt;
    }

    while (completed != TOTAL_PROC)
    {
        int idx = -1;
        int mn = 100000;

        getShortestJob(p, &idx, &mn, current_time, is_completed);

        cout << setw(WIDTH) << setfill((char)(idx + 49)) << " ";

        if (idx != -1)
        {

            if (burst_time[idx] == p[idx].bt)
            {
                p[idx].st = current_time;
            }
            burst_time[idx] -= 1;
            current_time++;

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
        else
            current_time++;
    }
    display(p);
    return 0;
}