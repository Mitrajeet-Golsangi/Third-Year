#include <algorithm>
#include <iomanip>
#include <iostream>

#define WIDTH 10

using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int priority;
    int ct;
    int tat;
    int wt;

    process(int pid, int at, int bt, int priority)
    {
        this->pid = pid;
        this->at = at;
        this->bt = bt;
        this->priority = priority;
    }
};

void findCompletionTime(process p[], int n)
{
    p[0].ct = p[0].bt;

    int sum = p[0].ct;

    for (int i = 1; i < n; i++)
    {
        if (p[i].at < sum)
            sum += p[i].bt;
        else
            sum = p[i].at + p[i].bt;

        p[i].ct = sum;
    }
}

void drawLine()
{
    cout << left << setw(WIDTH * 7) << setfill('-') << "" << setfill(' ') << endl;
}

void display(process p[], int n)
{
    drawLine();
    cout << left
         << setw(WIDTH) << "Process"
         << setw(WIDTH) << "AT"
         << setw(WIDTH) << "BT"
         << setw(WIDTH) << "Priority"
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
             << setw(WIDTH) << p[i].priority
             << setw(WIDTH) << p[i].ct
             << setw(WIDTH) << p[i].tat
             << setw(WIDTH) << p[i].wt
             << endl;
    }
    drawLine();
}

bool comp(process a, process b)
{
    return a.at == b.at ? a.priority < b.priority : a.at < b.at;
}

int main()
{
    process p[] = {
        process(1, 0, 11, 2),
        process(2, 5, 28, 0),
        process(3, 12, 2, 3),
        process(4, 2, 10, 1),
        process(5, 9, 16, 4),
    };

    std::sort(p, p + 5, comp);

    findCompletionTime(p, 4);
    display(p, 4);

    return 0;
}