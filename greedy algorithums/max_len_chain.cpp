#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // STEP 1: Sort pairs by their end value (second element) - greedy sorting
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b){
            return a[1]<b[1];
        });
        int chainlen =1;  // Start with first pair
        int curr_end = pairs[0][1];  // Track end time of last selected pair
        int n=pairs.size();

        // STEP 2: Greedily select pairs that start after previous chain ends
        for(int i=0; i<n; i++){
            // If current pair starts after previous chain ends, extend the chain
            if(pairs[i][0] > curr_end){
                chainlen++;  // Increment chain length
                curr_end = pairs[i][1];  // Update end time of last selected pair
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