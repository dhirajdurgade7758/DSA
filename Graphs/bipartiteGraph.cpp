#include<iostream>
#include<vector>
#include<list>
#include<queue>
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

    bool isBipartite(){
        queue<int> q;
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            list<int> neighbors = l[curr];
            for(int v: neighbors){
                if(color[v] == -1){
                    color[v] = !color[curr];
                    q.push(v);
                }
                else{
                    if(color[v] == color[curr]){
                        return false;
                    }
                }
            }
            
        }
        return true;
        
    }
};

int main()
{
    Graph g(4); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    // g.addEdge(0,3);

    cout<<g.isBipartite()<<endl;
    return 0;
}
