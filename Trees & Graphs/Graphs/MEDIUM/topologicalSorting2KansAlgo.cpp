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

    void indigree(vector<int> &indeg){
        for (int i = 0; i < V; i++)
        {
            list<int> neighbors = l[i];
            for (int v: neighbors)
            {
                indeg[v]++;
            }
        }
    }

    void topSort2(){
        vector<int> indeg(V,0);
        indigree(indeg);

        //push all the vertex having indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        // loop for all the neighbors of the curr and reduce the indegree 
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> neighbors = l[curr];

            for(int v: neighbors){
                indeg[v]--; 
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
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
    g.topSort2();

    return 0;
}
