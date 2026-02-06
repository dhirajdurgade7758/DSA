#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (!pq.empty()) {
            if (pq.size() == 1) {
                return pq.top();
            }
            int y = pq.top(); 
            pq.pop();
            int x = pq.top(); 
            pq.pop();

            if (y - x > 0) {
                pq.push(y - x);
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    int result = sol.lastStoneWeight(stones);
    cout << "Last stone weight: " << result << endl;

    return 0;
}
