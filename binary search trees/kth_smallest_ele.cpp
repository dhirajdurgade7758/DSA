#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    int count = 0;  // Counter to track visited nodes in inorder traversal
    int ans;        // Stores the kth smallest value

    // Function to find the kth smallest element in BST
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;

        // Traverse left subtree (smaller values)
        kthSmallest(root->left, k);

        // Visit the current node
        count++;
        if (count == k) {   // If current node is the kth node
            ans = root->val;
            return ans;
        }

        // Traverse right subtree (larger values)
        kthSmallest(root->right, k);

        return ans;
    }
};

// Helper function to create a sample BST
TreeNode* createSampleBST() {
    /*
              5
             / \
            3   6
           / \
          2   4
         /
        1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleBST();

    int k = 3;
    int result = sol.kthSmallest(root, k);

    cout << k << "rd smallest element in BST is: " << result << endl;

    return 0;
}
