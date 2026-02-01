#include <bits/stdc++.h>
using namespace std;

/* ---------- Tree Node Definition ---------- */
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* ---------- BST Search (used in brute force) ---------- */
bool searchBST(TreeNode* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

/* ---------- Approach 1: Brute Force (n log m) ---------- */
void inorderAndSearch(TreeNode* root1, TreeNode* root2, int X, int &count) {
    if (root1 == nullptr) return;

    inorderAndSearch(root1->left, root2, X, count);

    int complement = X - root1->val;
    if (searchBST(root2, complement)) {
        count++;
    }

    inorderAndSearch(root1->right, root2, X, count);
}

int countPairsBruteForce(TreeNode* root1, TreeNode* root2, int X) {
    int count = 0;
    inorderAndSearch(root1, root2, X, count);
    return count;
}

/* ---------- Approach 2: HashMap / HashSet (n + m) ---------- */
void storeInSet(TreeNode* root, unordered_set<int> &s) {
    if (root == nullptr) return;
    storeInSet(root->left, s);
    s.insert(root->val);
    storeInSet(root->right, s);
}

void countUsingSet(TreeNode* root, unordered_set<int> &s, int X, int &count) {
    if (root == nullptr) return;

    countUsingSet(root->left, s, X, count);

    if (s.find(X - root->val) != s.end()) {
        count++;
    }

    countUsingSet(root->right, s, X, count);
}

int countPairsHashMap(TreeNode* root1, TreeNode* root2, int X) {
    unordered_set<int> s;
    storeInSet(root2, s);

    int count = 0;
    countUsingSet(root1, s, X, count);
    return count;
}

/* ---------- Main Function ---------- */
int main() {
    /*
        BST 1:
                5
               / \
              3   7
             / \ / \
            2  4 6  8

        BST 2:
                10
               /  \
              6    15
             / \   / \
            3  8 11  18

        X = 16
        Pairs: (5,11), (6,10), (8,8)
        Output = 3
    */

    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(6);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(8);
    root2->right->left = new TreeNode(11);
    root2->right->right = new TreeNode(18);

    int X = 16;

    cout << "Brute Force (n log m) Count = "
         << countPairsBruteForce(root1, root2, X) << endl;

    cout << "HashMap (n + m) Count = "
         << countPairsHashMap(root1, root2, X) << endl;

    return 0;
}
