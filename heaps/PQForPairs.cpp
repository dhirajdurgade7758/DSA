#include<iostream>
#include<queue>
using namespace std;

struct compare
{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2){
        return p1.second > p2.second;
    }
};


int main()
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
    pq.push(make_pair("dhiraj", 2));
    pq.push(make_pair("vishal", 6));
    pq.push(make_pair("darshan", 4));
    pq.push(make_pair("harshad", 1));
    pq.push(make_pair("harsh", 5));
    
    while(!pq.empty()){
        cout<<"top: "<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }

return 0;
}