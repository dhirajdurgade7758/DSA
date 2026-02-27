#include<iostream>
#include<vector>
#include<string>
using namespace std;

// My approach - brute force (commented because optimized solution is better)
// This approach tries to maximize character values from the end,
// but can be inefficient and harder to track remaining sum correctly
// class Solution {
// public:
//     string getSmallestString(int n, int k) {
//         vector<char> alphabets = {
//         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
//         'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
//         'u', 'v', 'w', 'x', 'y', 'z'
//         };
//         string ans ="";
//         for(int i=n; i>0; i--){
//             if(k>(26+(n-1))){
//                 ans.push_back('z');
//                 k-=26;
//             }
//             else{
//                 int indx = abs(k-(i-1));
//                 indx--;
//                 if(indx<0){
//                     indx=0;
//                 }
//                 k=i-1;
//                 // ans.insert(ans.begin(), alphabets[indx]);
//                 ans = alphabets[indx] + ans;  
//             }
//         }
//         return ans;
        
//     }
// }; 

class Solution {
public:
    string getSmallestString(int n, int k) {
        // STEP 1: Create starting string with all 'a' (gives minimum value)
        vector<char> alphabets = {
       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
       'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
       'u', 'v', 'w', 'x', 'y', 'z'
        };
        string res(n, 'a');  // All characters start as 'a' (sum = n)
        k-=n;  // Remaining budget to increase character values

        // STEP 2: Greedily maximize characters from the end to keep lexicographically smallest
        while(k > 0){
            // At each position from the end, use as large a character as budget allows
            // Max difference from 'a' is 25 (when using 'z')
            res[n-1] = alphabets[min(25, k)];
            k -= min(25, k);  // Deduct used budget
            n--;  // Move to previous position
        }
        return res;
        
    }
};

int main() {
    Solution sol;
    int n = 3, k = 27;
    cout << "Smallest string with n=" << n << ", k=" << k << ": " << sol.getSmallestString(n, k) << endl;
    
    int n2 = 5, k2 = 73;
    cout << "Smallest string with n=" << n2 << ", k=" << k2 << ": " << sol.getSmallestString(n2, k2) << endl;
    return 0;
} 