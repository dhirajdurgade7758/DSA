#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void queueReverse(queue<int>& q){
    stack<int> temp;
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }

    while (!temp.empty())
    {
        q.push(temp.top());
        temp.pop();
    }
    
    
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    queueReverse(q);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

return 0;
}