#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix product
        for(int i = 1; i < n; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        // Suffix product
        int suffix = 1;
        for(int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product Except Self: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}