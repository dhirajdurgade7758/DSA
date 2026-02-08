#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<int>& comb,
                   vector<bool>& used,
                   vector<vector<int>>& ans) {

        if (comb.size() == nums.size()) {
            ans.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            comb.push_back(nums[i]);

            backtrack(nums, comb, used, ans);

            // backtracking
            comb.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        vector<bool> used(nums.size(), false);

        backtrack(nums, comb, used, ans);
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);

    for (auto &v : result) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
