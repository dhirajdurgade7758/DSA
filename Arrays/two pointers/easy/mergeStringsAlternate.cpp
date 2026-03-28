#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string ans="";
        while(i<word1.size() && j<word2.size()){
            ans+=word1[i];
            ans+=word2[j];
            i++;j++;
        }
        if(i<word1.size()){
            ans+=word1.substr(i, word1.size()-i);
        }

        if(j<word2.size()){
            ans+=word2.substr(j, word2.size()-j);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: "abc", "pqr"
    string result1 = sol.mergeAlternately("abc", "pqr");
    cout << "Test 1: \"abc\" + \"pqr\" = \"" << result1 << "\"" << endl;
    
    // Test case 2: "ab", "pqrs"
    string result2 = sol.mergeAlternately("ab", "pqrs");
    cout << "Test 2: \"ab\" + \"pqrs\" = \"" << result2 << "\"" << endl;
    
    // Test case 3: "abcd", "pq"
    string result3 = sol.mergeAlternately("abcd", "pq");
    cout << "Test 3: \"abcd\" + \"pq\" = \"" << result3 << "\"" << endl;
    
    // Test case 4: "a", "bcdefghijklmnopqrstuvwxyz"
    string result4 = sol.mergeAlternately("a", "bcdefghijklmnopqrstuvwxyz");
    cout << "Test 4: \"a\" + \"bcdefghijklmnopqrstuvwxyz\" = \"" << result4 << "\"" << endl;
    
    return 0;
}