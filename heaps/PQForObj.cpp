#include<iostream>
#include <queue>
using namespace std;

class student{
    public:
    int rank;
    int age;

    student(int r, int a){
        rank = r;
        age = a;
    }

    bool operator < (const student &s) const {
        return this->rank > s.rank;
    }
};

int main()
{
    priority_queue<student> pq;
    pq.push(student(3, 20));
    pq.push(student(1, 22));
    pq.push(student(2, 19));

    while(!pq.empty()){
        student s = pq.top();
        cout<<"rank: "<<s.rank<<" age: "<<s.age<<endl;
        pq.pop();
    }

return 0;
}