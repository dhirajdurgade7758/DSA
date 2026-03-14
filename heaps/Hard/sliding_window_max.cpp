#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void slidingWindowMax(vector<int> arr, int k){
    priority_queue<pair<int, int>> pq;
    // build first window
    for(int i=0; i<k; i++){
        pq.push(make_pair(arr[i],i));
    }
    cout<<"max: "<<pq.top().first<<endl;
    
    // check for ele is outside the window
    for(int i=k; i<arr.size(); i++){
        while(!pq.empty() && pq.top().second <= (i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout<<"max: "<<pq.top().first<<endl;
    }
}

int main()
{
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    slidingWindowMax(arr, 3);
    

return 0;
}