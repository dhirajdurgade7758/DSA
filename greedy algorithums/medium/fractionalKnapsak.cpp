#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first > p2.first;
}

int fractionalKnapsack(vector<int> val, vector<int> wt, int w){
    int n = val.size();
    int ans = 0;
    // Create pairs of (value-to-weight ratio, index) for sorting
    vector<pair<double, int>> ratio(n, make_pair(0.0,0));
    
    // STEP 1: Calculate value-to-weight ratio for each item
    for(int i= 0; i<n; i++){
        double r = val[i]/(double)wt[i];
        ratio[i] = make_pair(r,i);
    }
    
    // STEP 2: Sort items by value-to-weight ratio in descending order (greedy approach)
    sort(ratio.begin(), ratio.end(), compare);
    
    // STEP 3: Greedily select items with highest ratio until knapsack is full
    for(int i=0; i<n; i++){

        int indx = ratio[i].second;
        // If item fits completely, take whole item
        if(wt[indx] <= w){
            ans += val[indx];
            w-=wt[indx];
        }
        // If item doesn't fit completely, take fractional part of item
        else{
            ans += (ratio[i].first * w);
            w = 0;
            break;
        }
    }
    return ans;
}

int main() 
{
    vector<int> val = {60, 100,120};
    vector<int> wt = {10, 20, 30};
    int w = 50;
    cout<<fractionalKnapsack(val, wt, w);
    

return 0;
}