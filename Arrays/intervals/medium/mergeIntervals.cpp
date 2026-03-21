#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    // Edge case
    if(intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] <= res.back()[1]) {
            // Merge
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        } else {
            // No overlap
            res.push_back(intervals[i]);
        }
    }

    return res;
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

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged intervals:\n";
    for(auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}