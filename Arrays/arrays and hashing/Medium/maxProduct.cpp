#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int leftProduct=1;
        int rightProduct=1;
        int ans=nums[0];

        for(int i=0; i<n; i++){
            if(leftProduct == 0) leftProduct=1;
            if(rightProduct == 0) rightProduct=1;
            
            leftProduct*=nums[i];
            rightProduct*=nums[n-i-1];

            ans=max(ans, max(leftProduct, rightProduct));
        }
        return ans;
 }


int main()
{
    vector<int> nums = {2,3,-2,4};
    cout<<maxProduct(nums)<<endl;

return 0;
}