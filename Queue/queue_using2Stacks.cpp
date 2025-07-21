#include<iostream>
#include<stack>
using namespace std;

// approch 1 push O(n)
// class Queue{
//     public:
//     stack<int> s1, s2;

//     void push(int data){
//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(data);

//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     void pop(){
//         if (s1.empty())
//         {
//             cout<<"Queue is empty! "<<endl;
//             return;
//         }
//         s1.pop();
//     }

//     int front(){
//         if (s1.empty())
//         {
//             cout<<"Queue is empty! "<<endl;
//             return -1;
//         }
//         return s1.top();
//     }

//     bool empty(){
//         return s1.empty();
//     }
// };

class Queue{
    public:
    stack<int> s1, s2;

    void push(int data){
        s1.push(data);
    }

    void pop(){
        if (s1.empty())
        {
            cout<<"Queue is empty! "<<endl;
            return;
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front(){
        if (s1.empty())
        {
            cout<<"Queue is empty! "<<endl;
            return -1;
        }

        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int front = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return front;
    }

    bool empty(){
        return s1.empty();
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