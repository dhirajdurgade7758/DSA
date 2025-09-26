#include<iostream>
#include<vector>
using namespace std;

int knapSackRec(vector<int> val, vector<int> wt, int n, int w){
    if(n==0 || w==0){
        return 0;
    }
    int currval = val[n-1];
    int currwt = wt[n-1];

    if(currwt <= w){
        //incude
        int ans1 = knapSackRec(val, wt, n-1, w-currwt) + currval;

        //not include
        int ans2 = knapSackRec(val, wt, n-1, w);
        return(max(ans1, ans2));
    }
    else{
        return knapSackRec(val, wt, n-1, w);
    }
}

int main()
{
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;
    cout<<knapSackRec(val, wt, n,w);

return 0;
}