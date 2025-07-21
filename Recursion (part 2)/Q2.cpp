#include<iostream>
#include<vector>
using namespace std;

void find_occurances(vector<int> arr, int i, int key){
// base case 
if(i == arr.size()){
    return;
}
if(arr[i] == key){
    cout<<i<<" ";
}
find_occurances(arr, i+1, key);
}
int main()
{
vector<int> arr = {3, 2, 4, 5, 6, 2, 7, 2, 2};
int  key = 2;
find_occurances(arr, 0, key);
return 0;
}