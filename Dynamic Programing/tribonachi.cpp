#include <iostream>
#include <vector>
using namespace std;

int tribonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    else if (n == 1 || n == 2) return 1;

    // Create a DP array to store results of subproblems
    vector<int> dp(n + 1, 0);

    // Initialize first three terms
    dp[0] = 0;
    dp[1] = dp[2] = 1;

    // Fill the DP table
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n = 25; // You can change n to test different values
    cout << "The " << n << "th Tribonacci number is: " << tribonacci(n) << endl;
    return 0;
}
