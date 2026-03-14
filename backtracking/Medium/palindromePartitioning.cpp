#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> part;

    bool isPali(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(int i, string &s) {
        // Base case: entire string is used
        if (i == s.size()) {
            res.push_back(part);
            return;
        }

        // Try all possible cuts starting at i
        for (int j = i; j < s.size(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1)); // choose
                dfs(j + 1, s);                          // explore
                part.pop_back();                        // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> ans = sol.partition(s);

    cout << "\nPalindrome Partitions:\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (auto &str : v) {
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}
