#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& candidates, int target,
                vector<int> comb, int sum, int indx,
                vector<vector<int>>& ans) {

        if (sum > target) {
            return;
        }

        if (sum == target) {
            ans.push_back(comb);
            return;
        }

        for (int i = indx; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            helper(candidates, target, comb, sum + candidates[i], i, ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(candidates, target, comb, 0, 0, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations are:\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
