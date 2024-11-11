#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, burstTime, priority, waitingTime, turnaroundTime;
};

bool compare(Process a, Process b) {
    return a.priority < b.priority; // Lower priority number means higher priority
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter Burst Time for Process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter Priority for Process " << processes[i].id << ": ";
        cin >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), compare);

    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].turnaroundTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    cout << "\nPROCESS\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n";
    for (const auto& p : processes) {
        cout << "P" << p.id << "\t" 
             << p.burstTime << "\t\t" 
             << p.priority << "\t\t" 
             << p.waitingTime << "\t\t" 
             << p.turnaroundTime << endl;
    }

    return 0;
}
