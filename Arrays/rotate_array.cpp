#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArr(vector<int> &nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // edge case: when k > n

        reverseArr(nums, 0, n - 1);
        reverseArr(nums, 0, k - 1);
        reverseArr(nums, k, n - 1);
    }
};

int main() {
    // Example test
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    Solution obj;
    obj.rotate(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
