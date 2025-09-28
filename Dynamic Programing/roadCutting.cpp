#include<iostream>
#include<vector>
using namespace std;

int RoadCutting(vector<int> prices, vector<int> lengths, int roadLength, int n){
    vector<vector<int>> dp(n+1, vector<int>(roadLength+1, 0));

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=roadLength; j++)
        {
            int price = prices[i-1];
            int length = lengths[i-1];

            if(length <= j){
                dp[i][j] = max(price + dp[i][j-length], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<roadLength+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][roadLength];
}

int main()
{
    vector<int> prices = {1,5,8,9,10,17,17,20};
    vector<int> lengths = {1,2,3,4,5,6,7,8};
    int n = prices.size();
    int roadLength = 8;
    cout<<RoadCutting(prices, lengths, roadLength, n);

return 0;
}