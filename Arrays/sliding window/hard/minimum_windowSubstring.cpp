#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        // Edge case checks
        if (t == "") return "";
        if (s.size() < t.size()) return "";

        // Frequency map for string t
        unordered_map<char, int> T;

        // Frequency map for current window
        unordered_map<char, int> win;

        // Fill map for t
        for (char c : t) {
            T[c]++;
        }

        int left = 0, right = 0;
        int have = 0;
        int need = T.size();

        int res = INT_MAX;
        pair<int, int> anspoint = {0, 0};

        // Sliding window
        while (right < s.length()) {

            char curr = s[right];

            // Add current character to window
            if (T.find(curr) != T.end()) {
                win[curr]++;
                if (win[curr] == T[curr]) {
                    have++;
                }
            }

            // Try to shrink the window
            while (have == need) {

                int currwin = right - left + 1;
                if (currwin < res) {
                    res = currwin;
                    anspoint = {left, right};
                }

                // Remove left character
                if (T.find(s[left]) != T.end()) {
                    if (win[s[left]] == T[s[left]]) {
                        have--;
                    }
                    win[s[left]]--;
                }
                left++;
            }

            right++;
        }

        if (res == INT_MAX) return "";

        return s.substr(anspoint.first, res);
    }
};

int main() {
    Solution sol;

    // Test input
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Function call
    string result = sol.minWindow(s, t);

    // Output
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}
