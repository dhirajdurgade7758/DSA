#include<iostream>
#include<vector>
using namespace std;

int unboundedKnapsack(vector<int> val, vector<int> wt, int W, int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=W; j++)
        {
            int itemval = val[i-1];
            int itemwt = wt[i-1];

            if(itemwt <= j){
                dp[i][j] = max(itemval + dp[i][j-itemwt], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<W; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][W];
}

int main()
{
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;
    cout<<unboundedKnapsack(val, wt, w, n);

return 0;
}