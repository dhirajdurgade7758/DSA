class Solution {
public:

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<bool>& vis) {

        vis[node] = true;

        for (int neighbor : adj[node]) {

            if (!vis[neighbor]) {

                if (dfs(neighbor, node, adj, vis)) {
                    return true;
                }

            }
            else if (neighbor != parent) {
                return true; // cycle found
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        // Tree must have exactly n-1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        // Detect cycle
        if (dfs(0, -1, adj, vis)) {
            return false;
        }

        // Check connectivity
        for (bool visited : vis) {
            if (!visited) {
                return false;
            }
        }

        return true;
    }
};