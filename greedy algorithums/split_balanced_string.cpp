#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        // STEP 1: Track balance between 'R' and 'L' characters
        int count = 0;  // Count of balanced substrings found
        int temp = 0;   // Balance counter (R=+1, L=-1)
        
        // STEP 2: Traverse string and find each balanced substring
        for(int i=0; i<s.size(); i++){
            // When balance reaches 0, we found a balanced substring
            if(temp == 0){
                count++;  // Found and counted a balanced substring
            }

            // Update balance: R increases, L decreases
            if(s[i]=='R'){
                temp++;   // 'R' increases balance
            }
            else{
                temp--;   // 'L' decreases balance
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s = "RLRRLLRLRL";
    cout << "Number of balanced substrings in '" << s << "': " << sol.balancedStringSplit(s) << endl;
    
    string s2 = "RLLLLRRRLR";
    cout << "Number of balanced substrings in '" << s2 << "': " << sol.balancedStringSplit(s2) << endl;
    return 0;
}