#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;

    for(int i = 0; i < intervals.size(); i++) {
        if(newInterval[1] < intervals[i][0]) {
            res.push_back(newInterval);
            for(int j = i; j < intervals.size(); j++) {
                res.push_back(intervals[j]);
            }
            return res;
        }
        else if(newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
        }
        else {
            newInterval = {
                min(intervals[i][0], newInterval[0]),
                max(intervals[i][1], newInterval[1])
            };
        }
    }

    res.push_back(newInterval);
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

    vector<int> newInterval(2);
    cout << "Enter new interval (start end): ";
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> result = insertInterval(intervals, newInterval);

    cout << "Result intervals:\n";
    for(auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}