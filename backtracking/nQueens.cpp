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

bool isSafe(vector<vector<char>> board, int row, int col){
    int n=board.size();
    for(int i=0; i<n; i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    //vertical test
    for(int i=0;i<=row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

    //digonal left test 
    for(int i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    //digonal right test
    for(int i=row, j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    return true;
}


void nQueens(vector<vector<char>>& board, int row){
    int n=board.size();
    if(row == n){
        printboards(board);
            cout<<"-----------------"<<endl;
        return;
    }

    for(int i=0; i<n; i++){// collumns
    if(isSafe(board, row, i)){
        board[row][i] = 'Q';
        nQueens(board, row+1);
        board[row][i] = '.';
    }
     
    }

}



int main()
{
    vector<vector<char>> board;
    int n=4;
    for(int i=0; i<n; i++){
        vector<char> newrow;
        for(int j=0; j<n; j++){
          newrow.push_back('.');
        }
        board.push_back(newrow);
    }
    nQueens(board, 0);

return 0;
}