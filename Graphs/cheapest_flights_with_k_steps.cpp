#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Info {
public:
    int u;      // current node (city)
    int cost;   // cost so far from src to this city
    int stops;  // number of stops made so far

    Info(int u, int cost, int stops) {
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
};

class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        // Queue for BFS traversal (stores city, cost, stops)
        queue<Info> q;

        // Distance array to track min cost for reaching each city
        vector<int> dist(V, INT_MAX);

        // Start from source with 0 cost and -1 stops
        q.push(Info(src, 0, -1));
        dist[src] = 0;

        // BFS traversal
        while (!q.empty()) {
            Info curr = q.front();
            q.pop();

            // Explore all outgoing flights from current city
            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == curr.u) { // edge from curr.u → v
                    int v = flights[i][1];    // destination city
                    int wt = flights[i][2];   // flight cost

                    // If taking this flight gives a cheaper cost
                    // AND stops remain within limit (≤ k)
                    if ((dist[v] > curr.cost + wt) && (curr.stops + 1 <= k)) {
                        dist[v] = curr.cost + wt;
                        // Push new state into queue
                        q.push(Info(v, curr.cost + wt, curr.stops + 1));
                    }
                }
            }
        }

        // If destination city not reachable within K stops
        if (dist[dst] == INT_MAX) {
            return -1;
        }

        // Otherwise return cheapest cost to reach dst
        return dist[dst];
    }
};
