#include<iostream>
#include<vector>
using namespace std;

int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxProduct=INT_MIN;
        int currProduct=1;
        for(int i=0; i<n; i++){
            currProduct*=nums[i];
            maxProduct=max(maxProduct, currProduct);
            if(currProduct < 0){
                currProduct=0;
            }
        }
        return maxProduct;
}


int main()
{
    vector<int> nums = {2,3,-2,4};
    cout<<maxProduct(nums)<<endl;

return 0;
}