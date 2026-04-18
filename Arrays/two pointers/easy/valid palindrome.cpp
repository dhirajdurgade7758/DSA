#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            } else {
                return isPalindrome(s, left+1, right) || 
                       isPalindrome(s, left, right-1);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Valid palindrome (even length)
    string test1 = "abccba";
    cout << "Test 1 - Input: \"" << test1 << "\" -> Output: " << (sol.validPalindrome(test1) ? "true" : "false") << endl;
    
    // Test case 2: Valid palindrome (odd length)
    string test2 = "abcba";
    cout << "Test 2 - Input: \"" << test2 << "\" -> Output: " << (sol.validPalindrome(test2) ? "true" : "false") << endl;
    
    // Test case 3: Can be palindrome by removing one character
    string test3 = "abccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccba";
    cout << "Test 3 - Long string with one char difference -> Output: " << (sol.validPalindrome(test3) ? "true" : "false") << endl;
    
    // Test case 4: Cannot be palindrome by removing one character
    string test4 = "abc";
    cout << "Test 4 - Input: \"" << test4 << "\" -> Output: " << (sol.validPalindrome(test4) ? "true" : "false") << endl;
    
    // Test case 5: Single character (always valid)
    string test5 = "a";
    cout << "Test 5 - Input: \"" << test5 << "\" -> Output: " << (sol.validPalindrome(test5) ? "true" : "false") << endl;
    
    return 0;
}