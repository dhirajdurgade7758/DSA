#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int, int>> jobs){
    sort(jobs.begin(), jobs.end(), compare);
    
    int profit = jobs[0].second;
    int safeDeadline = 2;
    
    for(int i=1; i<jobs.size(); i++){
        if(jobs[i].first >= safeDeadline){
            profit+=jobs[i].second;
            safeDeadline++;
        }
    }
    
    cout<<"maxProfit from jobs is: "<<profit<<endl;
    return profit;
}

int main()
{
    vector<pair<int, int>> pairs(5, make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);
    
    maxProfit(pairs);
return 0;
}