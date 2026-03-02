#include<iostream>
#include<vector>
#include <algorithm> // for sort
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main()
{
    // STEP 1: Create activity list with pairs (start, end time)
    vector<pair<int,int>> act(3, make_pair(0,0));
    act[0] = make_pair(0,9);
    act[1] = make_pair(1,2);
    act[2] = make_pair(2,4);
    
    // Display activities before sorting
    cout<<"befor sorting"<<endl;
    
    for(int i=0; i<act.size(); i++){
        cout<<"A"<<i<<" "<<act[i].first<<" , "<<act[i].second<<endl;
    }
    
    // STEP 2: Sort activities by end time (greedy - earliest deadline first)
    sort(act.begin(), act.end(), compare);
    cout<<"after sorting"<<endl;
    for(int i=0; i<act.size(); i++){
        cout<<"A"<<i<<" "<<act[i].first<<" , "<<act[i].second<<endl;
    }
return 0;
}