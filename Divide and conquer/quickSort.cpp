#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int si, int ei){
        int i=si-1;
        for(int j=si; j<ei; j++){
            if(arr[j] >= arr[ei]){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        i++;
        swap(arr[i], arr[ei]);
        return i;
}

void quickSort(vector<int>& arr, int si, int ei){
    if(si >= ei){
        return;
    }
    int pivote = partition(arr, si, ei);
    quickSort(arr, si, pivote-1);
    quickSort(arr, pivote+1, ei);
}

void display(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    vector<int> arr = {6,4,2,9,1,5,3,7};
    quickSort(arr, 0, arr.size()-1);
    display(arr);

return 0;
}