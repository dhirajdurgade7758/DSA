#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue(){
        head = nullptr;
        tail = nullptr;
    }

    void push(int data){
        Node* newnode = new Node(data);
        if (head==nullptr)
        {
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }        
    }

    void pop(){
        if(empty()){
            cout<<"queue is empty! "<<endl;
        }
        else{
        Node* temp = head;
        head = head->next;
        }
    }

    int front(){
        if(empty()){
            cout<<"queue is empty! "<<endl;
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head==nullptr;
    }

};

int main()
{
    Queue obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);

    while (!obj.empty())
    {
        cout<<obj.front()<<endl;
        obj.pop();
    }
    


return 0;
}