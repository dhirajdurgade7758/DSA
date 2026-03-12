#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int maxcount = 0;

        // Insert all elements into set
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }

        // Check start of sequence
        for(int it : s){
            if(s.find(it - 1) == s.end()){
                int count = 1;
                int currnum = it;

                while(s.find(currnum + 1) != s.end()){
                    currnum++;
                    count++;
                }

                maxcount = max(maxcount, count);
            }
        }

        return maxcount;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {100,4,200,1,3,2};

    int result = sol.longestConsecutive(nums);

    cout << "Longest Consecutive Sequence Length: " << result << endl;

    return 0;
}