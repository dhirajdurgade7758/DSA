#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int V;               // number of vertices
    list<int> *l;        // adjacency list

public:
    // Constructor: initialize adjacency list for V vertices
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    // Add edge (undirected)
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u); 
    }

    // Recursive DFS helper to check path
    bool hasPathHelper(int u, int target, vector<bool> &visited) {
        if (u == target)   // base case: found target
            return true;

        visited[u] = true; // mark current node visited
        
        // explore neighbors
        for (auto v : l[u]) {
            if (!visited[v]) {
                if(hasPathHelper(v, target, visited)){
                    return true;   // path found
                }
            }
        }
        return false;  // no path from this branch
    }

    // Public function to check if there is path from 0 to target
    bool hasPath(int target){
        if(target >= V) {   // safety check
            cout << "Target vertex out of range!" << endl;
            return false;
        }
        vector<bool> visited(V, false);
        return hasPathHelper(0, target, visited);
    }
};

int main()
{
    Graph g(6); // graph with 6 vertices (0 to 5)

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Check if path exists from 0 to 5
    cout << (g.hasPath(5) ? "Path exists" : "No path") << endl;

    return 0;
}
