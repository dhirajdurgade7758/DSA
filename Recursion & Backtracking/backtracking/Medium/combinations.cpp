#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& curr, int lastPick, int n, int k) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for (int i = lastPick + 1; i <= n; i++) {
            curr.push_back(i);
            helper(ans, curr, i, n, k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans, curr, 0, n, k);
        return ans;
    }
};

int main() {
    Solution sol;

    int n = 4;
    int k = 2;

    cout << "Enter n and k: ";
    if (cin >> n >> k) {
        vector<vector<int>> result = sol.combine(n, k);

        cout << "Combinations are:\n";
        for (const auto& comb : result) {
            cout << "[ ";
            for (int val : comb) {
                cout << val << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}