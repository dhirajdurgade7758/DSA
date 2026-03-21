#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;

    // Sort by start time
    sort(intervals.begin(), intervals.end());

    // Min heap (stores end times)
    priority_queue<int, vector<int>, greater<int>> pq;

    // Add first meeting
    pq.push(intervals[0][1]);

    for(int i = 1; i < intervals.size(); i++) {
        // If room is free, reuse it
        if(intervals[i][0] >= pq.top()) {
            pq.pop();
        }

        // Allocate current meeting
        pq.push(intervals[i][1]);
    }

    return pq.size();
}

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter meetings (start end):\n";
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = minMeetingRooms(intervals);

    cout << "Minimum meeting rooms required: " << result << endl;

    return 0;
}