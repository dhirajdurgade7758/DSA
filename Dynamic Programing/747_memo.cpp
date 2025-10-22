#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int f(int i, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp) {

        if (i == prices.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {

            int take = -prices[i] + f(i + 1, 0, prices, fee, dp);

            int skip = f(i + 1, 1, prices, fee, dp);

            profit = max(take, skip);
        } 
        else {
            int sell = prices[i] - fee + f(i + 1, 1, prices, fee, dp);

            int skip = f(i + 1, 0, prices, fee, dp);

            profit = max(sell, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);  
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << "Maximum Profit: " << sol.maxProfit(prices, fee) << endl;
    return 0;
}
