#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int ROWS = matrix.size();
    int COLS = matrix[0].size();

    bool rowZero = false;

    // Step 1: mark rows & cols
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(matrix[r][c] == 0) {
                matrix[0][c] = 0;

                if(r > 0) {
                    matrix[r][0] = 0;
                } else {
                    rowZero = true;
                }
            }
        }
    }

    // Step 2: update inner matrix
    for(int r = 1; r < ROWS; r++) {
        for(int c = 1; c < COLS; c++) {
            if(matrix[0][c] == 0 || matrix[r][0] == 0) {
                matrix[r][c] = 0;
            }
        }
    }

    // Step 3: handle first column
    if(matrix[0][0] == 0) {
        for(int r = 0; r < ROWS; r++) {
            matrix[r][0] = 0;
        }
    }

    // Step 4: handle first row
    if(rowZero) {
        for(int c = 0; c < COLS; c++) {
            matrix[0][c] = 0;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "Updated matrix:\n";
    for(auto &row : matrix) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}