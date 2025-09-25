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

    return countWayRec(n-1, f) + countWayRec(n-2, f);
}


int main()
{
    int n=6;
    vector<int> f(n+1, -1);
    cout<<countWayRec(n, f)<<endl;

return 0;
}