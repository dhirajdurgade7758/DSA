#include<iostream>
#include<vector>
using namespace std;

 int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int vote = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(vote==0){
                vote=1;
                candidate = nums[i];
            }
            else{
                if(nums[i] == candidate){
                    vote++;
                }
                else{
                    vote--;
                }
            }
        }
        return candidate;
    }

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement(nums);

return 0;
}