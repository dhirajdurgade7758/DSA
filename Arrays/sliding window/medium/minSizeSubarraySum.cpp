#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum >= target) {
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return minlen == INT_MAX ? 0 : minlen;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Test 1: nums = [2, 3, 1, 2, 4, 3], target = " << target1 << endl;
    cout << "Output: " << sol.minSubArrayLen(target1, nums1) << endl;
    cout << "Expected: 2 (subarray [4,3])" << endl << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Test 2: nums = [1, 4, 4], target = " << target2 << endl;
    cout << "Output: " << sol.minSubArrayLen(target2, nums2) << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Test 3: nums = [1, 1, 1, 1, 1, 1, 1, 1], target = " << target3 << endl;
    cout << "Output: " << sol.minSubArrayLen(target3, nums3) << endl;
    cout << "Expected: 0 (sum of all elements is 8)" << endl << endl;
    
    // Test case 4
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 15;
    cout << "Test 4: nums = [1, 2, 3, 4, 5], target = " << target4 << endl;
    cout << "Output: " << sol.minSubArrayLen(target4, nums4) << endl;
    cout << "Expected: 5 (entire array)" << endl << endl;
    
    return 0;
}