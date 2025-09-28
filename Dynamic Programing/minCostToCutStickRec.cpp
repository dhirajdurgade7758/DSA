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
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int c=cuts.size();
        sort(cuts.begin(), cuts.end());
        return f(1, c, cuts);
    }
};