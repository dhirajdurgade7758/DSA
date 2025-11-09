#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // Loop for each pass
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Inner loop for comparison and swapping
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // OPTIMIZATION:
        // If no two elements were swapped by the inner loop,
        // the array is sorted, so we can break early.
        if (!swapped) {
            break;
        }
    }
}


void printVector(const std::vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << std::endl;
}

// --- Main function to demonstrate ---
int main() {
    // Initialize a vector of integers
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Unsorted array: ";
    printVector(data);

    // Call the sort function
    bubbleSort(data);

    cout << "Sorted array:   ";
    printVector(data);

    return 0;
}