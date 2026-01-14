#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int subarraySumEqalsK(vector<int> arr, int k){
    int sum=0;
    int ans=0;
    unordered_map<int, int> m;
    m[0] = 1;
    for(int j=0; j<arr.size(); j++){
        sum+=arr[j];
        if(m.count(sum - k)){
            ans+= m[sum - k];
        }
        if(m.count(sum)){
            m[sum]++;
        }
        else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10,2,-2,-20,10};
    int k = -10;
    cout<<subarraySumEqalsK(arr, k);

return 0;
}