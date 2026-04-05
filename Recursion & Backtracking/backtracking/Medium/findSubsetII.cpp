#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int i, vector<int>& nums,
                vector<int>& subset,
                vector<vector<int>>& allsubset) {
        int n = nums.size();

        if (i == n) {
            allsubset.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[i]);
        helper(i + 1, nums, subset, allsubset);

        // skip duplicates before exclude
        while (i + 1 < n && nums[i] == nums[i + 1]) {
            i++;
        }

        // exclude
        subset.pop_back();
        helper(i + 1, nums, subset, allsubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> allsubset;
        helper(0, nums, subset, allsubset);
        return allsubset;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets are:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
