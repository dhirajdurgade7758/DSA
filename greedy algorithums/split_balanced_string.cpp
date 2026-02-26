#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int temp = 0;
        
        for(int i=0; i<s.size(); i++){
            if(temp == 0){
                count++;
            }

            if(s[i]=='R'){
            temp++;
            }
            else{
                temp--;
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