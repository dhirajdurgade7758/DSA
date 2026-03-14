class Solution {
public:
    long long f(int i, int j, vector<int> &cuts){
        if(i>j){
            return 0;
        }
        long long mini = INT_MAX;

        for(int ind=i; ind<=j; ind++){
            long long cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts) + f(ind+1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }

    long long minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<long long>> dp(c+2, vector<long long>(c+2, 0));

        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i>j){
                    continue;
                }
                long long mini = INT_MAX;

                for(int ind=i; ind<=j; ind++){
                    long long cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j]= mini;

            }
        }
        return dp[1][c];
    }
};