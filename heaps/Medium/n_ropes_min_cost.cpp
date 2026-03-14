#include <queue>
#include <vector>
using namespace std;

int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // push all elements into min heap
    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    int ans = 0;

    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        int cost = min1 + min2;
        ans += cost;

        pq.push(cost);
    }

    return ans;
}