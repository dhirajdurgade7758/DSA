/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getsize(ListNode* head){
    ListNode* temp = head;
    int size=0;
    while (temp!=nullptr)
    {
        temp = temp->next;
        size++;
    }
    return size;
    
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = getsize(headA);
        int sizeB = getsize(headB);

        int d=0;
        if(sizeA>sizeB){
            d=sizeA-sizeB;
            while(d){
            headA=headA->next;
            d--;
        }

        }
        else{
            d=sizeB-sizeA;
            while(d){
                headB=headB->next;
                d--;
            }
        }

        while(headA!=nullptr && headB!=nullptr){
            if(headA==headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;

    }
};