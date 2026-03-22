#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    vector<int> result;
    result.resize(n * m);
    int indx = 0;

    while(srow <= erow && scol <= ecol) {

        // Top
        for(int i = scol; i <= ecol; i++) {
            result[indx++] = matrix[srow][i];
        }

        // Right
        for(int i = srow + 1; i <= erow; i++) {
            result[indx++] = matrix[i][ecol];
        }

        // Bottom
        for(int i = ecol - 1; i >= scol; i--) {
            if(srow == erow) break;
            result[indx++] = matrix[erow][i];
        }

        // Left
        for(int i = erow - 1; i >= srow + 1; i--) {
            if(scol == ecol) break;
            result[indx++] = matrix[i][scol];
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }

    return result;
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

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}