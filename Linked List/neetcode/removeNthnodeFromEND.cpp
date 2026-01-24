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
    int getsize(ListNode* head) {
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case: empty list or single node removal
        if (head == nullptr || (head->next == nullptr && n == 1)) {
            return nullptr;
        }

        int size = getsize(head);

        // If head itself needs to be removed
        if (n == size) {
            ListNode* newHead = head->next;
            return newHead;
        }

        ListNode* prev = head;
        for (int i = 1; i < (size - n); i++) {
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return head;
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
    int removeN = 2; // remove 2nd node from end
    head = sol.removeNthFromEnd(head, removeN);

    cout << "After Removing " << removeN << "th Node From End: ";
    printList(head);

    return 0;
}
