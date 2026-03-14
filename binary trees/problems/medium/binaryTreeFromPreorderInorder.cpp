#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> inMap;

    TreeNode* helper(vector<int>& preorder, int& preIdx, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        root->left = helper(preorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return helper(preorder, preIdx, 0, inorder.size() - 1);
    }
};

// Function to print inorder traversal (to verify tree)
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution obj;
    TreeNode* root = obj.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);

    return 0;
}