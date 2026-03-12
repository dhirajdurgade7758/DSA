#include<iostream>
#include<vector>
using namespace std;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int srow = 0, scol = 0, erow = n-1, ecol = m-1;
        vector<int> result;
        result.resize(n*m);
         int indx = 0;
        while(srow<=erow && scol<=ecol){

            //Top
            for(int i=scol; i<=ecol; i++){
                result[indx++] = matrix[srow][i];
            }

            //right
            for(int i=srow+1; i<=erow; i++){
                result[indx++] = matrix[i][ecol];
            }

            //bottom
            for(int i=ecol-1; i>=scol; i--){
                if(srow == erow){
                    break;
                }
                result[indx++] = matrix[erow][i];
            }

            //left
            for(int i=erow-1; i>=srow+1; i--){
                if(scol == ecol){
                    break;
                }
                result[indx++] = matrix[i][scol];
            }

            srow++;
            scol++;
            erow--;
            ecol--;
        }
        return result;
    }

    int main(){
        vector<vector<int>> mt = {
             {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
        };

        vector<int> result = spiralOrder(mt);

        for(int i=0; i<result.size(); i++){
    cout << result[i] << " ";
}

        return 0;
    }
