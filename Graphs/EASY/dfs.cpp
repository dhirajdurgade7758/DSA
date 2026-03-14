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
        dfshelper(0, visited);
        cout<<endl;
    }
};

int main()
{
    Graph g(5); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.dfs();
    return 0;
}
