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


    void primsAlgo(int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> mst(V, false); // fix: initialize with size V
        pq.push(make_pair(0, src));
        int totalCost = 0;

        while(!pq.empty()){ // fix: correct loop condition
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                totalCost += wt;
                cout << "Edge: " << u << " Weight: " << wt << endl;
                auto neighbors = l[u];
                for(auto n : neighbors){
                    int v = n.first;
                    int currwt = n.second;
                    if(!mst[v])
                        pq.push(make_pair(currwt, v));
                }
            }
        }

        cout << "Total cost: " << totalCost << endl;
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
    g.primsAlgo(0);

    return 0;
}
