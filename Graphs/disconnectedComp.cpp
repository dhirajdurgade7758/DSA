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


    void dfshelper(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto v : l[u]) {
            if (!visited[v]) {
                dfshelper(v, visited);
            }
        }
    }

    void dfs(){
        vector<bool> visited(6, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfshelper(i, visited);
                cout<<endl;
            }
            
        }
    }
};

int main()
{
    Graph g(5); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(1,6);
    g.addEdge(6,4);
    g.addEdge(4,3);
    g.addEdge(4,9);
    g.addEdge(3,8);
    g.addEdge(3,7);
    g.addEdge(2,5);
    g.addEdge(2,0);
    g.dfs();
    return 0;
}
