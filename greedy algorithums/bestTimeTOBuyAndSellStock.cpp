#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprf = 0;
        int bestbuy = prices[0];
        int n = prices.size();

        for(int i = 1; i < n; i++) {
            if(prices[i] > bestbuy) {
                maxprf = max(maxprf, prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return maxprf;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {7,1,5,3,6,4};  // Test case

    int result = sol.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}