#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

    // Build list: 1 -> 2 -> 3 -> 4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle: 4 -> 2
    fourth->next = second;

    Solution sol;

    if (sol.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    // Example without cycle
    fourth->next = nullptr;

    if (sol.hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
