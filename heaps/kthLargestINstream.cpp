#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest obj(k, nums);

    cout << obj.add(3) << endl;   // 4
    cout << obj.add(5) << endl;   // 5
    cout << obj.add(10) << endl;  // 5
    cout << obj.add(9) << endl;   // 8
    cout << obj.add(4) << endl;   // 8

    return 0;
}
