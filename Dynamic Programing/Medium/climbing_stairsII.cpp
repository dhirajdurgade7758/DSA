#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& costs, vector<int>& dp) {
        int n = costs.size();

        // Base case: reached end
        if (i >= n - 1) {
            return 0;
        }

        // Memoization check
        if (dp[i + 1] != -1) {
            return dp[i + 1];
        }

        int mini = 1e9;

        // Try jumping 1, 2, or 3 steps
        for (int j = i + 1; j <= min(i + 3, n - 1); j++) {
            mini = min(mini,
                       (j - i) * (j - i) + costs[j] + solve(j, costs, dp));
        }

        return dp[i + 1] = mini;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 2, -1);
        return solve(-1, costs, dp);
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> costs(n);
    cout << "Enter costs: ";
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Minimum cost: " << obj.climbStairs(n, costs) << endl;

    return 0;
}