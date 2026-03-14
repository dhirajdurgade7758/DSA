#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        // Min heap -> {time, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > minHeap;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        vector<pair<int,int>> directions = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while(!minHeap.empty()) {

            auto top = minHeap.top();
            minHeap.pop();

            int t = top[0];
            int r = top[1];
            int c = top[2];

            if(r == n-1 && c == n-1)
                return t;

            for(auto dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    minHeap.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    int result = sol.swimInWater(grid);

    cout << "Minimum time to reach bottom-right: " << result << endl;

    return 0;
}