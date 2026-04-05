#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permutations(vector<int> nums, vector<int> comb, vector<vector<int>>& ans) {
        if (nums.size() == 0) {
            ans.push_back(comb);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // choose
            nums.erase(nums.begin() + i);
            comb.push_back(num);

            // explore
            permutations(nums, comb, ans);

            // un-choose (backtrack)
            comb.pop_back();
            nums.insert(nums.begin() + i, num);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comb;
        permutations(nums, comb, ans);
        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);

    cout << "Permutations:\n";
    for (auto &perm : result) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
