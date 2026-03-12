#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    string toLowercase(const string& input) {
        string result = input;

        transform(result.begin(), result.end(), result.begin(),
                  [](unsigned char c) {
                      return tolower(c);
                  });

        return result;
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        string str = toLowercase(s);

        while (st < end) {
            // Skip non-alphanumeric characters
            while (st < end && !isalnum(str[st])) st++;
            while (st < end && !isalnum(str[end])) end--;

            if (str[st] != str[end]) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s = "A man, a plan, a canal: Panama";

    if (sol.isPalindrome(s)) {
        cout << "The string is a palindrome" << endl;
    } else {
        cout << "The string is NOT a palindrome" << endl;
    }

    return 0;
}