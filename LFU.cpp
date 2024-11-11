#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of page frames: ";
    cin >> m;
    cout << "Enter the number of page references: ";
    cin >> n;

    vector<int> pages;
    cout << "Enter the page reference string: ";
    for (int i = 0; i < n; i++) {
        int page;
        cin >> page;
        pages.push_back(page);
    }

    vector<int> frames(m, -1); // Initialize frames with -1
    map<int, int> freq; // Map to store page and its frequency

    int page_faults = 0;
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool page_found = false;

        // Check if page is already in a frame
        for (int j = 0; j < m; j++) {
            if (frames[j] == page) {
                page_found = true;
                freq[page]++;
                break;
            }
        }

        // If not found, replace the least frequently used page
        if (!page_found) {
            page_faults++;

            // Find the least frequently used page
            int min_freq = INT_MAX;
            int victim = 0;
            for (int j = 0; j < m; j++) {
                if (freq[frames[j]] < min_freq) {
                    min_freq = freq[frames[j]];
                    victim = j;
                }
            }

            frames[victim] = page;
            freq[page] = 1;
        }

        // Print the current state of frames
        for (int j = 0; j < m; j++) {
            cout << frames[j] << " ";
        }
        if(!page_found){
        	cout << "   Page Fault: " << page_faults << endl;
		}
        cout << endl;
        
    }

    cout << "Total Page Faults: " << page_faults << endl;

    return 0;
}
