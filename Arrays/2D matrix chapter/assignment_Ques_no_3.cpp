// Question 3 : Write a program to Find Transpose of a Matrix. 
// What is Transpose? 
// Transpose of a matrix is the process of swapping the rows to columns. For a 2x3 
// matrix, 
// Matrix 
// a11 a12 a13 
// a21 a22 a23 
// Transposed Matrix 
// a11 a21 
// a12 a22 
// a13 a23 

#include <iostream>
using namespace std;

int main() {
    // Define matrix dimensions
    const int row = 2, column = 3;
    int matrix[row][column] = { {2, 3, 7}, {5, 6, 7} };

    // Transpose the matrix
    int transpose[column][row] = { {0} };

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

