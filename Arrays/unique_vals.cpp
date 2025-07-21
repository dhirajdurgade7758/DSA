#include <iostream>
using namespace std;

// Function to print unique elements in an array
void printUniqueElements(int arr[], int size) {
    bool isUnique;

    cout << "Unique elements in the array are: ";
    for (int i = 0; i < size; i++) {
        isUnique = true;
        for (int j = 0; j < size; j++) {
            // If arr[i] is found in another position, it is not unique
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        // If the element is unique, print it
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int size;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Call function to print unique elements
    printUniqueElements(arr, size);

    return 0;
}
