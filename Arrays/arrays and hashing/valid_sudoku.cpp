#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> row(9);
        vector<vector<char>> col(9);
        vector<vector<vector<char>>> grid(3, vector<vector<char>>(3));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                char val = board[i][j];

                // Check row
                if (find(row[i].begin(), row[i].end(), val) != row[i].end())
                    return false;

                // Check column
                if (find(col[j].begin(), col[j].end(), val) != col[j].end())
                    return false;

                // Check 3x3 grid
                int r = i / 3;
                int c = j / 3;
                if (find(grid[r][c].begin(), grid[r][c].end(), val) != grid[r][c].end())
                    return false;

                // Insert values
                row[i].push_back(val);
                col[j].push_back(val);
                grid[r][c].push_back(val);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    cout << (obj.isValidSudoku(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    return 0;
}
