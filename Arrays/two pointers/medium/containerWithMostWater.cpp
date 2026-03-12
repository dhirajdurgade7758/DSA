#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;
        int ans = 0;

        while(lp < rp){
            int w = rp - lp;
            int h = min(height[lp], height[rp]);
            int areawt = w * h;

            ans = max(ans, areawt);

            // Move pointer of smaller height
            height[lp] < height[rp] ? lp++ : rp--;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = sol.maxArea(height);

    cout << "Maximum Water Container Area: " << result << endl;

    return 0;
}