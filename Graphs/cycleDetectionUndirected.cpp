#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u); // fix for undirected graph
    }


    bool cycleDetectHelper(int src, int parr, vector<bool> &vis){
        vis[src] = true;

        for(int v: l[src]){
            if(!vis[v]){
                if (cycleDetectHelper(v, src, vis))
                {
                    return true;
                }
            }
            else{
                if(v != parr){
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(){
        vector<bool> vis(V, false);
        return cycleDetectHelper(0, -1, vis);
    }
};

int main()
{
    Graph g(5); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    cout<<g.isCycle();
    return 0;
}
