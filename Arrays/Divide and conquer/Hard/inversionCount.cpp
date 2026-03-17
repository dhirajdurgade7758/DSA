#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int si, int ei, int mid) { // O(n) time complexity
    vector<int> temp; // Temporary vector to store merged elements
    int i = si;
    int j = mid + 1;
    int invCount = 0;

    // Merge the two halves
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            invCount += (mid-i+1);
            j++;
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from the right half
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the merged elements back to the original array
    for (int k = si, x = 0; k <= ei; k++, x++) {
        arr[k] = temp[x];
    }
    return invCount;
}

int mergeSort(vector<int>& arr, int si, int ei){ //O(n logn) time complexity
    if(si<ei){
    //divide part
    int mid = si+(ei-si)/2;
    int leftInvCount = mergeSort(arr,si,mid ); //left part
    int rightInvCount = mergeSort(arr,mid+1, ei); //right part

    // combine left and right
    // conquer part
    int invCount = merge(arr, si, ei, mid);
    return (leftInvCount+rightInvCount+invCount);
    }
    return 0;
}

void printArr(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    vector<int> arr = {2, 4, 1, 3, 5} ;
    cout<<mergeSort(arr,0, arr.size()-1)<<endl;
    printArr(arr);

return 0;
}