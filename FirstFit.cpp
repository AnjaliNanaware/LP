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
    vector<int> allocated_blocks(num_files, -1); // -1 indicates not allocated
    vector<int> fragments(num_files, 0);

    cout << "Enter the size of the blocks:\n";
    for (int i = 0; i < num_blocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> block_sizes[i];
    }

    cout << "Enter the size of the files:\n";
    for (int i = 0; i < num_files; i++) {
        cout << "File " << i + 1 << ": ";
        cin >> file_sizes[i];
    }

    // First-Fit Algorithm
    for (int i = 0; i < num_files; i++) {
        for (int j = 0; j < num_blocks; j++) {
            if (allocated_blocks[j] == -1 && block_sizes[j] >= file_sizes[i]) {
                allocated_blocks[j] = i;
                fragments[i] = block_sizes[j] - file_sizes[i];
                break;
            }
        }
    }

    // Print the allocation table
    cout << "\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n";
    for (int i = 0; i < num_files; i++) {
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
