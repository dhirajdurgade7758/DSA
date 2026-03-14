#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyList{
    public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = nullptr;
        tail = nullptr;
    }

    void pushFront(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head =tail= newnode;
        }
        else{
            newnode->next = head;
            head->prev =newnode;
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
            newnode->prev=tail;
            tail = newnode;
        }
    }

    void printList(){
        Node* temp = head;
        while (temp != nullptr)
        {
            cout<<temp->data<<" <=> ";
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
        if(head!=nullptr){
            head->prev = nullptr;
        }
        temp->next = nullptr;
        cout<<"the node "<<temp->data<<" is deleted"<<endl;
        delete temp;
    }
    void pop_back(){
        if(head == nullptr){
            cout<<"list is empty"<<endl;
            return;
        }

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


};


int main()
{
   DoublyList l1;
   l1.pushBack(1);
   l1.pushBack(2);
   l1.pushBack(3);
   l1.pushBack(4);
   l1.pushBack(5);
   l1.printList();
   l1.pop_back();
   l1.pop_front();
   l1.printList();
return 0;
} 

