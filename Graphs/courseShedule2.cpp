#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---------- Function to check for cycles using DFS ----------
    bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& adj) {
        vis[src] = true;        // mark current node as visited
        recPath[src] = true;    // mark in recursion path

        // traverse all neighbors (courses that depend on this course)
        for(int v : adj[src]) {
            if(!vis[v]) {
                if(isCycle(v, vis, recPath, adj)) return true; // cycle found
            } 
            else if(recPath[v]) {
                return true; // cycle detected (back edge)
            }
        }

        recPath[src] = false;   // remove from recursion path before backtracking
        return false;
    }

    // ---------- Topological Sort using DFS ----------
    void topSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& adj) {
        vis[src] = true;

        // visit all neighbors
        for(int v : adj[src]) {
            if(!vis[v]) {
                topSort(v, vis, s, adj);
            }
        }

        // push course to stack after exploring all dependencies
        s.push(src);
    }

    // ---------- Main Function ----------
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;

        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for(auto &edge : prerequisites) {
            int a = edge[0]; // to take course a
            int b = edge[1]; // you must first complete b
            adj[b].push_back(a); // edge: b -> a
        }

        // Step 2: Detect cycles
        vector<bool> vis(V, false), recPath(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycle(i, vis, recPath, adj)) {
                    return {}; // cycle found → impossible to finish
                }
            }
        }

        // Step 3: Topological sort
        vector<bool> vis2(V, false);
        stack<int> s;
        for(int i = 0; i < V; i++) {
            if(!vis2[i]) {
                topSort(i, vis2, s, adj);
            }
        }

        // Step 4: Extract result from stack
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

// ---------- Driver Code for VS Code ----------
int main() {
    Solution sol;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1,0}};
    vector<int> order1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Order for Example 1: ";
    for(int x : order1) cout << x << " ";
    cout << endl;

    // Example 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> order2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Order for Example 2: ";
    for(int x : order2) cout << x << " ";
    cout << endl;

    // Example 3 (cycle)
    int numCourses3 = 2;
    vector<vector<int>> prerequisites3 = {{0,1},{1,0}};
    vector<int> order3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Order for Example 3: ";
    if(order3.empty()) cout << "Impossible (Cycle Detected)";
    else for(int x : order3) cout << x << " ";
    cout << endl;

    return 0;
}
