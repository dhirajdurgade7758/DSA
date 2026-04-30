
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, 0);

        // base case already handled: dp[n] = 0

        for (int i = n - 1; i >= 0; i--) {
            // Option 1: take current char as extra
            dp[i] = 1 + dp[i + 1];

            string temp = "";

            // Option 2: try forming words
            for (int j = i; j < n; j++) {
                temp += s[j];

                if (dict.count(temp)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};