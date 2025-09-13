#include<iostream>
#include<vector>
#include<list>
using namespace std;

// Graph representation using adjacency list
class Graph
{
    int V;            // number of vertices
    list<int> *l;     // adjacency list (array of linked lists)

public:
    // Constructor: allocate memory for adjacency list
    Graph(int V){
        this->V = V;
        l = new list<int>[V];  // creates an array of lists
    }

    // Add an edge between u and v (undirected graph)
    void addEdge(int u, int v){
        l[u].push_back(v);  // add v to u’s list
        l[v].push_back(u);  // add u to v’s list (undirected)
    }

    // Print adjacency list representation of the graph
    void print(){
        for (int i = 0; i < V; i++)
        {   
            cout << "neighbors for " << i << " : ";
            
            // iterate through adjacency list of vertex i
            list<int> neighbors = l[i];
            for(int vertex: neighbors){
                cout << vertex << " ";  // print all neighbors of i
            }
            cout << endl;
        }
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

    // Print adjacency list
    g.print();

    return 0;
}
