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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        if (left == -1 || right == -1) {
            return -1;
        }

        if (abs(left - right) <= 1) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "Tree is Balanced";
    } else {
        cout << "Tree is Not Balanced";
    }

    return 0;
}
