#include<iostream>
#include<vector>
using namespace std;

void printboards(vector<vector<char>> board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<char>>& board, int row, int col) {
    int n = board.size();

    // Check all possible knight moves with boundary checks
    if (row + 2 < n && col - 1 >= 0 && board[row + 2][col - 1] == 'K') {
        return false;
    }
    if (row + 2 < n && col + 1 < n && board[row + 2][col + 1] == 'K') {
        return false;
    }
    if (row - 2 >= 0 && col + 1 < n && board[row - 2][col + 1] == 'K') {
        return false;
    }
    if (row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == 'K') {
        return false;
    }
    if (row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == 'K') {
        return false;
    }
    if (row + 1 < n && col - 2 >= 0 && board[row + 1][col - 2] == 'K') {
        return false;
    }
    if (row - 1 >= 0 && col + 2 < n && board[row - 1][col + 2] == 'K') {
        return false;
    }
    if (row + 1 < n && col + 2 < n && board[row + 1][col + 2] == 'K') {
        return false;
    }

    // No threats detected
    return true;
}


void nNights(vector<vector<char>>& board, int row){
    int n=board.size();
    if(row == n){
        printboards(board);
            cout<<"-----------------"<<endl;
        return;
    }

    for(int i=0; i<n; i++){// collumns
    if(isSafe(board, row, i)){
        board[row][i] = 'K';
        nNights(board, row+1);
        board[row][i] = '.';
    }
     
    }

}



int main()
{
    vector<vector<char>> board;
    int n=2;
    for(int i=0; i<n; i++){
        vector<char> newrow;
        for(int j=0; j<n; j++){
          newrow.push_back('.');
        }
        board.push_back(newrow);
    }
    nNights(board, 0);

return 0;
}