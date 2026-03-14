#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Helper class to store information about each subtree
class Info {
public:
    bool isBST;   // Is subtree a BST?
    int min;      // Minimum value in subtree
    int max;      // Maximum value in subtree
    int sum;      // Sum of subtree

    Info(bool isBST, int min, int max, int sum) {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxsum = 0;

    Info* largestBST(TreeNode* root) {
        if (root == nullptr) {
            return new Info(true, INT_MAX, INT_MIN, 0);
        }

        Info* left = largestBST(root->left);
        Info* right = largestBST(root->right);

        if (left->isBST && right->isBST &&
            left->max < root->val && root->val < right->min) {

            int sum = left->sum + right->sum + root->val;
            maxsum = max(maxsum, sum);

            return new Info(
                true,
                min(root->val, left->min),
                max(root->val, right->max),
                sum
            );
        }

        return new Info(false, INT_MIN, INT_MAX, max(left->sum, right->sum));
    }

    int maxSumBST(TreeNode* root) {
        maxsum = 0;
        largestBST(root);
        return maxsum;
    }
};

int main() {
    /*
        Example Tree:
                5
               / \
              4   8
             /   / \
            3   6   10

        BST Subtree with max sum = 3 + 4 + 5 + 6 + 8 + 10 = 36
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    Solution sol;
    cout << "Maximum Sum BST in Binary Tree: "
         << sol.maxSumBST(root) << endl;

    return 0;
}
