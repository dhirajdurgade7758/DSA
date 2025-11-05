class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }

        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < maxi){
                ans = max(ans, nums[i]);
            }
        }
        if(ans != INT_MIN){
            return ans;
        }
        return -1;
    }
};