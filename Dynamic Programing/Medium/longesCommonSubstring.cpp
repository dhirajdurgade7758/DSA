#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxi = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxi = max(maxi, dp[i][j]);
            } else {
                dp[i][j] = 0; // important for substring
            }
        }
    }

    return maxi;
}

int main() {
    string s1 = "abcde";
    string s2 = "abfce";

    cout << "Longest Common Substring Length: "
         << longestCommonSubstring(s1, s2) << endl;

    return 0;
}