#include <iostream>
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
    int count = 0;
    int ans = -1;

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return ans;

        kthSmallest(root->left, k);

        count++;
        if(count == k){
            ans = root->val;
            return ans;
        }

        kthSmallest(root->right, k);
        return ans;
    }
};

int main() {

    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    int k = 3;

    Solution obj;
    int result = obj.kthSmallest(root, k);

    cout << "Kth Smallest Element: " << result << endl;

    return 0;
}