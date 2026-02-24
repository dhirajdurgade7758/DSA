class Solution {
public:
    
    int dijkastrasAlgo(int src, vector<vector<int>> &graph, int V){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V+1, INT_MAX);

        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for(int i=0; i<graph.size(); i++){
                if(u==graph[i][0]){
                    if (dist[graph[i][1]] > dist[u] + graph[i][2])
                    {
                        dist[graph[i][1]] = dist[u] + graph[i][2];
                        pq.push(make_pair(dist[graph[i][1]], graph[i][1]));
                    }
                }
            }
        }

        int maxTime=0;
        for(int i=1; i<dist.size(); i++){
            maxTime=max(maxTime, dist[i]);
        }
        return maxTime;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=dijkastrasAlgo(k,times, n);
        if(ans != INT_MAX){
            return ans;
        }
        return -1;
    }
};