class Solution {
public:
    int f(int i, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp) {
        if (i == prices.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            // Option 1: Buy at this day
            int take = -prices[i] + f(i + 1, 0, prices, fee, dp);
            // Option 2: Skip buying
            int skip = f(i + 1, 1, prices, fee, dp);
            profit = max(take, skip);
        } else {
            // Option 1: Sell at this day
            int sell = prices[i] - fee + f(i + 1, 1, prices, fee, dp);
            // Option 2: Skip selling
            int skip = f(i + 1, 0, prices, fee, dp);
            profit = max(sell, skip);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp); // start with buying allowed
    }
};
