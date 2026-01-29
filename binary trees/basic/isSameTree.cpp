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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;

        if (root1 == nullptr || root2 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;

        return isSameTree(root1->left, root2->left) &&
               isSameTree(root1->right, root2->right);
    }
};

int main() {
    /*
        Tree 1:
              1
             / \
            2   3

        Tree 2:
              1
             / \
            2   3
    */

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution sol;
    if (sol.isSameTree(root1, root2)) {
        cout << "Trees are identical";
    } else {
        cout << "Trees are NOT identical";
    }

    return 0;
}
