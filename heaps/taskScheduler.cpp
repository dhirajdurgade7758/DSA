#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            freq[ch]++;
        }

        priority_queue<int> maxHeap;
        for (auto &p : freq) {
            maxHeap.push(p.second);
        }

        queue<pair<int, int>> q; // {remainingCount, nextAvailableTime}
        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // Move tasks whose cooldown is finished back to heap
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }

            // Execute the most frequent task
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n + 1});
                }
            }
        }
        return time;
    }
};

int main() {
    Solution sol;

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << "Least Interval: " << sol.leastInterval(tasks, n) << endl;

    return 0;
}
