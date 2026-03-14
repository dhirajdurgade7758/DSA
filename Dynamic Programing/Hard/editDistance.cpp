#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i][j] = minimum operations required to convert
        // first i characters of word1 → first j characters of word2
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base cases:
        // If word2 is empty, we need to delete all characters of word1
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        // If word1 is empty, we need to insert all characters of word2
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match → no extra operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters don't match → choose best of:
                    // 1. Insert (dp[i][j-1])
                    // 2. Delete (dp[i-1][j])
                    // 3. Replace (dp[i-1][j-1])
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[n][m]; // Final answer: min operations to convert word1 → word2
    }
};

// ---------------- DRIVER CODE ----------------
int main() {
    Solution sol;

    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum operations to convert \"" << word1 
         << "\" → \"" << word2 << "\" = " 
         << sol.minDistance(word1, word2) << endl;

    return 0;
}
