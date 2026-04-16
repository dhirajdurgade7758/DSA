#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

class Solution {
public:
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Move prev to node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* start = prev->next;  // left node
        ListNode* end = start;

        // Move end to right
        for (int i = left; i < right; i++) {
            end = end->next;
        }

        ListNode* nextRight = end->next;

        // Cut the sublist
        end->next = nullptr;

        // Reverse it
        ListNode* newHead = reverseList(start);

        // Reconnect
        prev->next = newHead;
        start->next = nextRight;

        return dummy->next;
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// Main function with test cases
int main() {
    Solution sol;
    
    // Test case 1: [1,2,3,4,5] with left=2, right=4
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1);
    cout << "Original list: ";
    printList(head1);
    head1 = sol.reverseBetween(head1, 2, 4);
    cout << "After reverseBetween(2, 4): ";
    printList(head1);
    cout << endl;
    
    // Test case 2: [5] with left=1, right=1
    vector<int> arr2 = {5};
    ListNode* head2 = createList(arr2);
    cout << "Original list: ";
    printList(head2);
    head2 = sol.reverseBetween(head2, 1, 1);
    cout << "After reverseBetween(1, 1): ";
    printList(head2);
    cout << endl;
    
    // Test case 3: [1,2] with left=1, right=2
    vector<int> arr3 = {1, 2};
    ListNode* head3 = createList(arr3);
    cout << "Original list: ";
    printList(head3);
    head3 = sol.reverseBetween(head3, 1, 2);
    cout << "After reverseBetween(1, 2): ";
    printList(head3);
    
    return 0;
}