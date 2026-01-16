#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq(26, 0), winfreq(26, 0);

        // Frequency of s1
        for (char c : s1) {
            freq[c - 'a']++;
        }

        int windowSize = s1.size();

        // First window
        for (int i = 0; i < windowSize; i++) {
            winfreq[s2[i] - 'a']++;
        }

        if (freq == winfreq) return true;

        // Sliding window
        for (int end = windowSize; end < s2.size(); end++) {
            winfreq[s2[end] - 'a']++;                 // add right char
            winfreq[s2[end - windowSize] - 'a']--;   // remove left char

            if (freq == winfreq) return true;
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "ab";
    string s2 = "eidbaooo";

    if (sol.checkInclusion(s1, s2)) {
        cout << "True: Permutation exists\n";
    } else {
        cout << "False: Permutation does not exist\n";
    }

    return 0;
}
