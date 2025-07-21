#include<iostream>
#include<deque>
using namespace std;

class Stack{
    public:
    deque<int> q;

    void push(int data){
        q.push_back(data);
    }

    void pop(){
        q.pop_back();
    }

    int top(){
        return q.back();
    }

    bool empty(){
        return q.empty();
    }
};

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