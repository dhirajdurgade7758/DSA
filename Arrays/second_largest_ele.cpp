#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        int largest=INT_MIN;
        int secondLargest = INT_MIN;
        int n=nums.size();
        if(n<2){
            return -1;
        }

        for(int i=0; i<n; ++i){
            if(nums[i] > largest){
                secondLargest=largest;
                largest=nums[i];
            }
            else if(nums[i] > secondLargest && nums[i] != largest){
                secondLargest = nums[i];
            }
        }

        if(secondLargest != INT_MIN){
            return secondLargest;
        }

        return -1;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums1 = {1, 5, 3, 9, 2};
    cout << "Second largest in [1,5,3,9,2]: " << sol.secondLargestElement(nums1) << endl;
    
    vector<int> nums2 = {10, 10, 10};
    cout << "Second largest in [10,10,10]: " << sol.secondLargestElement(nums2) << endl;
    
    vector<int> nums3 = {1};
    cout << "Second largest in [1]: " << sol.secondLargestElement(nums3) << endl;
    
    vector<int> nums4 = {5, 2, 8, 3};
    cout << "Second largest in [5,2,8,3]: " << sol.secondLargestElement(nums4) << endl;
    
    return 0;
}