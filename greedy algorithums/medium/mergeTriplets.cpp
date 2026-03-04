/*
PROBLEM: Merge Triplets to Form Target Triplet
===============================================
Given a list of triplets and a target triplet, determine if you can merge some 
triplets from the list to form the target triplet.

Rules:
- A triplet can be selected if all its values are less than or equal to the 
  corresponding target values (s[i] <= target[i] for all i).
- From valid triplets, take the maximum value at each position.
- If the resulting triplet equals the target, return true; otherwise, return false.

Example:
    triplets = [[2,5,3],[1,8,4],[1,7,5]]
    target = [2,7,5]
    Output: true
    Explanation: Merge [1,7,5] and [2,5,3] to get [max(1,2), max(7,5), max(5,3)] = [2,7,5]

Time Complexity: O(n) where n is the number of triplets
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> res(3, INT_MIN);

        for (auto s : triplets) {
            if (s[0] <= target[0] && s[1] <= target[1] && s[2] <= target[2]) {
                res[0] = max(res[0], s[0]);
                res[1] = max(res[1], s[1]);
                res[2] = max(res[2], s[2]);
            }
        }

        return res == target;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> triplets = {
        {2,5,3},
        {1,8,4},
        {1,7,5}
    };

    vector<int> target = {2,7,5};

    bool ans = obj.mergeTriplets(triplets, target);

    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}