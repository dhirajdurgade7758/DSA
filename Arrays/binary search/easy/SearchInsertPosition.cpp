#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left <= right){
            int mid=left+(right-left)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] < target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right+1;
    }
};

int main(){
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Input: nums = [1, 3, 5, 6], target = " << target1 << endl;
    cout << "Output: " << sol.searchInsert(nums1, target1) << endl;
    
    // Test case 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "\nInput: nums = [1, 3, 5, 6], target = " << target2 << endl;
    cout << "Output: " << sol.searchInsert(nums2, target2) << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "\nInput: nums = [1, 3, 5, 6], target = " << target3 << endl;
    cout << "Output: " << sol.searchInsert(nums3, target3) << endl;
    
    return 0;
}