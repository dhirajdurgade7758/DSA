#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
    // ~Node(){
    //     if(next != nullptr){
    //         cout<<"~Node() "<<data<<endl;
    //         delete next;
    //         next = nullptr;
    //     }
    // }
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = nullptr;
        tail = nullptr;
    }
    // ~List(){
    //     if(head != nullptr){
    //         cout<<"~List() "<<endl;
    //         delete head;
    //         head = nullptr;
    //     }
    // }
    void pushFront(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head =tail= newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void pushBack(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head =tail= newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void printList(){
        Node* temp = head;
        while (temp != nullptr)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"Null"<<endl;
        
    }

    void insert(int val, int pos){
        Node* newnode = new Node(val);
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp->next == nullptr){
                cout<<"position is invalid";
            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void pop_front(){
        if(head == nullptr){
            cout<<"list is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        cout<<"the node "<<temp->data<<" is deleted"<<endl;
        delete temp;
    }
    void pop_back(){
        Node* temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        cout<<"the node "<<tail->data<<" is deleted"<<endl;
        delete tail;
        tail = temp;        
    }

    void search(int ele){
        Node* temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data==ele)
            {
                cout<<"element found at positon "<<pos<<endl;
                return;
            }
            
            temp=temp->next;
            pos++;
        }
        cout<<"element does not exist in the list"<<endl;
        
    }

    int helper(Node* temp, int ele){
        if(temp == nullptr){
            return -1;
        }
        if(temp->data == ele){
            return 0;
        }

       int indx = helper(temp->next, ele);
       if(indx == -1){
        return -1;
       }

       return indx+1;
    }

    void searchRec(int ele){
        int ans = helper(head, ele);
        cout<<"element found at index: "<<ans<<endl;
    }

int getsize(){
    Node* temp = head;
    int size=0;
    while (temp!=nullptr)
    {
        temp = temp->next;
        size++;
    }
    return size;
    
}

 void removeNthNodeFromEnd(int n) {
    int size = getsize();

    Node*prev = head;
    for(int i=1; i<(size-n); i++){
        prev = prev->next;
    }

    Node* todel = prev->next;
    prev->next = prev->next->next;
}



};

    Node* reverse(Node* head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

Node* splitAtMid(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=nullptr;

    while (fast!=nullptr && fast->next!=nullptr)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }

    if (prev!=nullptr) //checking for single node list
    {
        prev->next = nullptr; // spliting the list at middel
    }
    
    return slow; //slow = righthead
    
}

void zigZag(Node* head){
    Node* righthead = splitAtMid(head);
    Node* rightHeadRev = reverse(righthead);

    Node* left=head;
    Node* right = rightHeadRev;
    Node* tail = right;
    while (left!=nullptr && right!=nullptr)
    {
        Node* rightNext = right->next;
        Node* leftNext = left->next;

        left->next = right;
        right->next = leftNext;

        tail=right;

        left=leftNext;
        right=rightNext;

    }
    if (right!=nullptr)
    {
     tail->next = right;
    }
}


int main()
{
   List l1;
   l1.pushBack(1);
   l1.pushBack(2);
   l1.pushBack(3);
   l1.pushBack(4);
   l1.pushBack(5);
   l1.pushBack(6);
   l1.pushBack(7);
   l1.printList();
   zigZag(l1.head);
   l1.printList();
return 0;
} 

