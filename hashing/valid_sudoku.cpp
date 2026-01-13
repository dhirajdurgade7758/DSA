class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> row(9, vector<char>(9,'0'));
        vector<vector<char>> col(9, vector<char>(9,'0'));
        vector<vector<vector<char>>> grid(3, vector<vector<char>> (3,vector<char>(9)));

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    continue;
                }

                if(find(row[i].begin(), row[i].end(), board[i][j]) != row[i].end()){
                    return false;
                }
                if(find(col[j].begin(), col[j].end(), board[i][j]) != col[j].end()){
                    return false;
                }
                int r=i/3;
                int c=j/3;
                if(find(grid[r][c].begin(), grid[r][c].end(), board[i][j]) != grid[r][c].end()){
                    return false;
                }
                row[i].push_back(board[i][j]);
                col[j].push_back(board[i][j]);
                grid[r][c].push_back(board[i][j]);
            }
        }
        return true;
    }
};