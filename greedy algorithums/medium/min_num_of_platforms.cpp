#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // STEP 1: Sort arrival and departure times separately
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxcount=0;  // Maximum platforms needed at any time
        int i=0, j=0;   // Pointers for arrival and departure arrays
        int count=0;    // Current trains at platform

        // STEP 2: Use two-pointer technique to find peak platform requirement
        while(i<arr.size()){
            // If train arrival happens before/at departure, increment platform count
            if(arr[i]<=dep[j]){
                i++;      // Move to next arrival
                count++;  // Increment trains requiring platform
            }
            // If departure happens before arrival, free up a platform
            else{
                j++;      // Move to next departure
                count--;  // Decrement trains requiring platform
            }
            // Track maximum platforms needed at any point
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum number of platforms needed: " << sol.findPlatform(arr, dep) << endl;
    return 0;
}
