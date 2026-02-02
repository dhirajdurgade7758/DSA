// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     while (root != NULL) {
//         if (p->val < root->val && q->val < root->val) {
//             root = root->left;
//         }
//         else if (p->val > root->val && q->val > root->val) {
//             root = root->right;
//         }
//         else {
//             return root; // split point
//         }
//     }
//     return NULL;
// }

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
    // 🔥 Iterative (BEST for interviews)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root; // split point (LCA found)
            }
        }
        return NULL;
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

    TreeNode* p = root->left;        // Node 2
    TreeNode* q = root->right;       // Node 8

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    if (ans != NULL) {
        cout << "LCA: " << ans->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
