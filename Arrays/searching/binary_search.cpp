#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int targ){
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while (start<=end)
    {
        mid = (start+end)/2;
        if (targ > arr[mid])
        {
            start = mid+1;
        }
        else if(targ < arr[mid]){
            end = mid - 1;
        }
        else{
            return mid;
        }
        
    }
    return -1;
    
}

int main(){

    vector<int> arr = {10,20,30,40,50,60,70,80};
    int targ = 80;

    cout<<"the value 80 found at index: "<<binary_search(arr, targ);
    

}