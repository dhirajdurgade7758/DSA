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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head for result list
        ListNode* anshead = new ListNode(0);
        ListNode* curr = anshead;

        int carry = 0;

        // Loop until both lists and carry are exhausted
        while (l1 || l2 || carry > 0) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int sum = v1 + v2 + carry;
            carry = sum / 10;     // carry for next digit
            int digit = sum % 10; // current digit

            curr->next = new ListNode(digit);
            curr = curr->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return anshead->next;
    }
};

// ---------- Helper functions ----------

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
    // Example:
    // l1 = [2,4,3]
    // l2 = [5,6,4]
    // Output = [7,0,8]

    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum:    ";
    printList(result);

    return 0;
}
