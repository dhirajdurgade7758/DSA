#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end());

    int count = 0;
    int j = 0;

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < intervals[j][1]) {
            count++;

            // Keep interval with smaller end time
            if(intervals[i][1] < intervals[j][1]) {
                j = i;
            }
        } else {
            j = i;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    cout << "Enter intervals (start end):\n";
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    int result = eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << result << endl;

    return 0;
}