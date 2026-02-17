#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& vis,
             int prevHeight,
             int row,
             int col) {

        if (row < 0 || col < 0 || row >= n || col >= m ||
            vis[row][col] ||
            heights[row][col] < prevHeight) {
            return;
        }

        vis[row][col] = true;

        dfs(heights, vis, heights[row][col], row + 1, col);
        dfs(heights, vis, heights[row][col], row - 1, col);
        dfs(heights, vis, heights[row][col], row, col + 1);
        dfs(heights, vis, heights[row][col], row, col - 1);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        // Top & Bottom rows
        for (int col = 0; col < m; col++) {
            dfs(heights, pac, heights[0][col], 0, col);
            dfs(heights, atl, heights[n - 1][col], n - 1, col);
        }

        // Left & Right columns
        for (int row = 0; row < n; row++) {
            dfs(heights, pac, heights[row][0], row, 0);
            dfs(heights, atl, heights[row][m - 1], row, m - 1);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    Solution obj;
    vector<vector<int>> result = obj.pacificAtlantic(heights);

    cout << "Cells that can reach both oceans:\n";
    for (auto &cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]\n";
    }

    return 0;
}
