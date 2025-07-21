#include<iostream>
#include<vector>
using namespace std;

    int xorBeauty(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }

int main()
{
    vector<int> nums = {1,4,5,6,20};
    cout<<xorBeauty(nums);

return 0;
}