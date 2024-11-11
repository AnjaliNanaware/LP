#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num_blocks, num_files;

    cout << "Enter the number of blocks: ";
    cin >> num_blocks;

    cout << "Enter the number of files: ";
    cin >> num_files;

    vector<int> block_sizes(num_blocks);
    vector<int> file_sizes(num_files);
    vector<int> allocated_blocks(num_blocks, -1); // -1 indicates not allocated
    vector<int> fragments(num_files, 0);

    // Input block sizes
    cout << "Enter the size of the blocks:\n";
    for (int i = 0; i < num_blocks; ++i) {
        cout << "Block " << i + 1 << ": ";
        cin >> block_sizes[i];
    }

    // Input file sizes
    cout << "Enter the size of the files:\n";
    for (int i = 0; i < num_files; ++i) {
        cout << "File " << i + 1 << ": ";
        cin >> file_sizes[i];
    }

    // Worst-Fit Memory Allocation
    for (int i = 0; i < num_files; ++i) {
        int best_fit_index = -1;
        int max_fragment = 0;

        for (int j = 0; j < num_blocks; ++j) {
            if (allocated_blocks[j] == -1 && block_sizes[j] >= file_sizes[i]) {
                int current_fragment = block_sizes[j] - file_sizes[i];
                if (current_fragment > max_fragment) {
                    max_fragment = current_fragment;
                    best_fit_index = j;
                }
            }
        }

        if (best_fit_index != -1) {
            allocated_blocks[best_fit_index] = i;
            fragments[i] = max_fragment;
        } else {
            cout << "File " << i + 1 << " cannot be allocated.\n";
        }
    }

    // Print the allocation table
    cout << "\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n";
    for (int i = 0; i < num_files; ++i) {
        cout << i + 1 << "\t\t" << file_sizes[i] << "\t\t";
        if (allocated_blocks[i] != -1) {
            cout << allocated_blocks[i] + 1 << "\t\t" << block_sizes[allocated_blocks[i]] << "\t\t" << fragments[i];
        } else {
            cout << "Not Allocated";
        }
        cout << endl;
    }

    return 0;
}
