#include<iostream>
#include<vector>
using namespace std;

void singleNum(vector<int> arr){
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans^=arr[i];
    }
    cout<<"single number is "<<ans;
}

int main()
{
    vector<int> arr = {2,2,3,4,3,4,5};
    singleNum(arr);

return 0;
}