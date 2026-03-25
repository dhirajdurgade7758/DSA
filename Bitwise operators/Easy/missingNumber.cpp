#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = 0;
        for (int i = 0; i <= nums.size(); i++) {  // include n
            sum1 ^= i;
        }

        int sum2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum2 ^= nums[i];
        }

        return sum1 ^ sum2;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (numbers from 0 to n with one missing):\n";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int result = obj.missingNumber(nums);

    cout << "Missing number is: " << result << endl;

    return 0;
}