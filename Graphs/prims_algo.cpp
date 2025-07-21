#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<list>
using namespace std;


class Graph
{
    int V; // No. of vertices
    list<pair<int, int>> *l; // adjacency list
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int, int>>[V]; // create an array of vectors
    }
    // void addEdge(int u, int v, int w){
    //     adj[u].push_back(make_pair(v, w)); // add edge to the adjacency list
    //     adj[v].push_back(make_pair(u, w)); // add edge to the adjacency list (undirected graph)
    // }// function to add an edge to the graph
    void primsAlgo(int src){
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue to store the edges>

        vector<bool> mst(false);
        pq.push(make_pair(0, src)); // push the source vertex with weight 0 
        int totalCost = 0;

        while(!pq.size() > 0){
            int u = pq.top().second; // get the vertex with minimum weight
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                totalCost += wt;
                cout<<"Edge: " << u << " Weight: " << wt << endl; // print the edge and its weight
                list<pair<int,int>> neighbors = l[u];

                for(pair<int, int> n : neighbors){
                    int v = n.first;
                    int currwt = n.second;
                    pq.push(make_pair(currwt, v));
                }

            }
            cout<<"total cost:"<<totalCost<<endl;


        }

     }
};


int main()
{

return 0;
}