#include<iostream>
#include<queue>
using namespace std;

void interleaveQueue(queue<int>& q){
    queue<int> first;
    int n = q.size()/2;

    for (int i = 0; i < n; i++)
    {
        first.push(q.front());
        q.pop();
    }

    while (!first.empty())
    {
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);

    interleaveQueue(q);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

return 0;
}