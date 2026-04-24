#include<iostream>
#include<queue>
using namespace std;

class Stack{
    public:
    queue<int> q1,q2;

    void push(int data){
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        
    }

    void pop(){
        q1.pop();
    }

    int top(){
        if(q1.empty()){
            cout<<"stack is empty! "<<endl;
            return -1;
        }
        return q1.front();
    }

    bool empty(){
        return q1.empty();
    }
// };
// class MyStack {
// public:
//     queue<int> q1,q2;
//     MyStack() {
        
//     }
    
//     void push(int data) {
//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.push(data);
//         while (!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }
//     }
    
//     int pop() {
//         int front=q1.front();
//         q1.pop();
//         return front;
        
//     }
    
//     int top() {
//         if(q1.empty()){
//             cout<<"stack is empty! "<<endl;
//             return -1;
//         }

//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);

    while (!obj.empty())
    {
        cout<<obj.top()<<endl;
        obj.pop();
    }
return 0;
}