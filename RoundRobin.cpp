#include <iostream>
using namespace std;

int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bu[i];
        ct[i] = bu[i]; // Copy burst time to ct array for later calculations
    }

    cout << "Enter the size of time slice: ";
    cin >> t;

    max = bu[0];
    for (i = 1; i < n; i++) {
        if (max < bu[i]) max = bu[i]; // Find the maximum burst time
    }

    for (j = 0; j < (max / t) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (bu[i] != 0) { // Check if the process still has remaining burst time
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i]; // Calculate turnaround time
                    temp = temp + bu[i]; // Update total time
                    bu[i] = 0; // Process is finished
                } else {
                    bu[i] = bu[i] - t; // Reduce remaining burst time
                    temp = temp + t; // Update total time
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i]; // Calculate waiting time
        att += tat[i]; // Accumulate turnaround time
        awt += wa[i]; // Accumulate waiting time
    }

    cout << "\nAverage Turnaround Time: " << att / n;
    cout << "\nAverage Waiting Time: " << awt / n << endl;
    cout << "\nPROCESS\t BURST TIME \t WAITING TIME\t TURNAROUND TIME\n";

    for (i = 0; i < n; i++) {
        cout << i + 1 << "\t " << ct[i] << "\t\t " << wa[i] << "\t\t " << tat[i] << endl;
    }

    return 0;
}
