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