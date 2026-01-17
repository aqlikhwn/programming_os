#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int ccode;          // course code
    int duration;       // class duration (burst time)
    int priority;       // priority
    int arrival_time;   // preferred arrival time
};

// Function to display process details
void displayProcesses(Process proc[], int n) {
    cout << "\n+------------+----------+----------+--------------+" << endl;
    cout << "| Course Code| Duration | Priority | Arrival Time |" << endl;
    cout << "+------------+----------+----------+--------------+" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| CSC" << setw(7) << left << proc[i].ccode 
             << "| " << setw(9) << left << proc[i].duration 
             << "| " << setw(9) << left << proc[i].priority 
             << "| " << setw(13) << left << proc[i].arrival_time << "|" << endl;
    }
    cout << "+------------+----------+----------+--------------+" << endl;
}

// FCFS - First Come First Serve Algorithm
void FCFS(Process proc[], int n) {
    cout << "\n========================================" << endl;
    cout << "   FCFS (First Come First Serve)" << endl;
    cout << "========================================" << endl;
    
    Process sorted[n];
    for (int i = 0; i < n; i++) {
        sorted[i] = proc[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j].arrival_time > sorted[j + 1].arrival_time) {
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
        if (i == 0) {
            waiting_time[i] = 0;
        } else {
            waiting_time[i] = completion_time;
        }
        
        completion_time += sorted[i].duration;
        turnaround_time[i] = waiting_time[i] + sorted[i].duration;
        
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        
        cout << "| CSC" << setw(7) << left << sorted[i].ccode 
             << "| " << setw(9) << left << sorted[i].duration 
             << "| " << setw(11) << left << completion_time 
             << "| " << setw(14) << left << waiting_time[i] 
             << "| " << setw(15) << left << turnaround_time[i] << "|" << endl;
    }
    cout << "+------------+----------+------------+---------------+----------------+" << endl;
    
    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << total_waiting / n << " hours" << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << total_turnaround / n << " hours" << endl;
}

// SJF - Shortest Job First (Non-Preemptive) Algorithm
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
        if (i == 0) {
            waiting_time[i] = 0;
        } else {
            waiting_time[i] = completion_time;
        }
        
        completion_time += sorted[i].duration;
        turnaround_time[i] = waiting_time[i] + sorted[i].duration;
        
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
        
        cout << "| CSC" << setw(7) << left << sorted[i].ccode 
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
    
    // Initialize processes (courses)
    // CSC2201: priority 2, 3 hours, preferred start 1st
    // CSC3401: priority 3, 2 hours, preferred start 2nd
    // CSC1103: priority 1, 1 hour, preferred start 3rd
    Process proc[] = {
        {2201, 3, 2, 1},  // CSC2201: 3 hours, priority 2, arrival 1
        {3401, 2, 3, 2},  // CSC3401: 2 hours, priority 3, arrival 2
        {1103, 1, 1, 3}   // CSC1103: 1 hour, priority 1, arrival 3
    };
    
    int n = sizeof(proc) / sizeof(proc[0]);
    
    cout << "\nInput Courses:" << endl;
    displayProcesses(proc, n);
    
    // Run FCFS Algorithm
    FCFS(proc, n);
    
    // Run SJF Algorithm
    SJF(proc, n);
    
    return 0;
}
