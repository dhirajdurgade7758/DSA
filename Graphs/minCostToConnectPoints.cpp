class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        //(wt,u)
        int src = 0;
        vector<bool> mst(V, false);
        pq.push(make_pair(0, src));;
        int minCost=0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(!mst[u]){
                minCost += cost;
                mst[u] = true;

                for(int v=0; v<V; v++){
                    if(u != v){
                        int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                        pq.push(make_pair(wt, v));
                    }
                }
            }
        }
        return minCost;
    }
};