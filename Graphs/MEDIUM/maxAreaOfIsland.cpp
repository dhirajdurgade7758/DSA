#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<int>>& grid, int row, int col, int& area){
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0)
            return;

        grid[row][col] = 0;   // mark visited
        area++;

        dfs(grid, row+1, col, area); // down
        dfs(grid, row-1, col, area); // up
        dfs(grid, row, col+1, area); // right
        dfs(grid, row, col-1, area); // left
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,1,1},
        {0,0,1,0,1,1,1,0},
        {0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,0,0}
    };

    cout << "Maximum Area of Island: " << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}
