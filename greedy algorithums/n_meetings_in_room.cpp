#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // STEP 1: Initialize with first meeting (assumes input sorted by end time)
        int currend = end[0];  // Track end time of last selected meeting
        int count = 1;         // Start count with first meeting
        int n=start.size();
        
        // STEP 2: Greedy approach - select meetings that start after previous one ends
        for(int i=1; i<n; i++){
            // If meeting starts after previous one ends, we can schedule it
            if(start[i] > currend){
                count++;        // Increment meeting count
                currend=end[i]; // Update end time of last selected meeting
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << "Maximum meetings that can be scheduled: " << sol.maxMeetings(start, end) << endl;
    return 0;
}