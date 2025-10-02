#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to calculate number of unique BSTs (Catalan number)
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs possible with i nodes
        vector<int> dp(n + 1, 0);

        // Base cases: Empty tree (0 nodes) and single node tree both count as 1
        dp[0] = dp[1] = 1;

        // Build up the dp table
        for (int i = 2; i <= n; i++) {
            // Consider each node as root
            for (int j = 0; j < i; j++) {
                // dp[j] = number of nodes in left subtree
                // dp[i - j - 1] = number of nodes in right subtree
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n]; // Final answer = number of BSTs possible with n nodes
    }
};

int main() {
    Solution sol;
    int n = 6; // Example input
    cout << "Number of unique BSTs with " << n << " nodes = " << sol.numTrees(n) << endl;

    // Print results for multiple values of n
    cout << "\nUnique BST counts for n = 0 to " << n << ":\n";
    for (int i = 0; i <= n; i++) {
        cout << "n = " << i << " -> " << sol.numTrees(i) << endl;
    }

    return 0;
}
