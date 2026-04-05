#include<iostream>
using namespace std;

int ways(int r, int c, int n, int m){
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    // right way call
    int v1 = ways(r, c+1, n, m);
    // down ways call
    int v2 = ways(r+1, c, n,m);

    return v1+v2;
}

int main()
{
    cout<<ways(0,0,3,7);

return 0;
}