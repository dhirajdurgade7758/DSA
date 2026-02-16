#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Edge{
    public:
        int u;
        int v;
        int wt;
        Edge(int u, int v, int wt){
            this->u = u;
            this->v = v;
            this->wt = wt;
        }
};

class Graph{
    int V;
    vector<Edge> edges;
    vector<int> parr;
    vector<int> rank;

    public:
        Graph(int V){
            this->V = V;
            for (int i=0; i<V; i++)
            {
                parr.push_back(i);
                rank.push_back(0);
            }
        }

        int find(int x){
            if(parr[x] == x){
                return x;
            }
            return parr[x] = find(parr[x]);
        }

        void unionByRank(int parrU, int parrV){
            if(rank[parrU] > rank[parrV]){
                parr[parrV] = parrU;
            }
            else{
                parr[parrU] = parrV;
            }
        }

        void addEdge(int u, int v, int wt){
            edges.push_back(Edge(u, v, wt));
        }

        void kruskals(){//O(Elog E)
            sort(edges.begin(), edges.end(), [](Edge& a, Edge& b){return a.wt < b.wt;});

            int minCost = 0;
            int edgeCount = 0;

            for(int i=0; i<edges.size() && edgeCount<=V-2; i++){ // becuse v-1 edges in MST and we are counting edge from 0
                Edge edge= edges[i];
                int parrU = find(edge.u);
                int parrV = find(edge.v);

                if(parrU != parrV){
                    unionByRank(parrU, parrV);
                    minCost+=edge.wt;
                    edgeCount++;
                }
            }
            cout<<"minimun cost is: "<< minCost<<endl;
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);
    g.kruskals();

return 0;
}