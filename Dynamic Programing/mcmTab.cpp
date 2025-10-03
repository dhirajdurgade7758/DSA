#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

// Function to solve Matrix Chain Multiplication using Tabulation
int mcmTab(vector<int> arr) {
    int n = arr.size();

    // DP table, dp[i][j] = minimum cost to multiply matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len = chain length
    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try every possible partition point k
            for (int k = i; k < j; k++) {
                int cost1 = dp[i][k];       // cost of multiplying left set
                int cost2 = dp[k + 1][j];   // cost of multiplying right set
                int currCost = cost1 + cost2 + (arr[i - 1] * arr[k] * arr[j]);

                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    // Dimensions of matrices: A1(1x2), A2(2x3), A3(3x4), A4(4x3)
    vector<int> arr = {1, 2, 3, 4, 3};

    cout << "Minimum cost to multiply matrices = " << mcmTab(arr) << endl;

    return 0;
}
