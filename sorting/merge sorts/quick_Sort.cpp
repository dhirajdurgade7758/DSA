#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int si, int ei){
   
int i=si-1;
int pivot = arr[ei];
for(int j=si; j<ei; j++){
    if(arr[j] <= pivot){
        i++;
        swap(arr[i], arr[j]);
    }
}
i++;
swap(arr[i], arr[ei]);
return i;
}
void quick_sort(vector<int> &arr, int si, int ei){
    if(si>=ei){
        return;
    }
    int pivot = partition(arr, si, ei);
    quick_sort(arr,si,pivot-1);
    quick_sort(arr,pivot+1, ei);
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

    quick_sort(arr, 0, 4);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}