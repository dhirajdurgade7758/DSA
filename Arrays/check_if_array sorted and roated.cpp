#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }
        if(count == 1 && nums[0] > nums[n-1]){
            return true;
        }
        else if(count == 0){
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Array [3,4,5,1,2] is sorted and rotated: " << (sol.check(nums1) ? "true" : "false") << endl;
    
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Array [1,2,3,4,5] is sorted and rotated: " << (sol.check(nums2) ? "true" : "false") << endl;
    
    vector<int> nums3 = {2, 1};
    cout << "Array [2,1] is sorted and rotated: " << (sol.check(nums3) ? "true" : "false") << endl;
    
    return 0;
}