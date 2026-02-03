#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int maxSoFar, int &count) {
        if (!root) return;

        // Check if current node is good
        if (root->val >= maxSoFar) {
            count++;
        }

        // Update max value seen so far
        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar, count);
        dfs(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }
};

int main() {
    /*
        Example Tree:
                3
               / \
              1   4
             /   / \
            3   1   5

        Good Nodes = 4
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    cout << "Number of Good Nodes: " << sol.goodNodes(root) << endl;

    return 0;
}
