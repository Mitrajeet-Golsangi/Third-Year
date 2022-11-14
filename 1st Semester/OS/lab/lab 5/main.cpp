#include <iostream>
#include <iomanip>

using namespace std;

class JobSchedules {
    string p_id[10];
    int wt[10];
    int bt[10];
    int at[10];
    int tat[10];
    int processes;
public:
    JobSchedules(int n, int* wt) {
        processes = n;
        for (int i = 0; i < n; i++)
        {
            this->p_id[i] = "P" + to_string(i+1);
            this->wt[i] = wt[i];
        }

    }

    void fcfs_wt() {
        wt[0] = bt[0];

        for (int i = 1; i < processes; i++)
        {
            wt[i] = wt[i-1] + bt[i];
        }
        
        
    }
};

int main()
{
    int n;
    int wt[10];

    cout << "Enter number of Processes : ";
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cout << "Enter Bus Time for Process " << i+1 << ": ";
        cin >> wt[i];
    }
    
    JobSchedules jobs = JobSchedules(4, wt);
    
    return 0;
}