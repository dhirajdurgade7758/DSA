#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;            // Value of the node
    TreeNode *left;     // Pointer to left child
    TreeNode *right;    // Pointer to right child
    
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function: recursively check if all nodes have the same value
    bool isUnivalTreeHelper(TreeNode* root, int value){
        if(root == nullptr){
            return true; // Base case: empty subtree is valid
        }
        if(root->val != value){
            return false; // If any node has different value → not univalued
        }
        // Check both left and right subtrees
        return (isUnivalTreeHelper(root->left, value) && isUnivalTreeHelper(root->right, value));
    }  

    // Main function to check if tree is univalued
    bool isUnivalTree(TreeNode* root) {
        return isUnivalTreeHelper(root, root->val);
    }
};

// ---------------- MAIN FUNCTION TO TEST ----------------
int main(){
    /**
     * Example tree:
     *        1
     *       / \
     *      1   1
     *     / \
     *    1   1
     */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);

    Solution sol;
    if(sol.isUnivalTree(root)){
        cout << "The tree is a Univalued Tree ✅" << endl;
    } else {
        cout << "The tree is NOT a Univalued Tree ❌" << endl;
    }

    return 0;
}
