#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxprf = 0;
    int bestbuy = prices[0];
    int n = prices.size();

    for(int i = 1; i<n; i++){
        if(prices[i] > bestbuy){
            maxprf = max(maxprf, prices[i] - bestbuy);
        }
        bestbuy = min(bestbuy, prices[i]);
    }
    return maxprf;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"maximum profit can be: "<<maxProfit(prices);

return 0;
}
