#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, int> inMap;

    TreeNode* helper(vector<int>& preorder, int& preIdx, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        int inIdx = inMap[rootVal];

        // Building Left then Right is crucial for Preorder logic
        root->left = helper(preorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, preIdx, inIdx + 1, right);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int preIdx = 0;
        return helper(preorder, preIdx, 0, inorder.size() - 1);
    }
};

// Helper function to print tree in Level Order (BFS) to verify result
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr) {
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Example Input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    cout << "Building tree..." << endl;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Level Order Result: ";
    printLevelOrder(root);

    return 0;
}