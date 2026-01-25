#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // Dummy node to help build new list
        Node* newhead = new Node(0);

        Node* oldcurr = head;
        Node* curr = newhead;

        // Map: original node -> copied node
        unordered_map<Node*, Node*> mp;

        // 1️⃣ Create copy of each node and store mapping
        while (oldcurr != NULL) {
            Node* newnode = new Node(oldcurr->val);
            curr->next = newnode;

            mp[oldcurr] = newnode;   // map original to copy

            oldcurr = oldcurr->next;
            curr = curr->next;
        }

        // 2️⃣ Assign random pointers using map
        curr = newhead->next;
        oldcurr = head;

        while (curr != NULL) {
            if (oldcurr->random != NULL) {
                curr->random = mp[oldcurr->random];
            }
            curr = curr->next;
            oldcurr = oldcurr->next;
        }

        return newhead->next;
    }
};

// ---------- Helper functions for testing ----------

// Print list: value and random value
void printList(Node* head) {
    while (head != NULL) {
        cout << "Val: " << head->val << ", Random: ";
        if (head->random)
            cout << head->random->val;
        else
            cout << "NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create test list
    // 1 -> 2 -> 1
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);

    n1->next = n2;
    n2->next = n3;

    // Random pointers
    n1->random = n3;
    n2->random = n1;
    n3->random = n2;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
