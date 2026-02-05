#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<mat.size(); i++){
            int soldiersCount=0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]==1){
                    soldiersCount++;
                }
                else{
                    break;
                }
            }
            pq.push(make_pair(soldiersCount, i));
        }
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
        
}

int main(){
    vector<vector<int>> mat = {{1,1,0,0,0}, {1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};

    int k = 3;

    return 0;
}
