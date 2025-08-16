#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int largestSubarraySum(vector<int> arr){
    int sum=0;
    int ans=0;
    unordered_map<int, int> m;
    for(int j=0; j<arr.size(); j++){
        sum+=arr[j];
        if(m.count(sum)){
            int currlen = j-m[sum];
            ans = max(ans, currlen);
        }
        else{
            m[sum] = j;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {15,-2,2,-8,1,7,10};
    cout<<largestSubarraySum(arr);

return 0;
}