#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> arrival_time(n);
    vector<int> burst_time(n);
    vector<int> remaining_time(n);
    vector<int> waiting_time(n);
    vector<int> turnaround_time(n);

    cout << "Enter the arrival time and burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Process " << i + 1 << ":" << endl;
        cout << "Arrival time: ";
        cin >> arrival_time[i];
        cout << "Burst time: ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }

    cout << "Enter the time quantum: ";
    cin >> time_quantum;

    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (int i = 0; i < n; ++i) {
            if (arrival_time[i] <= current_time && remaining_time[i] > 0) {
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    waiting_time[i] = current_time - burst_time[i] - arrival_time[i];
                    turnaround_time[i] = current_time - arrival_time[i];
                    remaining_time[i] = 0;
                    completed_processes++;
                } else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
            }
        }
    }

    // Print the results
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    // Calculate average waiting time and turnaround time
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
