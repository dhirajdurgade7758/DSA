#include <iostream>
#include <vector>
using namespace std;

// Function to calculate nth Catalan number using tabulation (DP)
int catTab(int n) {
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[0] = dp[1] = 1;

    // Fill DP table
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // Catalan relation: Cn = Σ (Ci * Cn-i-1) for i = 0 to n-1
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n = 6;

    cout << "Catalan Numbers up to " << n - 1 << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "C" << i << " = " << catTab(i) << endl;
    }

    return 0;
}
