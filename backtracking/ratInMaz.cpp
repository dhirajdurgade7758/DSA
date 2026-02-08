#include<iostream>
#include<string>
#include<vector>
using namespace std;

// void helper(vector<vector<int>> mat, int r, int c, vector<string>& ans, string path, vector<vector<bool>> vis){
//     int n = mat.size();
//     if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || vis[r][c] == true){
//         return;
//     }

//     if(r==n-1 && c==n-1){
//         ans.push_back(path);
//         return;
//     }
//     vis[r][c] = true;
//     helper(mat, r, c+1, ans, path+'R', vis); // Right move
//     helper(mat, r+1, c, ans, path+'D', vis); // Down move
//     helper(mat, r, c-1, ans, path+'L', vis); // left move
//     helper(mat, r-1, c, ans, path+'U', vis); // Up move

//     vis[r][c] = false;
// }

// vector<string> findPath(vector<vector<int>> &mat) {
//     int n=mat.size();
//         vector<string> ans;
//         vector<vector<bool>> vis(n, vector<bool>(n, false));
//         helper(mat, 0, 0, ans,"", vis);
//         return ans;
//     }
// int main()
// {
//     vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
//     vector<string> ans = findPath(mat);
//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<endl;
//     }
// return 0;
// }

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