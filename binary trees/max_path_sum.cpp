#include <iostream>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;             // Value of the node
    TreeNode *left;      // Pointer to left child
    TreeNode *right;     // Pointer to right child

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to compute maximum path sum including current node
    int maxPathDown(TreeNode* root, int &maxi) {
        if (root == nullptr) return 0;

        // Recursively calculate max path sum from left and right subtrees
        int left = max(0, maxPathDown(root->left, maxi));   // ignore negative paths
        int right = max(0, maxPathDown(root->right, maxi));

        // Update global maximum if path through root is greater
        maxi = max(maxi, root->val + left + right);

        // Return max gain (only one side) to parent
        return max(left, right) + root->val;
    }

    // Main function to return maximum path sum in binary tree
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};

// ---------- Test Code ----------
int main() {
    /*
           10
          /  \
         2   10
        / \     \
       20  1    -25
                 /  \
                3    4
    Expected Maximum Path Sum = 42 (20 + 2 + 10 + 10)
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}
