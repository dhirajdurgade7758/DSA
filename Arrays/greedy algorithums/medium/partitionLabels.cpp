#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {

        // Step 1: Store the last occurrence index of every character
        unordered_map<char, int> last;
        for(int i = 0; i < s.length(); i++){
            last[s[i]] = i;
        }

        vector<int> ans;   // stores partition sizes
        int partLen = 0;   // last index of current partition

        // Traverse the string
        for(int i = 0; i < s.length(); i++){

            // Set the current partition end using last occurrence
            partLen = last[s[i]];

            int charCount = 0; // size of current partition

            // Expand partition until we reach its farthest required index
            while(i <= partLen){

                // Update partition end if another character extends it
                partLen = max(partLen, last[s[i]]);

                charCount++; // count characters in partition
                i++;         // move to next character
            }

            // Store partition length
            ans.push_back(charCount);

            // Important: reduce i because for-loop will increment it again
            i--;
        }

        return ans;
    }
};

int main(){

    Solution obj;

    // Example input
    string s = "ababcbacadefegdehijhklij";

    // Call function
    vector<int> result = obj.partitionLabels(s);

    // Print result
    cout << "Partition Sizes: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}