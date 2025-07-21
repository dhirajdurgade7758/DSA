#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(20);
    dq.push_front(10);
    dq.push_back(30);
    dq.push_back(40);
    dq.pop_back();
    dq.pop_front();
    cout<<dq.front()<<endl;
    cout<<dq.back();
    

return 0;
}