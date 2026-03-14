#include<iostream>
#include<vector>
using namespace std;

int fibDP(int n, vector<int> &f){
    if(n==0 || n==1){
        return n;
    }

    if(f[n] != -1){
        return f[n];
    }

    return (fibDP(n-1, f) + fibDP(n-2, f));
}


int main()
{
    int n=6;
    vector<int> f(n+1, -1);
    cout<<fibDP(n, f)<<endl;

return 0;
}