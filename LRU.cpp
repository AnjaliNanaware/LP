#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, f, page_faults = 0; // n: number of page references, f: number of frames

    cout << "Enter the number of page references: ";
    cin >> n;

    cout << "Enter the reference string: ";
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> f;

    vector<int> frames(f, -1); // Initialize frames with -1
    vector<int> time_stamp(f, 0); // To track the last usage time of each frame

    cout << "\nPage Replacement Process:\n";
    for (int i = 0; i < n; i++) {
        bool page_fault = true;

        // Check if the page is already in a frame
        for (int j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                page_fault = false;
                time_stamp[j] = i; // Update the time stamp of the page
                break;
            }
        }

        // If page fault occurs
        if (page_fault) {
            // Find the least recently used (LRU) page
            int min_time = 0;
            int victim = 0;
            for (int j = 1; j < f; j++) {
                if (time_stamp[j] < time_stamp[min_time]) {
                    min_time = j;
                    victim = j;
                }
            }

            // Replace the LRU page with the current page
            frames[victim] = pages[i];
            time_stamp[victim] = i;
            page_faults++;

            // Print the current state of frames and page fault
            for (int j = 0; j < f; j++) {
                cout << frames[j] << " ";
            }
            cout << "   Page Fault: " << page_faults << endl;
        } else {
            // Print the current state of frames without page fault
            for (int j = 0; j < f; j++) {
                cout << frames[j] << " ";
            }
            cout << endl;
        }
    }

    cout << "\nTotal Page Faults: " << page_faults << endl;

    return 0;
}
