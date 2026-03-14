#include <bits/stdc++.h>
using namespace std;

class Row {
public:
    int Scount;
    int indx;

    Row(int c, int i) {
        Scount = c;
        indx = i;
    }

    // Custom comparator for priority_queue
    bool operator < (const Row &r) const {
        if (this->Scount == r.Scount) {
            return this->indx > r.indx;   // smaller index = weaker
        }
        return this->Scount > r.Scount;   // fewer soldiers = weaker
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> vec;

        for (int i = 0; i < mat.size(); i++) {
            int soldiersCount = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) soldiersCount++;
                else break;
            }
            vec.push_back(Row(soldiersCount, i));
        }

        priority_queue<Row> pq(vec.begin(), vec.end());

        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().indx);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    int k = 3;
    vector<int> result = sol.kWeakestRows(mat, k);

    for (int idx : result) {
        cout << idx << " ";
    }

    return 0;
}
