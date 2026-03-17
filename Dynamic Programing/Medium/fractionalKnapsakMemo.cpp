#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val, vector<int> wt, int n, int w,vector<vector<int>>& dp){
    if(n==0 || w==0){
        return 0;
    }
    int currval = val[n-1];
    int currwt = wt[n-1];
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }

    if(currwt <= w){
        //incude
        int ans1 = knapSackRec(val, wt, n-1, w-currwt, dp) + currval;

        //not include
        int ans2 = knapSackRec(val, wt, n-1, w, dp);
        dp[n][w] = (max(ans1, ans2));
    }
    else{
        dp[n][w] = knapSackRec(val, wt, n-1, w, dp);
    }
    return dp[n][w];
}

int main()
{
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout<<knapSackRec(val, wt, n,w, dp);

return 0;
}
