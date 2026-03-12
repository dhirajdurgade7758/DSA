#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // Build left max array
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        // Build right max array
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        int waterTrapped = 0;

        for(int i = 0; i < n; i++){
            int currwater = min(leftMax[i], rightMax[i]) - height[i];
            if(currwater > 0){
                waterTrapped += currwater;
            }
        }

        return waterTrapped;
    }
};

int main() {
    Solution sol;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = sol.trap(height);

    cout << "Total Water Trapped: " << result << endl;

    return 0;
}