#include<iostream>
#include<vector>
using namespace std;

// Function to find maximum profit by cutting a road
// Uses dynamic programming (unbounded knapsack variant)
// prices: array of prices for each cut length
// lengths: array of lengths for each cut
// roadLength: total length of the road to cut
// n: number of different cut options
int RoadCutting(vector<int> prices, vector<int> lengths, int roadLength){
    int n=prices.size();
    // DP table where dp[i][j] represents max profit using first i cut types for length j
    vector<vector<int>> dp(n+1, vector<int>(roadLength+1, 0));

    // Iterate through each cut type (1 to n)
    for (int i=1; i<=n; i++)
    {
        // Iterate through each possible road length (1 to roadLength)
        for (int j=1; j<=roadLength; j++)
        {
            // Get the price and length of current cut option
            int price = prices[i-1];
            int length = lengths[i-1];

            // If current cut length fits in remaining road length
            if(length <= j){
                // Take max of: using this cut (with repeated use) vs not using it
                dp[i][j] = max(price + dp[i][j-length], dp[i-1][j]);
            }
            // If current cut length doesn't fit, skip this cut
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
    
    // Return the maximum profit for the entire road length
    return dp[n][roadLength];
}

int main()
{
    // Define prices for each cut length {1,2,3,4,5,6,7,8}
    vector<int> prices = {1,5,8,9,10,17,17,20};
    
    // Define corresponding cut lengths
    vector<int> lengths = {1,2,3,4,5,6,7,8};
    
    
    // Total length of road to cut
    int roadLength = 8;
    
    // Call the function and print result (maximum profit)
    cout<<RoadCutting(prices, lengths, roadLength);

return 0;
}