#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }

        while(!pq.empty() && k > 1){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};

int main() {

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    Solution obj;
    int result = obj.findKthLargest(nums, k);

    cout << "Kth Largest Element: " << result << endl;

    return 0;
}