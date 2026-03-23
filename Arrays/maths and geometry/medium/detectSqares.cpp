#include <bits/stdc++.h>
using namespace std;

class DetectSquares {
public:
    map<pair<int, int>, int> ptsCount;
    vector<pair<int, int>> pts;

    DetectSquares() {}

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ptsCount[{x, y}]++;
        pts.push_back({x, y});
    }

    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int res = 0;

        for (auto &p : pts) {
            int x = p.first, y = p.second;

            // Check if diagonal of square
            if (abs(py - y) != abs(px - x) || x == px || y == py)
                continue;

            // Count possible squares
            res += ptsCount[{x, py}] * ptsCount[{px, y}];
        }

        return res;
    }
};