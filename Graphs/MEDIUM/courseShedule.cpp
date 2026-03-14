#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to detect cycle in a directed graph using DFS
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& graph) {
        vis[src] = true;       // mark current node as visited
        recPath[src] = true;   // mark node as part of the current recursion path

        // Explore all neighbors (edges src -> nbr)
        for (auto &edge : graph) {
            int u = edge[1]; // prerequisite (from)
            int v = edge[0]; // course (to)

            if (src == u) {  // if this edge starts from current node
                if (!vis[v]) {
                    // if neighbor is not visited, recurse
                    if (isCycle(v, vis, recPath, graph)) {
                        return true; // cycle found in recursion
                    }
                } else {
                    // if neighbor is visited and is in recursion path → cycle
                    if (recPath[v]) {
                        return true;
                    }
                }
            }
        }

        recPath[src] = false;  // backtrack: remove from recursion path
        return false;
    }

    // Main function: check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<bool> vis(V, false);     // visited array
        vector<bool> recPath(V, false); // recursion stack (to detect back edges)

        // Run DFS from every unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, recPath, prerequisites)) {
                    return false; // cycle detected → cannot finish all courses
                }
            }
        }

        return true; // no cycle → possible to finish all courses
    }
};

int main() {
    Solution sol;

    // Example 1:
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}}; 
    // meaning: to take course 1, you must complete course 0 first

    if (sol.canFinish(numCourses, prerequisites)) {
        cout << "All courses can be finished ✅" << endl;
    } else {
        cout << "Cycle detected ❌, cannot finish all courses" << endl;
    }

    // Example 2:
    numCourses = 2;
    prerequisites = {{1, 0}, {0, 1}}; 
    // cycle: 0 → 1 → 0

    if (sol.canFinish(numCourses, prerequisites)) {
        cout << "All courses can be finished ✅" << endl;
    } else {
        cout << "Cycle detected ❌, cannot finish all courses" << endl;
    }

    return 0;
}
