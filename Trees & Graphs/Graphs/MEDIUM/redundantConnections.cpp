#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> parr;
    vector<int> rankv;

    void DisjointSet(int n){
        parr.resize(n);
        rankv.resize(n);

        for (int i = 0; i < n; i++)
        {
            parr[i] = i;
            rankv[i] = 0;
        }
    }

    int find(int x){
        if(parr[x] == x){
            return x;
        }
        return parr[x] = find(parr[x]); // path compression
    }

    bool unionByRank(int a, int b){
        int prra = find(a);
        int prrb = find(b);

        if(prra == prrb){
            return false;  // cycle detected
        }
        
        if (rankv[prra] == rankv[prrb])
        {
            parr[prrb] = prra;
            rankv[prra]++;
        }
        else if(rankv[prra] > rankv[prrb]){
            parr[prrb] = prra;
        }
        else{
            parr[prra] = prrb;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
       DisjointSet(n+1);   // nodes are 1-indexed

       for(auto edge : edges){
         if(!unionByRank(edge[0], edge[1])){
            return edge;   // redundant edge
         }
       }
       return {};
    }
};

int main() {

    Solution sol;

    // Example test case
    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {2,3}
    };

    vector<int> result = sol.findRedundantConnection(edges);

    cout << "Redundant Edge: ";
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}
