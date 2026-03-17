#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int si, int ei, int target) {
    if(si > ei){
        return -1;
    }
            int mid = si + ((ei - si)/2);

            if(target == nums[mid]){
                return mid;
            }

            if(nums[si] <= nums[mid]){ // mid is on line 1
                if(nums[si] <= target && target <= nums[mid]){
                    // left part
                    return search(nums, si, mid, target);
                }
                else{
                    // Right part
                   return search(nums, mid+1, ei, target);
                }
            }
            else{ // mid is on line 2
                if(nums[mid] <= target && target <= nums[ei]){
                    // right part
                    return search(nums,mid+1, ei, target);
                }
                else{
                    // left part
                   return search(nums, si, mid, target);
                }
            }
    }

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<search(nums, 0, nums.size()-1, 0);
return 0;
}