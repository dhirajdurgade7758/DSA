#include <iostream>
#include <climits>
using namespace std;

/* Tree Node */
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int mindiff = INT_MAX;

    // Function to find the least absolute difference between any node value and K
    int minDiff(Node *root, int K) {
        if (root == NULL) return mindiff;

        // Update the minimum difference
        mindiff = min(mindiff, abs(K - root->data));

        // Use BST property:
        if (K < root->data) {
            // If K is smaller, closer value must be in left subtree
            return minDiff(root->left, K);
        } 
        else {
            // If K is larger or equal, closer value must be in right subtree
            return minDiff(root->right, K);
        }
    }
};

// Helper function to create a sample BST
Node* createSampleBST() {
    /*
              10
             /  \
            5    15
           / \     \
          3   7     18
    */
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);

    return root;
}

int main() {
    Solution sol;
    Node* root = createSampleBST();

    int K = 12;
    int result = sol.minDiff(root, K);

    cout << "Minimum absolute difference with " << K << " is: " << result << endl;

    return 0;
}
