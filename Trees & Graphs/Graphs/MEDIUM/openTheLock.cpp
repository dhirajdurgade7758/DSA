class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000")) return -1;

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            string curr = front.first;
            int steps = front.second;

            if (curr == target) return steps;

            for (int i = 0; i < 4; i++) {
                string up = curr;
                string down = curr;

                // rotate wheel up
                up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;

                // rotate wheel down
                down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                if (!dead.count(up) && !vis.count(up)) {
                    q.push({up, steps + 1});
                    vis.insert(up);
                }

                if (!dead.count(down) && !vis.count(down)) {
                    q.push({down, steps + 1});
                    vis.insert(down);
                }
            }
        }

        return -1;
    }
};