#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // DFS helper function to fill connected pixels
    void dfs(int row, int col, int n, int m, 
             vector<vector<bool>> &vis, vector<vector<int>> &image, 
             int oldColor, int newColor) {
        
        vis[row][col] = true;          // mark current cell visited
        image[row][col] = newColor;    // fill with new color

        // Move Up
        if (row - 1 >= 0 && image[row - 1][col] == oldColor && !vis[row - 1][col]) {
            dfs(row - 1, col, n, m, vis, image, oldColor, newColor);
        }

        // Move Down
        if (row + 1 < n && image[row + 1][col] == oldColor && !vis[row + 1][col]) {
            dfs(row + 1, col, n, m, vis, image, oldColor, newColor);
        }

        // Move Left
        if (col - 1 >= 0 && image[row][col - 1] == oldColor && !vis[row][col - 1]) {
            dfs(row, col - 1, n, m, vis, image, oldColor, newColor);
        }

        // Move Right
        if (col + 1 < m && image[row][col + 1] == oldColor && !vis[row][col + 1]) {
            dfs(row, col + 1, n, m, vis, image, oldColor, newColor);
        }
    }

    // Main function for flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // visited matrix
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // start DFS from given source pixel
        dfs(sr, sc, n, m, vis, image, image[sr][sc], newColor);

        return image;
    }
};

// ---------------- DRIVER CODE (to run in VS Code) ----------------
int main() {
    Solution sol;

    // Example input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    cout << "Original Image:" << endl;
    for (auto row : image) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }

    // Apply flood fill
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "\nAfter Flood Fill:" << endl;
    for (auto row : result) {
        for (auto val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
