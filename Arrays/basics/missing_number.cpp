#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int val : nums) {
            ans = ans ^ val;   // XOR logic
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {4, 1, 2, 1, 2};

    Solution obj;
    int ans = obj.singleNumber(nums);

    cout << "Single Number: " << ans << endl;

    return 0;
}

