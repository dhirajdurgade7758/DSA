#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // #Using optimized approch# //

        // int count0 = 0, count1 = 0, count2 = 0;

        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==0) count0++;
        //     else if(nums[i]==1) count1++;
        //     else if(nums[i]==2) count2++;
        // }

        // int idx = 0;
        // for(int i=0; i<count0; i++ ){
        //     nums[idx++] = 0;
        // }
        // for(int i=0; i<count1; i++){
        //     nums[idx++] = 1;
        // }
        // for(int i=0; i<count2; i++){
        //     nums[idx++] = 2;
        // }

        //# Using dutch national flag algoritum #//

        int n = nums.size();
        int mid=0, high=n-1, low=0;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Main function for testing
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    cout << "Test 1 - Before: ";
    for(int num : nums1) cout << num << " ";
    solution.sortColors(nums1);
    cout << "\nAfter: ";
    for(int num : nums1) cout << num << " ";
    cout << "\n\n";
    
    // Test case 2
    vector<int> nums2 = {2, 0, 1};
    cout << "Test 2 - Before: ";
    for(int num : nums2) cout << num << " ";
    solution.sortColors(nums2);
    cout << "\nAfter: ";
    for(int num : nums2) cout << num << " ";
    cout << "\n\n";
    
    // Test case 3
    vector<int> nums3 = {0};
    cout << "Test 3 - Before: ";
    for(int num : nums3) cout << num << " ";
    solution.sortColors(nums3);
    cout << "\nAfter: ";
    for(int num : nums3) cout << num << " ";
    cout << "\n\n";
    
    // Test case 4
    vector<int> nums4 = {1, 2, 0, 1, 2, 0, 0, 1};
    cout << "Test 4 - Before: ";
    for(int num : nums4) cout << num << " ";
    solution.sortColors(nums4);
    cout << "\nAfter: ";
    for(int num : nums4) cout << num << " ";
    cout << "\n";
    
    return 0;
}