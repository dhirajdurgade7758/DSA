#include<iostream>
#include<string>
using namespace std;

// Count Palindromic Substrings using Expand Around Center approach
class Solution {
public:
    // Count all palindromic substrings in string s
    // Uses expand around center method: treat each position as palindrome center
    int countSubstrings(string s) {
        int n=s.length();
        int res = 0;

        // Try each position as potential palindrome center
        for(int i=0; i<n; i++){

            // Case 1: Odd length palindromes (single character center)
            // Start from center i and expand outwards
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;  // Found a palindrome
                l--;    // Expand left
                r++;    // Expand right
            }

            // Case 2: Even length palindromes (two character center)
            // Center is between positions i and i+1
            l=i; 
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;  // Found a palindrome
                l--;    // Expand left
                r++;    // Expand right
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    
    // Test case 1: Simple palindromes - \"a\", \"b\", \"c\", \"abc\" (if bab counted)
    string test1 = "abc";
    cout << "Test 1: \"" << test1 << "\" -> " << sol.countSubstrings(test1) << " palindromes (Expected: 3)" << endl;
    
    // Test case 2: Multiple palindromes
    string test2 = "abab";
    cout << "Test 2: \"" << test2 << "\" -> " << sol.countSubstrings(test2) << " palindromes (Expected: 6)" << endl;
    // Palindromes: \"a\", \"b\", \"a\", \"b\", \"aba\", \"bab\"
    
    // Test case 3: All same characters
    string test3 = "aaa";
    cout << "Test 3: \"" << test3 << "\" -> " << sol.countSubstrings(test3) << " palindromes (Expected: 6)" << endl;
    // Palindromes: \"a\", \"a\", \"a\", \"aa\", \"aa\", \"aaa\"
    
    // Test case 4: Single character
    string test4 = "a";
    cout << "Test 4: \"" << test4 << "\" -> " << sol.countSubstrings(test4) << " palindromes (Expected: 1)" << endl;
    
    // Test case 5: Complex case
    string test5 = "nitin";
    cout << "Test 5: \"" << test5 << "\" -> " << sol.countSubstrings(test5) << " palindromes (Expected: 7)" << endl;
    // Palindromes: \"n\", \"i\", \"t\", \"i\", \"n\", \"iti\", \"nitin\"

    return 0;
}