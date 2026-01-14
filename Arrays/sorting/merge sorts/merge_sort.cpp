#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int si, int mid, int ei){
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= ei){
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for(int k = 0; k < temp.size(); k++){
        arr[si + k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int si, int ei){
    if(si >= ei){
        return;
    }

    int mid = (si+ei)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);

    merge(arr, si,mid, ei);
}


void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, 4);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}