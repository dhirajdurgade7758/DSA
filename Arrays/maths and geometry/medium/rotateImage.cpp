#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int l = 0;
    int r = matrix.size() - 1;

    while(l < r) {
        for(int i = 0; i < (r - l); i++) {
            int top = l;
            int bottom = r;

            // save top-left
            int topLeft = matrix[top][l + i];

            // move bottom-left → top-left
            matrix[top][l + i] = matrix[bottom - i][l];

            // move bottom-right → bottom-left
            matrix[bottom - i][l] = matrix[bottom][r - i];

            // move top-right → bottom-right
            matrix[bottom][r - i] = matrix[top + i][r];

            // move saved top-left → top-right
            matrix[top + i][r] = topLeft;
        }
        r--;
        l++;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "Rotated matrix:\n";
    for(auto &row : matrix) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}