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


    void allPathsHelper(int src, int dest, vector<bool> &visited, string &path) {
        if (src == dest)
        {
            cout<<path<<dest<<endl;
            return;
        }
        
        visited[src] = true;
        path += to_string(src);

        for (int v : l[src]) {
            if (!visited[v]) {
                allPathsHelper(v, dest, visited, path);
            }
        }

        path = path.substr(0, path.size()-1);
        visited[src] = false;
    }

    void allPaths(int dest){
        vector<bool> visited(6, false);
        string path = "";
        allPathsHelper(0, dest, visited, path);
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
    

    g.allPaths(4);
    return 0;
}
