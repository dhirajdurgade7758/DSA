#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int st = i + 1;
            int end = n - 1;

            while (st < end) {
                int sum = nums[i] + nums[st] + nums[end];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[st], nums[end]});
                    st++;
                    end--;

                    // Skip duplicate second element
                    while (st < end && nums[st] == nums[st - 1]) st++;

                    // Skip duplicate third element
                    while (st < end && nums[end] == nums[end + 1]) end--;
                }
                else if (sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "Triplets with sum 0:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}


// class Solution {
// public:
//     // Custom hash for vector<int>
//     struct VectorHash {
//         size_t operator()(const vector<int>& v) const {
//             size_t hash = 0;
//             for (int x : v) {
//                 hash ^= std::hash<int>()(x) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
//             }
//             return hash;
//         }
//     };

//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         unordered_set<vector<int>, VectorHash> ans;
//         int n = nums.size();

//         for (int i = 0; i < n - 2; i++) {
//             int st = i + 1;
//             int end = n - 1;

//             while (st < end) {
//                 int sum = nums[i] + nums[st] + nums[end];

//                 if (sum == 0) {
//                     ans.insert({nums[i], nums[st], nums[end]});
//                     st++;
//                     end--;
//                 }
//                 else if (sum < 0) {
//                     st++;
//                 }
//                 else {
//                     end--;
//                 }
//             }
//         }

//         // Convert unordered_set → vector
//         return vector<vector<int>>(ans.begin(), ans.end());
//     }
// };

