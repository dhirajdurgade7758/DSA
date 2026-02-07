#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, vector<int>& nums,
                vector<int>& subset,
                vector<vector<int>>& allsubset) {

        if (i == nums.size()) {
            allsubset.push_back(subset);
            return;
        }

        // include nums[i]
        subset.push_back(nums[i]);
        helper(i + 1, nums, subset, allsubset);

        // exclude nums[i]
        subset.pop_back();
        helper(i + 1, nums, subset, allsubset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> allsubset;
        helper(0, nums, subset, allsubset);
        return allsubset;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:\n";
    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
