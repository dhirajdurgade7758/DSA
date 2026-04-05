#include<iostream>
#include<vector>
using namespace std;
    
void heapify(int indx, vector<int> &arr, int n){
        if(indx >= n){
            return;
        }
        
        int l=2*indx+1;
        int r=2*indx+2;
        int maxindx=indx;
        
        if(l<n && arr[l]>arr[maxindx]){
            maxindx=l;
        }
        
        if(r<n && arr[r]>arr[maxindx]){
            maxindx=r;
        }
        
        if(maxindx!=indx){
            swap(arr[maxindx], arr[indx]);
            return heapify(maxindx, arr, n);
        }
    }
    
void heapSort(vector<int> &arr){
        //step 1 build a maxheap
        int n=arr.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(i, arr, n);
        }
        
        // step 2 taking else to correct position
        for(int i=n-1; i>=0; i--){
            swap(arr[0], arr[i]);
            heapify(0, arr, i);
        }
    }

int main()
{
    vector<int> arr = {10,15,5,7,3,11};
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
    
    heapSort(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
    

return 0;
}