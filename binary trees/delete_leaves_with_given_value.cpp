#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr)
            return nullptr;

        // Process children first (postorder)
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // If current node is leaf and equals target
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }

        return root;
    }
};

// Inorder traversal for checking result
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
            1
           / \
          2   3
         /   / \
        2   2   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    int target = 2;

    Solution sol;
    root = sol.removeLeafNodes(root, target);

    cout << "Inorder Traversal after removal: ";
    inorder(root);

    return 0;
}
