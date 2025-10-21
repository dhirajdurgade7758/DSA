#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive helper function with memoization
    int f(int i, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp) {
        // Base case: if we've reached the end of price list
        if (i == prices.size()) return 0;

        // Return already computed result
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            // Option 1: Buy the stock today (subtract price)
            int take = -prices[i] + f(i + 1, 0, prices, fee, dp);

            // Option 2: Skip buying today
            int skip = f(i + 1, 1, prices, fee, dp);

            // Take the better of the two choices
            profit = max(take, skip);
        } 
        else {
            // Option 1: Sell the stock today (add price minus transaction fee)
            int sell = prices[i] - fee + f(i + 1, 1, prices, fee, dp);

            // Option 2: Skip selling today
            int skip = f(i + 1, 0, prices, fee, dp);

            // Take the better of the two choices
            profit = max(sell, skip);
        }

        // Store result in dp table
        return dp[i][buy] = profit;
    }

    // Main function to calculate maximum profit
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // DP table initialized with -1
        return f(0, 1, prices, fee, dp);  // Start from day 0 with buying allowed
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << "Maximum Profit: " << sol.maxProfit(prices, fee) << endl;
    return 0;
}
