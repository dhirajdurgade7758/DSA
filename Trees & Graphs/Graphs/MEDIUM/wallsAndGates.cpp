#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<int,int>> q;

    // push all gates
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0){
                q.push({i,j});
            }
        }
    }

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && a[nx][ny] == INT_MAX){
                a[nx][ny] = a[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return a;
}