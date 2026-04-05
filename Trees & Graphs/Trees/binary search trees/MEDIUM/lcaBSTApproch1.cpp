#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void getPath(TreeNode* root, int val, vector<TreeNode*>& path) {
        if (root == NULL) {
            return;
        }

        path.push_back(root);

        if (root->val == val) {
            return;
        }

        if (val < root->val) {
            getPath(root->left, val, path);
        } else {
            getPath(root->right, val, path);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        getPath(root, p->val, path1);
        getPath(root, q->val, path2);

        TreeNode* lca = NULL;

        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) {
                break;
            }
            lca = path1[i];
        }

        return lca;
    }
};

int main() {
    /*
            6
           / \
          2   8
         / \ / \
        0  4 7  9
          / \
         3   5
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);

    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;              // Node 2
    TreeNode* q = root->left->right;       // Node 4

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    if (ans != NULL) {
        cout << "LCA: " << ans->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
