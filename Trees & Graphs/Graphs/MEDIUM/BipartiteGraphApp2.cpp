#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // returns:
    // -1 -> no cycle
    //  0 -> odd cycle
    //  1 -> even cycle
    int dfs(int node, int parent, vector<bool>& vis, vector<int>& depth) {
        vis[node] = true;

        for(int neighbor : adj[node]) {

            if(!vis[neighbor]) {
                depth[neighbor] = depth[node] + 1;

                int result = dfs(neighbor, node, vis, depth);
                if(result != -1)
                    return result;
            }
            else if(neighbor != parent) {
                int cycleLength = depth[node] - depth[neighbor] + 1;

                if(cycleLength % 2 == 0)
                    return 1;   // even cycle
                else
                    return 0;   // odd cycle
            }
        }

        return -1;
    }

    int isCycleOddEven(){
        vector<bool> vis(V, false);
        vector<int> depth(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                int result = dfs(i, -1, vis, depth);
                if(result != -1)
                    return result;
            }
        }

        return -1;  // no cycle
    }
};

int main() {
    Graph g(5);

    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    int ans = g.isCycleOddEven();

    if(ans == 1)
        cout << "Cycle is even";
    else if(ans == 0)
        cout << "Cycle is odd";
    else
        cout << "No cycle";

    return 0;
}
