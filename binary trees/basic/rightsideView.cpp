// #include <bits/stdc++.h>
// using namespace std;

// /**
//  * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     unordered_map<int, int> mp;
//     vector<int> ans;

//     void rightSideViewHelper(TreeNode* root, int vd) {
//         if (root == nullptr) return;

//         // First node encountered at this depth
//         if (mp.find(vd) == mp.end()) {
//             mp[vd] = root->val;
//             ans.push_back(root->val);
//         }

//         // Go right first
//         rightSideViewHelper(root->right, vd + 1);
//         rightSideViewHelper(root->left, vd + 1);
//     }

//     vector<int> rightSideView(TreeNode* root) {
//         rightSideViewHelper(root, 0);
//         return ans;
//     }
// };

// int main() {
//     /*
//         Sample Tree:
//                 1
//                / \
//               2   3
//                \   \
//                 5   4

//         Right Side View: 1 3 4
//     */

//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->right = new TreeNode(5);
//     root->right->right = new TreeNode(4);

//     Solution sol;
//     vector<int> result = sol.rightSideView(root);

//     cout << "Right Side View: ";
//     for (int x : result) {
//         cout << x << " ";
//     }
//     cout << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    vector<int> ans;

    void dfs(TreeNode* root, int level) {
        if (!root) return;

        // First node seen at this level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit right subtree first
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
        dfs(root, 0);
        return ans;
    }
};

int main() {
    /*
        Example Tree:
                1
               / \
              2   3
               \   \
                5   4

        Right Side View: 1 3 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
