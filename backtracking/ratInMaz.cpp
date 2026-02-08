#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& maze, int row, int col,
                string path, vector<string>& ans,
                vector<vector<bool>>& vis) {

        int n = maze.size();

        // boundary + blocked + visited check
        if (row < 0 || col < 0 || row >= n || col >= n ||
            maze[row][col] == 0 || vis[row][col]) {
            return;
        }

        // destination reached
        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[row][col] = true;

        // move in all 4 directions
        helper(maze, row + 1, col, path + "D", ans, vis); // Down
        helper(maze, row - 1, col, path + "U", ans, vis); // Up
        helper(maze, row, col + 1, path + "R", ans, vis); // Right
        helper(maze, row, col - 1, path + "L", ans, vis); // Left

        vis[row][col] = false; // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        if (maze[0][0] == 1)
            helper(maze, 0, 0, "", ans, vis);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    Solution obj;
    vector<string> result = obj.ratInMaze(maze);

    if (result.empty()) {
        cout << "-1";
    } else {
        for (string s : result) {
            cout << s << " ";
        }
    }

    return 0;
}


// optimized space complexity
void helper(vector<vector<int>> mat, int r, int c, vector<string>& ans, string path){
    int n = mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || mat[r][c] == -1){
        return;
    }

    if(r==n-1 && c==n-1){
        ans.push_back(path);
        return;
    }
    mat[r][c] = -1;
    helper(mat, r, c+1, ans, path+'R'); // Right move
    helper(mat, r+1, c, ans, path+'D'); // Down move
    helper(mat, r, c-1, ans, path+'L'); // left move
    helper(mat, r-1, c, ans, path+'U'); // Up move

    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n=mat.size();
        vector<string> ans; 
        helper(mat, 0, 0, ans,"");
        return ans;
    }
int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
return 0;
}