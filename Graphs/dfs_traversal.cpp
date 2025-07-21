#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
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


    void dfs(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto v : l[u]) {
            if (!visited[v.first]) {
                dfs(v.first, visited);
            }
        }
    }

    void dfsNonRecursive(int start) {
    vector<bool> visited(V, false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            // Push neighbors to the stack
            for (auto it = l[node].rbegin(); it != l[node].rend(); ++it) {
                if (!visited[it->first]) {
                    s.push(it->first);
                }
            }
        }
    }
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
    vector<bool> visited(6, false);
    g.dfs(0, visited);

    return 0;
}
