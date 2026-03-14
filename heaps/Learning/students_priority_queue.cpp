#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
public:
    int Scount;
    int indx;

    Row(int c, int i){
        Scount = c;
        indx = i;
    }
    
    bool operator < (const Row &r )const {
        if(this->Scount == r.Scount){
            return this->indx > r.indx;
        }
        return this->Scount > r.Scount;
    }

};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> vec;
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
            vec.push_back(Row(soldiersCount, i));
        }
    priority_queue<Row> pq(vec.begin(), vec.end());
        
        vector<int> ans;
        while(k>0){
            ans.push_back(pq.top().indx);
            pq.pop();
            k--;
        }
        return ans;
}

int main(){
    vector<vector<int>> mat = {{1,1,0,0,0}, {1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};

    int k = 3;
    vector<int> ans = kWeakestRows(mat, k);
    for(int i=0; i<ans.size(); i++){
        cout<<"row: "<<ans[i]<<endl;
    }

    return 0;
}
