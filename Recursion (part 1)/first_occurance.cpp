#include<iostream>
#include<vector>
using namespace std;

int checkFirstOccurance(vector<int> arr, int i, int target){
    int n=arr.size();
    if(i==n){
        return -1;
    }
    if (arr[i] == target)
    {
        return i;
    }

    return checkFirstOccurance(arr, i+1, target);
    
}

int lastOccurance(vector<int> arr, int target, int i){
    int n=arr.size();
    if(i==n){
        return -1;
    }
    int indx = lastOccurance(arr, target, i+1);
    if(indx==-1 && arr[i] == target){
        return i;
    }

    return indx;
}

int main()
{
    vector<int> arr = {1,2,3,3,3,4,5,6};
    cout<<checkFirstOccurance(arr,0,3)<<endl;
    cout<<lastOccurance(arr, 3, 0);

    return 0;
}