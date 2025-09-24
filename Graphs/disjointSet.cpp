#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
        vector<int> parr;
        vector<int> rank;
        DisjointSet(int n){
            for (int i = 0; i < n; i++)
            {
                parr.push_back(i);
                rank.push_back(0);
            }
            
        }

        int find(int x){
            if(parr[x] == x){
                return x;
            }
            return parr[x] = find(parr[x]); //path compressions
        }

        void unionByRank(int a, int b){
            int prra = find(a);
            int prrb = find(b);

            if (rank[prra] == rank[prrb])
            {
                parr[prrb] = prra;
                rank[prra]++;
            }
            else if(rank[prra] > rank[prrb]){
                parr[prrb] = prra;
            }
            else{
                parr[prra] = prrb;
            }
        }

        void getInfo(){
            for (int i = 0; i < parr.size(); i++)
            {
                cout<<i<<" : "<<parr[i]<<" , "<<rank[i]<<endl;
            }
        }
};

int main()
{
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout<<dj.find(2)<<endl;
    dj.unionByRank(0,4);
    cout<<dj.find(4)<<endl;
    cout<<dj.find(3)<<endl;
    dj.getInfo();

return 0;
}