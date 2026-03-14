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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;   // store next
            curr->next = prev;   // reverse link

            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        return prev;  // new head
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create linked list
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
    head = sol.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
