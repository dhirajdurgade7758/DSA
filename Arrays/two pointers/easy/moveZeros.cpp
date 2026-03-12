#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }

        while (i < n) {
            nums[i] = 0;
            i++;
        }
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    sol.moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
