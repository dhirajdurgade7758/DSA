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
    // Serialize subtree and detect duplicates
    string getSubTreeString(TreeNode* root,
                            unordered_map<string,int>& mp,
                            vector<TreeNode*>& res) {
        if (root == nullptr) {
            return "N"; // null marker
        }

        string s = to_string(root->val) + "," +
                   getSubTreeString(root->left, mp, res) + "," +
                   getSubTreeString(root->right, mp, res);

        // If subtree appears second time, store root
        if (mp[s] == 1) {
            res.push_back(root);
        }

        mp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> res;
        getSubTreeString(root, mp, res);
        return res;
    }
};

// Inorder traversal (for checking duplicate subtrees)
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
        4   2   4
           /
          4

    Duplicate subtrees:
    - Subtree rooted at 4
    - Subtree rooted at 2 -> 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    Solution sol;
    vector<TreeNode*> duplicates = sol.findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees (Inorder Traversal):\n";
    for (auto node : duplicates) {
        inorder(node);
        cout << endl;
    }

    return 0;
}
