#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O'){
            return;
        }

        board[i][j] = 'T';

        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n == 0) return;
        m = board[0].size();

        // Left & Right Borders
        for(int row = 0; row < n; row++){
            if(board[row][0] == 'O')
                dfs(board, row, 0);

            if(board[row][m-1] == 'O')
                dfs(board, row, m-1);
        }

        // Top & Bottom Borders
        for(int col = 0; col < m; col++){
            if(board[0][col] == 'O')
                dfs(board, 0, col);

            if(board[n-1][col] == 'O')
                dfs(board, n-1, col);
        }

        // Convert remaining 'O' to 'X'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        // Convert 'T' back to 'O'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    Solution obj;
    obj.solve(board);

    cout << "Final Board:\n";
    for(auto &row : board){
        for(auto &cell : row){
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
