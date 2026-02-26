#include<iostream>
#include<vector>
#include<algorithm>
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
    Solution sol;
    // Using vector<vector<int>> to match the function signature
    vector<vector<int>> pairs = {{5,24}, {39,60}, {5,28}, {27,40}, {50,90}};
    
    cout << "Longest chain length: " << sol.findLongestChain(pairs) << endl;
    
    return 0;
}