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


    void topologicalSortHelper(int u, vector<bool> &visited, stack<int> &s) {
        visited[u] = true;

        for (auto v : l[u]) {
            if (!visited[v]) {
                topologicalSortHelper(v, visited, s);
            }
        }

        s.push(u);
    }

    void topologicalSort(){
        vector<bool> visited(6, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if(!visited[i]){
               topologicalSortHelper(i, visited, s); 
            }
        }

        cout<<"toplogical sorting: "<<endl;
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        
        cout<<endl;
    }
};

int main()
{
    Graph g(6, false); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.topologicalSort();
    return 0;
}
