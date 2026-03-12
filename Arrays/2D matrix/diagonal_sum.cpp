#include<iostream>
#include<vector>

using namespace std;

 int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        //O(n^2) time complexity
        //      for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == j){
        //             sum += mat[i][j]; // primary diagonal
        //         }
        //         else if(j == n-i-1){
        //             sum += mat[i][j]; // secondary diagonal
        //         }
        //     }
        // }


        //O(n) time complexity
        // for(int i=0; i<n; i++){
        // sum += mat[i][i];           // primary diagonal
        // if(i != n-i-1){             // avoid double counting middle element
        //     sum += mat[i][n-i-1];   // secondary diagonal
        // }
        // }

        return sum;
    }

int main(){

    vector<vector<int>> mt = {
         {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout<<"Digonal sum of the 2D matrix is "<<diagonalSum(mt);

    return 0;
}