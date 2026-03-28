#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i] != val){
                nums[k]=nums[i];
                i++;
                k++;
            }
            else{
                i++;
            }
        }
        return k;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: [3,2,2,3], val = 3
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    cout << "Test 1: k = " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i];
        if (i < k1 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Test case 2: [0,1,2,2,3,0,4,2], val = 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    cout << "Test 2: k = " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i];
        if (i < k2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    // Test case 3: [1], val = 1
    vector<int> nums3 = {1};
    int val3 = 1;
    int k3 = sol.removeElement(nums3, val3);
    cout << "Test 3: k = " << k3 << ", nums = [";
    for (int i = 0; i < k3; i++) {
        cout << nums3[i];
        if (i < k3 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}