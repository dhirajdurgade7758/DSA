#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Decode Ways: Count the number of ways to decode a string of digits
// '1' -> 'A', '2' -> 'B', ..., '26' -> 'Z'
// Single digit: '1'-'9' (excluding '0')
// Two digits: '10'-'26' (characters won't decode values > 26)
int numDecodings(string s) {
    int n = s.length();
    // dp[i] = number of ways to decode string from position i to end
    vector<int> dp(n + 1, 0);

    // Base case: empty string has 1 way to decode (nothing)
    dp[n] = 1;

    // Fill dp table backwards from end of string
    for(int i = n - 1; i >= 0; i--) {
        // If current digit is '0', can't decode it as a single digit
        if(s[i] == '0') {
            dp[i] = 0;
        } else {
            // Current digit is valid ('1'-'9'), can decode as single digit
            dp[i] = dp[i + 1];

            // Check if we can decode current and next digit as 2-digit number
            // Valid range: '10'-'26'
            if(i + 1 < n &&
               (s[i] == '1' ||  // '1X' where X is any digit (10-19)
               (s[i] == '2' && s[i + 1] <= '6'))) {  // '2X' where X is 0-6 (20-26)
                // Can decode as 2-digit, add ways from position i+2
                dp[i] += dp[i + 2];
            }
        }
    }

    // Return number of ways to decode from start of string
    return dp[0];
}

int main() {
    // Test case 1: Simple single digit
    string test1 = "12";
    cout << "Test 1: \"" << test1 << "\" -> " << numDecodings(test1) << " ways (Expected: 2)" << endl;
    // Decodings: \"1,2\" (AB) or \"12\" (L)
    
    // Test case 2: Contains zeros
    string test2 = "226";
    cout << "Test 2: \"" << test2 << "\" -> " << numDecodings(test2) << " ways (Expected: 3)" << endl;
    // Decodings: \"2,2,6\" (BBF), \"22,6\" (VF), \"2,26\" (BZ)
    
    // Test case 3: String with zero (invalid case)
    string test3 = "06";
    cout << "Test 3: \"" << test3 << "\" -> " << numDecodings(test3) << " ways (Expected: 0)" << endl;
    // Can't decode: '0' alone is invalid, '06' > 26
    
    // Test case 4: Single digit
    string test4 = "5";
    cout << "Test 4: \"" << test4 << "\" -> " << numDecodings(test4) << " ways (Expected: 1)" << endl;
    
    // Test case 5: Multiple valid decodings
    string test5 = "2626";
    cout << "Test 5: \"" << test5 << "\" -> " << numDecodings(test5) << " ways (Expected: 4)" << endl;
    // Decodings: \"2,6,2,6\", \"26,2,6\", \"2,6,26\", \"26,26\"
    
    // Test case 6: All zeros (invalid)
    string test6 = "0";
    cout << "Test 6: \"" << test6 << "\" -> " << numDecodings(test6) << " ways (Expected: 0)" << endl;

    return 0;
}