#include<iostream>
#include<vector>
using namespace std;


int mcm(vector<int> arr, int i, int j){
    if(i == j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        // set1
        int cost1 = mcm(arr, i, k);

        //set2
        int cost2 = mcm(arr, k+1, j);

        int currCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, currCost);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();
    cout<<"minimum cost to multiply matrix is: "<<mcm(arr,1, n-1);

return 0;
}