class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};