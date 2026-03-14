#include <iostream>
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
    // Reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Split list at middle and return right half head
    ListNode* splitAtMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr) {
            prev->next = nullptr; // split the list
        }
        return slow; // right half head
    }

    // Reorder list
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode* rightHead = splitAtMid(head);
        ListNode* rightHeadRev = reverseList(rightHead);

        ListNode* left = head;
        ListNode* right = rightHeadRev;
        ListNode* tail = nullptr;

        while (left != nullptr && right != nullptr) {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;

            left->next = right;
            right->next = leftNext;

            tail = right;

            left = leftNext;
            right = rightNext;
        }

        if (right != nullptr) {
            tail->next = right;
        }
    }
};

// Helper: print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper: create list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    sol.reorderList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
