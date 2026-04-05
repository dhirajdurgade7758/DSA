#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dijkastrasAlgo(int src, vector<vector<int>> &graph, int V){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V+1, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for(int i = 0; i < graph.size(); i++){
                if(u == graph[i][0]){
                    int v = graph[i][1];
                    int wt = graph[i][2];

                    if (dist[v] > dist[u] + wt)
                    {
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == INT_MAX) return INT_MAX; // unreachable node
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = dijkastrasAlgo(k, times, n);
        if(ans != INT_MAX){
            return ans;
        }
        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;  // number of nodes
    int k = 2;  // source node

    int result = sol.networkDelayTime(times, n, k);

    cout << "Network Delay Time: " << result << endl;

    return 0;
}