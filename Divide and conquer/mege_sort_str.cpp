#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<string>& arr, int si, int ei, int mid) {
    vector<string> temp;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for (int x = 0, i = si; i <= ei; i++, x++) {
        arr[i] = temp[x];
    }
}

void mergeSort(vector<string>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }

    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, ei, mid);
}

void printArr(const vector<string>& arr) {
    for (const auto& str : arr) {
        cout << str << " ";
    }
    cout << endl;
}

int main() {
    vector<string> arr = { "sun", "earth", "mars", "mercury" };
    mergeSort(arr, 0, arr.size() - 1);
    printArr(arr);

    return 0;
}
