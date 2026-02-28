#include<iostream>
#include<string>
using namespace std;

//bruteforce approach
// class Solution {
// public:

//     bool helper(string s, int indx, int count){
//         if(count<0){return false;}
//         if(indx==s.length()){return count==0;}
//         if(s[indx] == '('){
//             return helper(s, indx+1, count+1);
//         }
//         if(s[indx] == ')'){
//             return helper(s, indx+1, count-1);
//         }
//         return(helper(s,indx+1,count) ||
//             helper(s,indx+1, count+1) ||
//             helper(s,indx+1, count-1) );
//     }

//     bool checkValidString(string s) {
//         int indx=0;
//         int count=0;
//         return helper(s, indx, count);

//     }
// };


// Optimized solution using greedy approach with min/max balance counters
// Time: O(n), Space: O(1) - much better than brute force

class Solution {
public:
    bool checkValidString(string s) {
        // STEP 1: Track min and max possible open parentheses count at each position
        // min: count if all '*' are treated as ')'
        // max: count if all '*' are treated as '('
        int min=0;
        int max=0;

        // STEP 2: Traverse string and update balance counters
        for(int i=0; i<s.length(); i++){
            // Opening bracket increases both min and max
            if(s[i]=='('){
                min++;  // Minimum increases
                max++;  // Maximum increases
            }
            // Closing bracket decreases both min and max
            else if(s[i]==')'){
                min--;  // Minimum decreases
                max--;  // Maximum decreases
            }
            // Wildcard can be treated as either '(' or ')'
            else{
                min--;  // Minimum if treated as ')'
                max++;  // Maximum if treated as '('
            }
            // If min goes negative, set to 0 (no need to track below 0)
            if(min<0){
                min=0;
            }
            // If max goes negative, impossible to balance (too many closing brackets)
            if(max<0){
                return false;
            }
        }
        // Valid if we can end with exactly 0 open parentheses
        return min==0;
    }
};

int main() {
    Solution sol;
    string s1 = "(*)";
    cout << "Is '" << s1 << "' valid? " << (sol.checkValidString(s1) ? "Yes" : "No") << endl;
    
    string s2 = "(*))";
    cout << "Is '" << s2 << "' valid? " << (sol.checkValidString(s2) ? "Yes" : "No") << endl;
    return 0;
}