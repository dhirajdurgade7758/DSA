#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // initialization
        vector<pair<int, int>> pairs;
        stack<int> st;
        int n = position.size();

        // pair position and speed
        for (int i = 0; i < n; i++) {
            pairs.push_back({position[i], speed[i]});
        }

        // sort based on position (ascending)
        sort(pairs.begin(), pairs.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.first < b.first;
             });

        // monotonic stack approach
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            double reachtimeB =
                (double)(target - pairs[st.top()].first) / pairs[st.top()].second;
            double reachtimeA =
                (double)(target - pairs[i].first) / pairs[i].second;

            cout << "Front car time: " << reachtimeB << endl;
            cout << "Current car time: " << reachtimeA << endl;

            if (reachtimeA > reachtimeB) {
                st.push(i);
            }
        }

        return st.size();
    }
};

int main() {
    Solution sol;

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = sol.carFleet(target, position, speed);
    cout << "Number of car fleets: " << result << endl;

    return 0;
}
