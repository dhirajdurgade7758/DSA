// User function Template for C++
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> minPartition(int N) {
        // STEP 1: Initialize with the amount and available coin denominations (sorted in ascending order)
        int amount = N;
        vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int num_of_coins=0;
        
        // STEP 2: Greedily select largest coins first (iterate from highest denomination)
        for(int i=coins.size()-1; i>=0 && amount>0; i--){
            // If current coin can be used, calculate how many of this coin we need
            if(amount >= coins[i]){
                num_of_coins = amount/coins[i];  // Integer division gives count of this coin
                // Add the coin to result list as many times as needed
                for(int j=0; j<num_of_coins; j++){
                    ans.push_back(coins[i]);
                }
                // Reduce remaining amount by what we used
                amount = amount%coins[i];
            }
        }
        return ans;
        
    }
};

int main() {
    Solution sol;
    int N = 1245;
    vector<int> result = sol.minPartition(N);
    cout << "Coins needed for " << N << ": ";
    for(int coin : result) {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}

