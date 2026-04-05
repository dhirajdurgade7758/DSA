#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to calculate the sum of all nodes within a given range [low, high]
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return 0; // Base case: empty tree
        }

        // Recursive calls on left and right subtrees
        int leftSum = rangeSumBST(root->left, low, high);
        int rightSum = rangeSumBST(root->right, low, high);

        // If current node value lies within the range, include it in the sum
        if(root->val >= low && root->val <= high) {
            return leftSum + rightSum + root->val;
        }

        // Otherwise, return sum of left and right subtrees only
        return leftSum + rightSum;
    }
};

// Helper function to create a sample BST for testing
TreeNode* createSampleBST() {
    /*
              10
             /  \
            5    15
           / \     \
          3   7     18
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleBST();

    int low = 7, high = 15;
    int result = sol.rangeSumBST(root, low, high);

    cout << "Range Sum of BST within [" << low << ", " << high << "] is: " << result << endl;

    return 0;
}
