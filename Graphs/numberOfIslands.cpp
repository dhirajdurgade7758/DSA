#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] != '1')
            return;

        grid[row][col] = '0';

        dfs(grid, row+1, col); // down
        dfs(grid, row-1, col); // up
        dfs(grid, row, col+1); // right
        dfs(grid, row, col-1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}
