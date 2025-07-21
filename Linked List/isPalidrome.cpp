/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // reversing the orignal list 
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        //checking both orignal and reversed list 
        temp = head;
        int i=0;
        while(temp!=nullptr){
            if(temp->val!=arr[i]){
                return false;
            }
            i++;
            temp=temp->next;
        }
        return true;
        
    }
};