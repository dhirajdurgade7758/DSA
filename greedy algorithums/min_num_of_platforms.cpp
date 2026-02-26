#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxcount=0;
        int i=0, j=0;
        int count=0;

        while(i<arr.size()){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
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
