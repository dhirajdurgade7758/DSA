#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// House Robber II - Handle circular arrangement where first and last houses are connected
class Solution {
public:
    // Helper function: solve linear house robber problem for range [start, end]
    // Uses DP: dp[i] = max profit from positions start to start+i
    int robLinear(vector<int>& nums, int start, int end) {
        int len = end - start + 1;

        // Edge case: only one house in range
        if (len == 1) return nums[start];

        // DP array where dp[i] represents max robbed amount up to index i
        vector<int> dp(len, 0);

        // Base cases
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        // Fill DP table: for each house decide to rob it or skip it
        for (int i = 2; i < len; i++) {
            // Max of: skip current house OR rob current + max from i-2 steps back
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[len - 1];
    }

    // Main function: solve House Robber II with circular constraint
    // Can't rob both first and last house (they are adjacent in circular arrangement)
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one house
        if (n == 1) return nums[0];

        // Case 1: Rob houses from 0 to n-2 (exclude last house)
        int case1 = robLinear(nums, 0, n - 2);
        
        // Case 2: Rob houses from 1 to n-1 (exclude first house)
        int case2 = robLinear(nums, 1, n - 1);

        // Return maximum profit from both cases
        return max(case1, case2);
    }
};

int main()
{
    Solution sol;
    
    // Test case 1: [1,2,3,1] - can rob houses 0 and 2 = 1+3 = 4
    vector<int> test1 = {1, 2, 3, 1};
    cout << "Test 1: [1,2,3,1] -> " << sol.rob(test1) << " (Expected: 4)" << endl;
    
    // Test case 2: [2,3,2] - can rob only middle house = 3 (or houses 0,2 but they are adjacent in circle)
    vector<int> test2 = {2, 3, 2};
    cout << "Test 2: [2,3,2] -> " << sol.rob(test2) << " (Expected: 3)" << endl;
    
    // Test case 3: [5,3,4,11,2] - multiple houses
    vector<int> test3 = {5, 3, 4, 11, 2};
    cout << "Test 3: [5,3,4,11,2] -> " << sol.rob(test3) << " (Expected: 20)" << endl;
    
    // Test case 4: Single house
    vector<int> test4 = {100};
    cout << "Test 4: [100] -> " << sol.rob(test4) << " (Expected: 100)" << endl;

    return 0;
}