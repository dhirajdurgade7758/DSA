#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int maxChainLength(vector<pair<int,int>> pairs){
    sort(pairs.begin(), pairs.end(), compare);
    
    int chainlen = 1;
    int currEnd = pairs[0].second;
    
    for(int i=0; i<pairs.size(); i++){
        if(pairs[i].first > currEnd){
            chainlen++;
            currEnd = pairs[i].second;
        }
    }
    
    return chainlen;
}

int main()
{
    vector<pair<int, int>> pairs(5, make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    cout<<maxChainLength(pairs)<<endl;
    
return 0;
}