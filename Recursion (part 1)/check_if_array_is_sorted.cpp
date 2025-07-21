#include<iostream>
using namespace std;

bool isSorted(int arr[], int n, int i){
    if(i == n-1){
        return true;
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
    return isSorted(arr, n, i+1);
}

int main()
{
    int arr[] = {1,2,6,8,9,10};
    int arr1[] = {12,34,5,7,2,50};
    cout<<isSorted(arr, 6, 0)<<endl; //1 for sorted array
    cout<<isSorted(arr1, 6, 0)<<endl; //0 for unsorted array

    return 0;
}