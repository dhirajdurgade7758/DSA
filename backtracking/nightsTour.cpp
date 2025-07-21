#include<iostream>
#include<vector>
using namespace std;

 bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expval){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!=expval){
            return false;
        }

        if(expval == (n*n) -1){
            return true;
        }
        // Eight possible moves for nights
        bool ans1 = isValid(grid, r-2, c+1, n, expval+1);
        bool ans2 = isValid(grid, r-1, c+2, n, expval+1);
        bool ans3 = isValid(grid, r+1, c+2, n, expval+1);
        bool ans4 = isValid(grid, r+2, c+1, n, expval+1);
        bool ans5 = isValid(grid, r+2, c-1, n, expval+1);
        bool ans6 = isValid(grid, r+1, c-2, n, expval+1);
        bool ans7 = isValid(grid, r-1, c-2, n, expval+1);
        bool ans8 = isValid(grid, r-2, c-1, n, expval+1);
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return isValid(grid, 0, 0, n, 0);
    }

int main()
{
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout<<checkValidGrid(grid);
return 0;
}