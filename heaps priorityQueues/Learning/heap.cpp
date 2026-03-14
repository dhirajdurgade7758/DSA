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
    
    void heapify(int indx){
        if(indx >= h.size()){
            return;
        }
        
        int l=2*indx+1;
        int r=2*indx+2;
        int maxindx=indx;
        
        if(l<h.size() && h[l]>h[maxindx]){
            maxindx=l;
        }
        
        if(r<h.size() && h[r]>h[maxindx]){
            maxindx=r;
        }
        
        swap(h[maxindx], h[indx]);
        
        if(maxindx!=indx){
            return heapify(maxindx);
        }
    }
    
    void pop(){
        //swap root and last
        swap(h[0], h[h.size()-1]);
        
        //delete this lastindex
        h.pop_back();
        
        //fix the heap
        heapify(0);
        
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
    
    while(!pq.empty()){
        cout<<"top: "<<pq.top()<<endl;
        pq.pop();
    }

return 0;
}