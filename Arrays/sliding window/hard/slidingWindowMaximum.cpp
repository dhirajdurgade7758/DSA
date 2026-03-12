#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int,int>> dq;

        for(int i = 0; i < nums.size(); i++){

            // Remove elements outside the window
            if(!dq.empty() && dq.front().second <= i - k){
                dq.pop_front();
            }

            // Remove smaller elements from back
            while(!dq.empty() && dq.back().first <= nums[i]){
                dq.pop_back();
            }

            dq.push_back({nums[i], i});

            // Window becomes valid
            if(i >= k - 1){
                ans.push_back(dq.front().first);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}