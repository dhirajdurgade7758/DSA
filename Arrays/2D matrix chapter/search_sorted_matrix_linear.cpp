#include<iostream>
#include<vector>

using namespace std;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();

        //O(n) time complexity

        // for(int i=0; i<n; i++ ){
        //     for(int j=0; j<n; j++){
        //         if(target == matrix[i][j]){
        //             return true;
        //         }
        //     }
        // }

        //O(log n) time complexity

        for(int i=0; i<n; i++ ){
            int mid = -1, low=0, high=m-1;
            while(low<=high){
                mid = (low+high)/2;
                if(mid == target){
                    return true;
                }
                else if(mid<target){
                    low = mid+1;
                }

                else if(mid>target){
                    high = mid-1;
                }

            }
        }

        return false;

    }

int main(){

}