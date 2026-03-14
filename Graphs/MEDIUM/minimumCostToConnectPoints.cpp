#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();  

        // Min-Heap → stores {cost, node}
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        int src = 0;  // start from any point (here, index 0)
        vector<bool> mst(V, false);  // visited / MST set
        pq.push({0, src});  // {0 cost, source}

        int minCost = 0;  // total cost of MST

        // Prim's Algorithm
        while (!pq.empty()) {
            int cost = pq.top().first;   // current edge weight
            int u = pq.top().second;     // current node
            pq.pop();

            // If node already included in MST, skip
            if (mst[u]) continue;

            // Add edge cost to MST total
            minCost += cost;
            mst[u] = true;

            // Explore all neighbors (all other points)
            for (int v = 0; v < V; v++) {
                if (!mst[v]) {  
                    // Manhattan distance as weight
                    int wt = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({wt, v});
                }
            }
        }

        return minCost;
    }
};

// ---------------- MAIN DRIVER ----------------
int main() {
    Solution sol;

    vector<vector<int>> points = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << "Minimum cost to connect all points: " << sol.minCostConnectPoints(points) << endl;

    return 0;
}
