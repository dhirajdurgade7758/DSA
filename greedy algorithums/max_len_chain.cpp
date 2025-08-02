#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){
            return a[1]<b[1];
        });
        int chainlen =1;
        int curr_end = pairs[0][1];
        int n=pairs.size();

        for(int i=0; i<n; i++){
            if(pairs[i][0] > curr_end){
                chainlen++;
                curr_end = pairs[i][1];
            }
        }
        return chainlen;
    }
};

int main()
{
    vector<pair<int, int>> pairs(5, make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    cout<<findLongestChain(pairs)<<endl;
    
return 0;
}