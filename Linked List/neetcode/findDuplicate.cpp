#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Phase 1: Detect cycle
        while (true) {
            slow = nums[slow];          // move 1 step
            fast = nums[nums[fast]];   // move 2 steps

            if (slow == fast) {
                break;
            }
        }

        // Phase 2: Find cycle entry (duplicate)
        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];

            if (slow == fast) {
                return slow;  // duplicate number
            }
        }
    }
};

// ---------- Testing ----------
int main() {
    Solution sol;

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate number: " << sol.findDuplicate(nums) << endl;

    return 0;
}
