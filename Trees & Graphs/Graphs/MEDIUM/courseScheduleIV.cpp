class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {

        vector<vector<bool>> reach(numCourses,
                                   vector<bool>(numCourses, false));

        // Direct prerequisites
        for (auto &p : prerequisites) {
            reach[p[0]][p[1]] = true;
        }

        // Floyd Warshall
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {

                    if (reach[i][k] && reach[k][j]) {
                        reach[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(reach[q[0]][q[1]]);
        }

        return ans;
    }
};