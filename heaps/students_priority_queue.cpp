#include<iostream>
#include<queue>
using namespace std;

class student{
public:
    string name;
    int rank;
    
    student(string name, int rank){
        this->name = name;
        this->rank = rank;
    }
    
    bool operator < (const student &obj) const {
        return this->rank < obj.rank;
    }
};

int main()
{
    priority_queue<student> pq;
    pq.push(student("dhiraj", 2));
    pq.push(student("vishal", 6));
    pq.push(student("darshan", 4));
    pq.push(student("harshad", 1));
    pq.push(student("harsh", 5));
    
    while(!pq.empty()){
        cout<<"top: "<<pq.top().name<<endl;
        pq.pop();
    }

return 0;
}