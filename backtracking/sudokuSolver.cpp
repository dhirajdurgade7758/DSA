#include<iostream>
using namespace std;

void printSudoku(int sudoku[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int sudoku[9][9], int row, int col, int digit){
    //vertical check
    for(int i=0;i<9; i++){
        if(sudoku[i][col] == digit){
            return false;
        }
    }

    // horizontal check
    for(int i=0; i<9; i++){
        if(sudoku[row][i] == digit){
            return false;
        }
    }

    // grid check
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i=startRow; i<(startRow+3); i++){
        for(int j=startCol; j<(startCol+3); j++){
            if(sudoku[i][j] == digit){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col){
    if(row == 9){ //base case 
        //sudoku solved
        printSudoku(sudoku);
        return true;
    }

    int nextrow = row;
    int nextcol = col+1;

    if(col+1 == 9){
        nextrow = row +1;
        nextcol = 0;
    }
    if(sudoku[row][col] != 0){
        return sudokuSolver(sudoku, nextrow, nextcol);
    }

    for(int i=1;i<=9; i++){
            if(isSafe(sudoku, row, col, i)){
                sudoku[row][col] = i;
                if(sudokuSolver(sudoku, nextrow, nextcol)){
                    return true;
                }
                else{
                    sudoku[row][col] = 0;
                }
            }
        }

    return false;
}

int main()
{
     int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    sudokuSolver(sudoku, 0,0);

return 0;
}