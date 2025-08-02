// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        int amount = N;
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int num_of_coins=0;
        for(int i=coins.size()-1; i>=0 && amount>0; i--){
            if(amount >= coins[i]){
                num_of_coins = amount/coins[i];
                for(int j=0; j<num_of_coins; j++){
                    ans.push_back(coins[i]);
                }
                amount = amount%coins[i];
            }
        }
        return ans;
        
    }
};

