#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to handle head changes
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
            // Step 1: Check if k nodes exist
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) return dummy->next;
            }

            // Step 2: Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 3: Connect reversed group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }
    }
};

// ---------- Helper Functions ----------

ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int x : nums) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ---------- Main ----------
int main() {
    Solution sol;

    ListNode* head = createList({1, 2, 3, 4, 5});
    int k = 3;

    cout << "Original: ";
    printList(head);

    head = sol.reverseKGroup(head, k);

    cout << "Reversed in K Group: ";
    printList(head);

    return 0;
}
