#include<iostream>
#include<vector>
using namespace std;

class heap{
    vector<int> h;
    
 public:
    void push(int data){
        h.push_back(data);
        
        int x=h.size()-1;
        int parr=(x-1)/2;
        
        while(parr>=0 && h[x] > h[parr]){
            swap(h[x], h[parr]);
            x=parr;
            parr=(x-1)/2;
        }
        cout<<"pushed: "<<data<<endl;
    }
    void pop(){
        
    }
    
    int top(){
        
        return h[0];
    }
    
    bool empty(){
        return h.size() == 0;
    }
    
};

int main()
{
    heap pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(7);
    pq.push(3);
    pq.push(11);
    cout<<pq.empty()<<endl;
    cout<<pq.top();

return 0;
}