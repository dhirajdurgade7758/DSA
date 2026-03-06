#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;  // initialize

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);

    cout << "Max consecutive ones: " << ans << endl;

    return 0;
}
