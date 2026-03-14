#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string t, string p) {
        int n = t.size(); // length of text
        int m = p.size(); // length of pattern

        // dp[i][j] → true if first i chars of text match first j chars of pattern
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: empty text "" matches empty pattern ""
        dp[0][0] = true;

        // If text is empty, pattern must only contain '*' to match
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1]; // '*' can represent empty sequence
            } else {
                dp[0][j] = false;
            }
        }

        // Fill DP table (bottom-up)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == t[i - 1]) {
                    // Case 1: characters match
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '?') {
                    // Case 2: '?' matches any single character
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    // Case 3: '*' matches empty sequence (dp[i][j-1]) 
                    // or matches one/more chars (dp[i-1][j])
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else {
                    // Case 4: characters do not match
                    dp[i][j] = false;
                }
            }
        }

        // Final result: does whole text match whole pattern?
        return dp[n][m];
    }
};

// ---------------- DRIVER CODE ----------------
int main() {
    Solution sol;

    string text = "adceb";
    string pattern = "*a*b";

    if (sol.isMatch(text, pattern)) {
        cout << "Pattern \"" << pattern << "\" matches text \"" << text << "\" ✅" << endl;
    } else {
        cout << "Pattern \"" << pattern << "\" does NOT match text \"" << text << "\" ❌" << endl;
    }

    return 0;
}
