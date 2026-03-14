#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int LIS(vector<int> arr1){
    unordered_set<int> s(arr1.begin(), arr.end());
    vector<int> arr2(s.begin(), s.end());

    int n=arr1.size();
    int m=arr2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    vector<int> arr = {50,3,10,7,40,80};
    cout<<LIS(arr);

return 0;
}