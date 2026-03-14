#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        // Get grid dimensions
        int n = grid.size();
        int m = grid[0].size();

        // This will store the maximum time required
        int ans = 0;

        // Queue will store:
        // ((row, col), time)
        queue<pair<pair<int,int>, int>> q;

        // -----------------------------
        // STEP 1: Push all rotten oranges (multi-source BFS)
        // -----------------------------
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                // If orange is rotten
                if(grid[i][j] == 2){

                    // Push into queue with time = 0
                    q.push({{i,j}, 0});

                    // Mark visited (convert to 0 to avoid revisiting)
                    grid[i][j] = 0;
                }
            }
        }

        // -----------------------------
        // STEP 2: BFS traversal
        // -----------------------------
        while(!q.empty()){

            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Update maximum time
            ans = max(ans, t);

            // ---- Check all 4 directions ----

            // Down
            if(i + 1 < n && grid[i+1][j] == 1){
                q.push({{i+1, j}, t+1});
                grid[i+1][j] = 0;  // mark visited
            }

            // Up
            if(i - 1 >= 0 && grid[i-1][j] == 1){
                q.push({{i-1, j}, t+1});
                grid[i-1][j] = 0;
            }

            // Right
            if(j + 1 < m && grid[i][j+1] == 1){
                q.push({{i, j+1}, t+1});
                grid[i][j+1] = 0;
            }

            // Left
            if(j - 1 >= 0 && grid[i][j-1] == 1){
                q.push({{i, j-1}, t+1});
                grid[i][j-1] = 0;
            }
        }

        // -----------------------------
        // STEP 3: Check if any fresh orange remains
        // -----------------------------
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1){
                    return -1;  // Impossible to rot all
                }
            }
        }

        return ans;
    }
};


// -----------------------------
// MAIN FUNCTION (For VS Code)
// -----------------------------
int main() {

    Solution obj;

    // Example grid
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = obj.orangesRotting(grid);

    cout << "Minimum Time Required: " << result << endl;

    return 0;
}
