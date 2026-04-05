#include <bits/stdc++.h>
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

int minDiffBST(TreeNode* root, int K) {
    int closest = root->val;

    while (root != nullptr) {
        if (abs(root->val - K) < abs(closest - K)) {
            closest = root->val;
        }

        if (K < root->val) {
            root = root->left;
        } else if (K > root->val) {
            root = root->right;
        } else {
            // exact match
            return root->val;
        }
    }
    return closest;
}

int main() {
    /*
        BST:
                8
               / \
              5   11
             / \    \
            3   6    20
    */

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(20);

    int K1 = 5;
    int K2 = 19;

    cout << "Closest value to " << K1 << " = "
         << minDiffBST(root, K1) << endl;

    cout << "Closest value to " << K2 << " = "
         << minDiffBST(root, K2) << endl;

    return 0;
}
