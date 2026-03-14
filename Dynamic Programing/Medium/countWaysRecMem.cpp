#include<iostream>
#include<vector>
using namespace std;

int countWayRec(int n, vector<int> &f){
    if(n==0 || n==1){
        return 1;
    }

    if(f[n] != -1){
        return f[n];
    }
    f[n] = countWayRec(n-1, f) + countWayRec(n-2, f);
    return f[n];
}


int main()
{
    int n=5;
    vector<int> f(n+1, -1);
    cout<<countWayRec(n, f)<<endl;

return 0;
}