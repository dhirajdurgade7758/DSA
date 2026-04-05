// class Solution {
// public:

//     bool helper(vector<vector<char>>& board, string word,int& i, int row, int col){
//         int n=board.size();
//         int m=board[0].size();
//         if(row >= n || col >= m || row < 0 || col < 0){
//             return false;
//         }
//         if(i>=word.length()){
//             return true;
//         }
//         if(board[row][col] == word[i]){
//             i++;

//         }
//         else{
//             i=0;
//         }
//         char temp = board[row][col];
//         board[row][col] = '#';   // mark visited
//         bool up = helper(board, word, i,  row-1, col);
//         bool down = helper(board, word, i,  row+1, col);
//         bool right = helper(board, word, i, row, col+1);
//         bool left = helper(board, word, i, row, col-1);
//         board[row][col] = temp;  // backtrack
//         if(up || down || right || left){
//             return true;
//         }
//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int indx=0;
//         return helper(board, word, indx, 0, 0);
//     }
// };
//my approch was wrong

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<vector<char>>& board, const string& word,
                int idx, int row, int col) {

        int n = board.size();
        int m = board[0].size();

        // boundary check
        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;

        // character mismatch
        if (board[row][col] != word[idx])
            return false;

        // word fully matched
        if (idx == word.length() - 1)
            return true;

        char temp = board[row][col];
        board[row][col] = '#';  // mark visited

        bool found =
            helper(board, word, idx + 1, row - 1, col) ||
            helper(board, word, idx + 1, row + 1, col) ||
            helper(board, word, idx + 1, row, col - 1) ||
            helper(board, word, idx + 1, row, col + 1);

        board[row][col] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "ABCCED: " << sol.exist(board, word1) << endl; // 1 (true)
    cout << "SEE: "    << sol.exist(board, word2) << endl; // 1 (true)
    cout << "ABCB: "   << sol.exist(board, word3) << endl; // 0 (false)

    return 0;
}
