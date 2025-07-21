#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    list<pair<int,int>> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt)); // fix for undirected graph
    }
    
};

int main()
{
    Graph g(6); // fix: increase to 6 vertices (0 to 5)
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 3, 10);
    g.addEdge(3, 4, 10);
    g.addEdge(4, 5, 10);
    g.addEdge(3, 5, 10);

    return 0;
}
