#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;   // adjacency list using vector

public:
    Graph(int V){
        this->V = V;
        adj.resize(V);          // create V empty vectors
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);    // undirected graph
    }

    bool cycleDetectHelper(int src, int parent, vector<bool> &vis){
        vis[src] = true;

        for(int neighbor : adj[src]){
            if(!vis[neighbor]){
                if(cycleDetectHelper(neighbor, src, vis)){
                    return true;
                }
            }
            else if(neighbor != parent){
                return true;
            }
        }

        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(cycleDetectHelper(i, -1, vis)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);

    cout << g.isCycle();   // 1 means cycle exists
    return 0;
}
