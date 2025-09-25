#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // Edge case: only one house
        if (nums.size() == 1) {
            return nums[0];
        }

        // dp[i] = max money that can be robbed up to house i
        vector<int> dp(nums.size(), -1);

        dp[0] = nums[0];                       // Rob first house
        dp[1] = max(nums[0], nums[1]);         // Max of robbing first or second house

        // Build the dp array
        for (int i = 2; i < nums.size(); i++) {
            // Either skip current house (dp[i-1]) or rob it + dp[i-2]
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        // Answer is the max we can rob till the last house
        return dp[nums.size() - 1];
    }
};

// ---------------- DRIVER CODE (to run in VS Code) ----------------
int main() {
    Solution sol;

    // Example input
    vector<int> houses = {2, 7, 9, 3, 1};

    cout << "Maximum money that can be robbed: " 
         << sol.rob(houses) << endl;

    return 0;
}
