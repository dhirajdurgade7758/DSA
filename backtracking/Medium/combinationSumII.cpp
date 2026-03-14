#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates, int target,
                vector<int>& comb, int sum, int indx,
                vector<vector<int>>& ans) {

        if (sum > target) return;

        if (sum == target) {
            ans.push_back(comb);
            return;
        }

        int n = candidates.size();

        for (int i = indx; i < n; i++) {

            // skip duplicates at the same recursion level
            if (i > indx && candidates[i] == candidates[i - 1])
                continue;

            comb.push_back(candidates[i]);
            helper(candidates, target, comb, sum + candidates[i], i + 1, ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // mandatory
        vector<vector<int>> ans;
        vector<int> comb;
        helper(candidates, target, comb, 0, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Combinations:\n";
    for (auto &v : result) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
