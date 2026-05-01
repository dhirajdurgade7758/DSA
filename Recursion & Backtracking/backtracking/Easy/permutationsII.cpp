class Solution {
public:

    void permutations(unordered_map<int, int>& nums, vector<int>& comb, vector<vector<int>>& ans, int n) {
        if (comb.size() == n) {
            ans.push_back(comb);
            return;
        }

        for (auto& it : nums) {
            if(it.second > 0){
                int num = it.first;

                // choose
                nums[num]--;

                comb.push_back(num);
                // explore
                permutations(nums, comb, ans, n);

                // un-choose (backtrack)
                comb.pop_back();
                nums[num]++;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> comb;
        vector<vector<int>> ans;
        permutations(mp, comb, ans, nums.size());
        return ans;
    }
};