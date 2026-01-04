#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprf = 0;
        int bestbuy = prices[0];
        int n = prices.size();

        for(int i = 1; i < n; i++){
            if(prices[i] > bestbuy){
                maxprf = max(maxprf, prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return maxprf;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
