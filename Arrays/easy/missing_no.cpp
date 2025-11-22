#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         unordered_map<int,bool> mp;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             mp[nums[i]] = true;
//         }

//         for(int i=0; i<=n; i++){
//             if(!mp[i]){
//                 return i;
//             }
//         }
//         return n;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            res += i - nums[i];
        }

        return res;
    }
};

int main() {
    // Example input
    vector<int> nums = {3, 0, 1};

    Solution obj;
    int ans = obj.missingNumber(nums);

    cout << "Missing Number: " << ans << endl;

    return 0;
}
