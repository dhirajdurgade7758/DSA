#include<unordered_map>
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        // code here
        unordered_map<int, int> mp;
        int res=0;
        int prefixSum=0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            
            if (prefixSum == k) {
                res = max(res, i + 1);
            }


            if(mp.find(prefixSum-k) != mp.end()){
                res = max(res, i-mp[prefixSum-k]);
            }

            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }
        }

        return res;
        
    }
};
