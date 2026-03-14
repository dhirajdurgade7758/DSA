#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Base case: empty list
        if (head == nullptr) {
            return head;
        }

        // Step 1: Check if k nodes exist
        int count = 0;
        ListNode* temp = head;

        while (count < k) {
            if (temp == nullptr) {
                return head;   // less than k nodes
            }
            temp = temp->next;
            count++;
        }

        // Step 2: Reverse remaining list recursively
        ListNode* prev = reverseKGroup(temp, k);

        // Step 3: Reverse current k-group
        temp = head;
        count = 0;
        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        return prev;
    }
};

// ---------- Helper Functions ----------

// Create linked list from vector
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    for (int x : nums) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy->next;
}

// Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example:
    // Input: 1 -> 2 -> 3 -> 4 -> 5, k = 2
    // Output: 2 -> 1 -> 4 -> 3 -> 5

    ListNode* head = createList({1, 2, 3, 4, 5});
    int k = 2;

    cout << "Original List: ";
    printList(head);

    ListNode* result = sol.reverseKGroup(head, k);

    cout << "Reversed in K Group: ";
    printList(result);

    return 0;
}
