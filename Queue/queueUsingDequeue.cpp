#include<iostream>
#include<deque>
using namespace std;

class Queue{
    public:
    deque<int> q;

    void push(int data){
        q.push_back(data);
    }

    void pop(){
        q.pop_front();
    }

    int front(){
        return q.front();
    }

    bool empty(){
        return q.empty();
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