#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> burst_time(n);
    vector<int> waiting_time(n); 
    vector<int> turnaround_time(n);

    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> burst_time[i];
    }

    // Calculate waiting time and turnaround time using FCFS
    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate average waiting time and turnaround time
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print the results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << burst_time[i] << "\t\t"
             << waiting_time[i] << "\t\t" << turnaround_time[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
