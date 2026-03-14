#include<iostream>
#include<string>
using namespace std;

int ways(int r, int c, int n, int m, string ans){
    if(r==n-1 && c==m-1){
        cout<<ans<<"\n";
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    // right way call
    int v1 = ways(r, c+1, n, m, ans+'R');
    // down ways call
    int v2 = ways(r+1, c, n,m, ans+'D');

    return v1+v2;
}

int main()
{
    cout<<ways(0,0,3,7,"");

return 0;
}