/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to generate unique string for each subtree
    // Format: "nodeValue,leftSubtree,rightSubtree"
    string getSubTreeString(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& res) {
        if(root == nullptr) {
            return "N"; // Null child marker
        }

        // Serialize current subtree
        string s = to_string(root->val) + "," +
                   getSubTreeString(root->left, mp, res) + "," +
                   getSubTreeString(root->right, mp, res);

        // If the subtree serialization already exists once, 
        // it means this is the second occurrence → duplicate found
        if(mp[s] == 1) {
            res.push_back(root);
        }

        // Increase count of this subtree pattern
        mp[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;  // stores serialized subtree → count
        vector<TreeNode*> res;          // stores root nodes of duplicate subtrees
        getSubTreeString(root, mp, res);
        return res;
    }
};
