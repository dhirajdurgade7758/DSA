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
    int cynum=-1;
    int count=0;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u); // fix for undirected graph
    }


    bool cycleDetectHelper(int src, int parr, vector<bool> &vis){
        vis[src] = true;

        for(int v: l[src]){
            if(!vis[v]){
                if (cycleDetectHelper(v, src, vis))
                {
                    if (v != cynum)
                    {
                        count++;
                    }
                    return true;
                }
            }
            else{
                if(v != parr){
                    cynum = v;
                    return true;
                }
            }
        }

        return false;
    }

    int isCycleOddEven(){
        vector<bool> vis(V, false);
        cout<<"count is :"<<count<<endl;
         if(cycleDetectHelper(0, -1, vis)){
            if (count % 2 == 0)
            {
                return 1;
            }
            else{
                return 0;
            }
            
         }
         return -1;
    }
};

int main()
{
    Graph g(5); // graph with 5 vertices (0 to 4)

    // Add edges
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    if (g.isCycleOddEven() == 1)
    {
        cout<<"cycle is even";
    }
    else if(g.isCycleOddEven() == 0){
        cout<<"cycle is odd";
    }
    else{
        cout<<"no cycle";
    }
    
    return 0;
}
