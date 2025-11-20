#include<iostream>
#include<vector>
using namespace std;


    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int k=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                k++;
                nums[k] = nums[i];
            }
        }
        k++;
        return k;
    }

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<"unique values from arrays are: "<<removeDuplicates(nums)<<endl;
return 0;
}