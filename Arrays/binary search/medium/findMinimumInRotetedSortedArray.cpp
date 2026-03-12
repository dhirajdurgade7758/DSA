#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        // If array is already sorted
        if(nums[left] < nums[right]){
            return nums[left];
        }

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4,5,6,7,0,1,2};

    int result = sol.findMin(nums);

    cout << "Minimum element in rotated array: " << result << endl;

    return 0;
}