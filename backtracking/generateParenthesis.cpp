#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int n, int lcount, int rcount,
                string comb, vector<string>& ans) {

        // parenthesis completed
        if (lcount == n && rcount == n) {
            ans.push_back(comb);
            return;
        }

        // go left
        if (lcount < n) {
            helper(n, lcount + 1, rcount, comb + "(", ans);
        }

        // go right
        if (lcount > rcount) {
            helper(n, lcount, rcount + 1, comb + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, 0, 0, "", ans);
        return ans;
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<string> result = sol.generateParenthesis(n);

    cout << "Valid Parentheses combinations:\n";
    for (auto &s : result) {
        cout << s << endl;
    }

    return 0;
}
