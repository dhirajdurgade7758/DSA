#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        //your code goes here
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums1 = {1, 5, 3, 9, 2};
    cout << "Index of 3 in [1,5,3,9,2]: " << sol.linearSearch(nums1, 3) << endl;
    
    cout << "Index of 7 in [1,5,3,9,2]: " << sol.linearSearch(nums1, 7) << endl;
    
    vector<int> nums2 = {10, 20, 30, 40};
    cout << "Index of 40 in [10,20,30,40]: " << sol.linearSearch(nums2, 40) << endl;
    
    return 0;
}