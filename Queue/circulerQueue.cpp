#include<iostream>
using namespace std;

class Queue{
    int capacity;
    int currSize;
    int f, r;
    int* arr;

    public:
    Queue(int capacity){
        this->capacity = capacity;
        currSize = 0;
        f=0;
        r=-1;
        arr = new int[capacity];

    }

    void push(int data){
        if (currSize == capacity)
        {
            cout<<"queue is full! "<<endl;
            return;
        }
       r = (r+1)%capacity;
       arr[r] = data;
       currSize++;
    }

    void pop(){
        if (currSize==0)
        {
            cout<<"queue is empty! "<<endl;
            return;
        }
        
       f = (f+1)%capacity;
       currSize--;
    }

    int front(){
        if (empty())
        {
            cout<<"queue is empty! "<<endl;
            return -1;
        }
        
       return arr[f];
    }

    bool empty(){
        return currSize==0;
    }

};

int main()
{
    Queue obj(5);
    obj.push(10);
    obj.push(20);
    obj.pop();
    obj.pop();
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.push(60);
    obj.push(70);

    while (!obj.empty())
    {
        cout<<obj.front()<<endl;
        obj.pop();
    }
    


return 0;
}