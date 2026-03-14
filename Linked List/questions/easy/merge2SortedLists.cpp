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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();  // dummy node
        ListNode* temp = ans;

        ListNode* i = list1;
        ListNode* j = list2;

        while (i != nullptr && j != nullptr) {
            if (i->val <= j->val) {
                temp->next = i;
                i = i->next;
            } else {
                temp->next = j;
                j = j->next;
            }
            temp = temp->next;
        }

        // Attach remaining nodes
        while (i != nullptr) {
            temp->next = i;
            i = i->next;
            temp = temp->next;
        }

        while (j != nullptr) {
            temp->next = j;
            j = j->next;
            temp = temp->next;
        }

        return ans->next;  // skip dummy node
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create list from array
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
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode* list1 = createList(arr1, n1);
    ListNode* list2 = createList(arr2, n2);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
