#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        if (s.length() == 1) return 1;

        int st = 0;
        int end = 1;
        unordered_set<char> hashset;

        hashset.insert(s[0]);
        int maxlen = 1;

        while (st < s.length() && end < s.length()) {

            while (hashset.find(s[end]) != hashset.end()) {
                hashset.erase(s[st]);
                st++;
            }

            hashset.insert(s[end]);
            int sz = hashset.size();
            maxlen = max(maxlen, sz);
            end++;
        }

        return maxlen;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}
