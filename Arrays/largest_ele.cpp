#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums1 = {1, 5, 3, 9, 2};
    cout << "Largest element in [1,5,3,9,2]: " << sol.largestElement(nums1) << endl;
    
    vector<int> nums2 = {-5, -2, -10, -1};
    cout << "Largest element in [-5,-2,-10,-1]: " << sol.largestElement(nums2) << endl;
    
    vector<int> nums3 = {100};
    cout << "Largest element in [100]: " << sol.largestElement(nums3) << endl;
    
    return 0;
}