/*
                                            if (ST < AT)
Process     AT      BT      ST = ∑ BT       CT = ST + BT        WT      TAT
                                            else
                                            CT = AT + BT
P0          0       2       2               2                   0
P1          1       2       4               4
P2          5       3       7               8
P3          6       4       12              12

*/

#include <iomanip>
#include <iostream>

#define WIDTH 10

using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;

    process();
    process(int pid, int at, int bt)
    {
        this->pid = pid;
        this->at = at;
        this->bt = bt;
    }
};

void findCompletionTime(process p[], int n)
{
    p[0].ct = p[0].bt;
    p[0].wt = 0;

    int sum = p[0].ct;

    for (int i = 1; i < n; i++)
    {
        if (sum > p[i].at)
            sum = p[i].bt + sum;
        else
            sum = p[i].bt + p[i].at;

        p[i].ct = sum;
    }
}

void findWaitTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void findTurnAroundTime(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
    }
}

void drawLine()
{
    cout << setw(WIDTH * 6) << setfill('-') << "" << endl
         << setfill(' ');
}
void display(process p[], int n)
{
    drawLine();
    cout << left
         << setw(WIDTH) << "Process"
         << setw(WIDTH) << "AT"
         << setw(WIDTH) << "BT"
         << setw(WIDTH) << "CT"
         << setw(WIDTH) << "TAT"
         << setw(WIDTH) << "WT"
         << endl;
    drawLine();

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(WIDTH) << p[i].pid
             << setw(WIDTH) << p[i].at
             << setw(WIDTH) << p[i].bt
             << setw(WIDTH) << p[i].ct
             << setw(WIDTH) << p[i].tat
             << setw(WIDTH) << p[i].wt
             << endl;
    }
    drawLine();
}

int main()
{
    process processes[] = {
        process(0, 0, 2),
        process(1, 1, 2),
        process(2, 5, 3),
        process(3, 6, 4),
    };
    findCompletionTime(processes, 4);
    findTurnAroundTime(processes, 4);
    findWaitTime(processes, 4);
    display(processes, 4);
    return 0;
}