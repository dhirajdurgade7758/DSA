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
    bool isUndir;

public:
    Graph(int V, bool isUndir=true){
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if (isUndir)
        {
            l[v].push_back(u);
        }
    }

    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for(int v: neighbors){
            if(!vis[v]){
                if(dirCycleHelper(v, vis, recPath)){
                    return true;
                }
            }
            else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);

        for (int i = 0; i < V; i++)
        {
            if(!vis[i]){
                if(dirCycleHelper(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Graph g(5, false); // graph with 5 vertices (0 to 4)
    // Add edges
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    cout<<g.isCycleDir();
    return 0;
}
