#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int st=0;
        int end=0;
        unordered_map<char,int> count;
        int res=0;
        int maxcount=0;
        while(end<s.size()){
            int windowlen=end-st+1;
            count[s[end]]++;

            maxcount=max(maxcount, count[s[end]]);

            while(windowlen-maxcount > k && st<=end){
                count[s[st]]--;
                st++;
                windowlen--;
            }
            
            res=max(res, windowlen);
            end++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Input: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "Output: " << sol.characterReplacement(s1, k1) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test case 2
    string s2 = "ABBB";
    int k2 = 2;
    cout << "Input: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "Output: " << sol.characterReplacement(s2, k2) << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test case 3
    string s3 = "ABABAB";
    int k3 = 2;
    cout << "Input: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "Output: " << sol.characterReplacement(s3, k3) << endl;
    cout << "Expected: 5" << endl;
    
    return 0;
}