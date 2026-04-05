#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

// Graph representation using adjacency list with weights
class Graph
{
    int V;                         // number of vertices
    list<pair<int,int>> *l;        // adjacency list: each element stores (neighbor, weight)

public:
    // Constructor: allocate adjacency list for V vertices
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V];  
    }

    // Add an edge between u and v with given weight (undirected)
    void addEdge(int u, int v, int wt){
        l[u].push_back(make_pair(v, wt));   // add edge u -> v with weight
        l[v].push_back(make_pair(u, wt));   // add edge v -> u with weight (undirected)
    }

    // Print adjacency list with weights
    void print(){
        for (int i = 0; i < V; i++)
        {   
            cout << "neighbors for " << i << " : ";

            // iterate over all neighbors of vertex i
            list<pair<int, int>> neighbors = l[i];
            for(pair<int, int> v: neighbors){
                // print neighbor vertex and weight
                cout << "(" << v.first << "," << v.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);

    // Add weighted edges
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 10);
    g.addEdge(2, 3, 10);
    g.addEdge(3, 4, 10);
    g.addEdge(4, 5, 10);
    g.addEdge(3, 5, 10);

    // Print adjacency list representation
    g.print();

    return 0;
}
