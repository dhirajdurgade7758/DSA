#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq; // stores indices

    for (int i = 0; i < nums.size(); i++) {

        // 1️⃣ Remove elements out of current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // 2️⃣ Remove smaller elements (they are useless)
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // 3️⃣ Add current index
        dq.push_back(i);

        // 4️⃣ Window formed → store answer
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
