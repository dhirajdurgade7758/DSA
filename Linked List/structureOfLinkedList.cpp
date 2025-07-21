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

    void reverse(){
        tail = head; 
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
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
bool isCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "cycle does not exist" << endl;
        return false; // A list with 0 or 1 node cannot have a cycle.
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            cout << "cycle exists" << endl;
            return true;
        }
    }

    // If we exit the loop, no cycle exists
    cout << "cycle does not exist" << endl;
    return false;
}

void removeCycle(Node* head){
    // detecting a cycle 

    Node* slow = head;
    Node* fast = head;
    bool iscycle = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            cout << "cycle exists" << endl;
            iscycle =true;
            break;
        }
    }
    if (!iscycle)
    {
        cout<<"cycle does not exists"<<endl;
    }
    
    // cycle removing part

    // edge case part
    slow = head;
    if(slow==fast){
        while (fast->next != slow)
        {
            fast= fast->next;
        }
        // removing last node connection
        fast->next = nullptr;
        cout<<"cycle removed"<<endl;
    }
    else{
    // normal case part
    Node*prev = nullptr;
    while (fast!=slow)
    {
        slow=slow->next;
        prev=fast;
        fast=fast->next;
    }
    // removing last node connection
    prev->next = nullptr;
    cout<<"cycle removed"<<endl;
    }

}


int main()
{
   List l1;
   l1.pushBack(1);
   l1.pushBack(2);
   l1.pushBack(3);
   l1.pushBack(4);
   l1.tail->next = l1.head;
    // isCycle(l1.head);
   removeCycle(l1.head);
   isCycle(l1.head);
   l1.printList();
    // l1.search(100);
    // l1.searchRec(100);
    // l1.pop_front();
    // l1.pop_back();
    // l1.printList();
    // l1.reverse();
    // l1.removeNthNodeFromEnd(3);
    // l1.printList();
return 0;
} 

