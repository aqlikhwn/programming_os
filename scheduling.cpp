#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int ccode;
    int duration;
    int priority;
    int arrival_time;
};

void displayProcesses(Process proc[], int n) {
    cout << "\n+------------+----------+----------+--------------+" << endl;
    cout << "| Course Code| Duration | Priority | Arrival Time |" << endl;
    cout << "+------------+----------+----------+--------------+" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| CSC" << setw(8) << left << proc[i].ccode 
             << "| " << setw(9) << left << proc[i].duration 
             << "| " << setw(9) << left << proc[i].priority 
             << "| " << setw(13) << left << proc[i].arrival_time << "|" << endl;
    }
    cout << "+------------+----------+----------+--------------+" << endl;
}

void FCFS(Process proc[], int n) {
    cout << "\n========================================" << endl;
    cout << "   FCFS (First Come First Serve)" << endl;
    cout << "========================================" << endl;
    
    Process sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = proc[i];
    }
    
    int waiting_time[n], turnaround_time[n];
    int completion_time = 0;
    float total_waiting = 0, total_turnaround = 0;
    
    cout << "\nScheduling Order: ";
    for (int i = 0; i < n; i++) {
        cout << "CSC" << sorted[i].ccode;
        if (i < n - 1) cout << " -> ";
    }
    cout << endl;
    
    cout << "\n+------------+----------+------------+---------------+----------------+" << endl;
    cout << "| Course Code| Duration | Completion | Waiting Time  | Turnaround Time|" << endl;
    cout << "+------------+----------+------------+---------------+----------------+" << endl;
    
    for (int i = 0; i < n; i++) {
        waiting_time[i] = completion_time;
        completion_time += sorted[i].duration;
        turnaround_time[i] = waiting_time[i] + sorted[i].duration;
        
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        
        cout << "| CSC" << setw(8) << left << sorted[i].ccode 
             << "| " << setw(9) << left << sorted[i].duration 
             << "| " << setw(11) << left << completion_time 
             << "| " << setw(14) << left << waiting_time[i] 
             << "| " << setw(15) << left << turnaround_time[i] << "|" << endl;
    }
    cout << "+------------+----------+------------+---------------+----------------+" << endl;
    
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << total_waiting / n << " hours" << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << total_turnaround / n << " hours" << endl;
}

void SJF(Process proc[], int n) {
    cout << "\n========================================" << endl;
    cout << "   SJF (Shortest Job First - Non-Preemptive)" << endl;
    cout << "========================================" << endl;
    
    Process sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = proc[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j].duration > sorted[j + 1].duration) {
                Process temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    
    int waiting_time[n], turnaround_time[n];
    int completion_time = 0;
    float total_waiting = 0, total_turnaround = 0;
    
    cout << "\nScheduling Order: ";
    for (int i = 0; i < n; i++) {
        cout << "CSC" << sorted[i].ccode;
        if (i < n - 1) cout << " -> ";
    }
    cout << endl;
    
    cout << "\n+------------+----------+------------+---------------+----------------+" << endl;
    cout << "| Course Code| Duration | Completion | Waiting Time  | Turnaround Time|" << endl;
    cout << "+------------+----------+------------+---------------+----------------+" << endl;
    
    for (int i = 0; i < n; i++) {
        waiting_time[i] = completion_time;
        completion_time += sorted[i].duration;
        turnaround_time[i] = waiting_time[i] + sorted[i].duration;
        
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        
        cout << "| CSC" << setw(8) << left << sorted[i].ccode 
             << "| " << setw(9) << left << sorted[i].duration 
             << "| " << setw(11) << left << completion_time 
             << "| " << setw(14) << left << waiting_time[i] 
             << "| " << setw(15) << left << turnaround_time[i] << "|" << endl;
    }
    cout << "+------------+----------+------------+---------------+----------------+" << endl;
    
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << total_waiting / n << " hours" << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << total_turnaround / n << " hours" << endl;
}

int main() {
    cout << "============================================" << endl;
    cout << "   CLASS SCHEDULING USING CPU ALGORITHMS" << endl;
    cout << "============================================" << endl;
    
    Process proc[] = {
        {2201, 3, 2, 1},
        {3401, 2, 3, 2},
        {1103, 1, 1, 3}
    };
    
    int n = sizeof(proc) / sizeof(proc[0]);
    
    cout << "\nInput Courses:" << endl;
    displayProcesses(proc, n);
    
    FCFS(proc, n);
    SJF(proc, n);
    
    return 0;
}