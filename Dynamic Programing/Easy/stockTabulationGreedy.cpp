#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int hold = -prices[0];  // holding a stock
    int cash = 0;           // not holding

    for (int i = 1; i < (int)prices.size(); i++) {
        cash = max(cash, hold + prices[i] - fee); // sell
        hold = max(hold, cash - prices[i]);       // buy
    }

    return cash;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        // No input provided — run a sample test case
        vector<int> prices = {1, 3, 2, 8, 4, 9};
        int fee = 2;
        cout << maxProfit(prices, fee) << '\n';
        return 0;
    }

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    int fee; cin >> fee;
    cout << maxProfit(prices, fee) << '\n';
    return 0;
}