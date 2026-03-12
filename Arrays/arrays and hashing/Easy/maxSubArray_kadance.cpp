#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxsum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            currSum = max(currSum + nums[i], nums[i]);
            maxsum = max(maxsum, currSum);
        }
        return maxsum;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl;

    return 0;
}
