#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int start, int end, int key){
    //base case 1
    if (start>end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    // base case 2
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] < key){
        start = mid+1;
    }
    else if(arr[mid] > key){
        end = mid-1;
    }
    // recursive call
    return binary_search(arr, start, end, key);
}

int main()
{
vector<int> arr = {1,2,3,4,5,6};
int n = arr.size();
cout<<binary_search(arr, 0, n-1, 5);
return 0;
}