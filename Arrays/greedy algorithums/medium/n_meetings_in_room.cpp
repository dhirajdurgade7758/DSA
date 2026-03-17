#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    
    vector<pair<int,int>> meetings;
    for(int i = 0; i < n; i++){
        meetings.push_back({end[i], start[i]});
    }

    sort(meetings.begin(), meetings.end()); // sort by end time

    int count = 1;
    int currEnd = meetings[0].first;

    for(int i = 1; i < n; i++){
        if(meetings[i].second > currEnd){
            count++;
            currEnd = meetings[i].first;
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