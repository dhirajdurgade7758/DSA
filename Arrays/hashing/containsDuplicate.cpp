#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> mp;
    for(int i=0; i<nums.size(); i++){
        if(mp[nums[i]]){
            return true;
        }
        mp[nums[i]] = true;
    }
    return false;
}


int main()
{
    vector<int> nums = {1,2,3,1};
    cout<<containsDuplicate(nums)<<endl;


return 0;
}