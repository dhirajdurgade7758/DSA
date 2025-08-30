#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;            // Node value
    TreeNode *left;     // Left child
    TreeNode *right;    // Right child

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to invert the binary tree (mirror image)
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr; // Base case: empty tree
        }
        
        // Recursively invert left & right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Swap left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root; // Return new root after inversion
    }
};

// Helper function: print inorder traversal
void inorder(TreeNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------------- MAIN FUNCTION TO TEST ----------------
int main(){
    /**
     * Original Tree:
     *        4
     *       / \
     *      2   7
     *     / \ / \
     *    1  3 6  9
     */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Inorder before inversion: ";
    inorder(root);
    cout << endl;

    Solution sol;
    root = sol.invertTree(root);

    cout << "Inorder after inversion: ";
    inorder(root);
    cout << endl;

    return 0;
}
