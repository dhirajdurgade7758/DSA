#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        int indx = 0;

        for(int i = 0; i < strs.size(); i++) {
            string currstr = strs[i];
            sort(currstr.begin(), currstr.end());

            if(mp.find(currstr) == mp.end()) {
                ans.push_back({strs[i]});
                mp[currstr] = indx;
                indx++;
            }
            else {
                ans[mp[currstr]].push_back(strs[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for(auto &group : result) {
        cout << "[ ";
        for(auto &word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}