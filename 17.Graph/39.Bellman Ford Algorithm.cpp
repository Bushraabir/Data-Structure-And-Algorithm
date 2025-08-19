/*
 * Problem Statement: Single Source Shortest Path with Negative Weights (Bellman-Ford)
 *
 * You are given a directed graph with 'n' nodes numbered from 0 to n-1 and a list of edges.
 * Each edge is represented as [u, v, wt], indicating a directed edge from u to v with weight wt.
 * The goal is to find the shortest distance from a given source node (usually 0) to all other nodes.
 * Additionally, detect if the graph contains a negative weight cycle.
 *
 * Key Observations:
 * - Unlike Dijkstra, Bellman-Ford can handle negative edge weights.
 * - If after n-1 iterations of relaxing all edges, any distance can still be reduced,
 *   a negative weight cycle exists.
 * - Each iteration of relaxing all edges propagates shortest distances one more "hop" away from the source.
 *
 * Intuition:
 * 1. Initialize a distance array 'dist' of size n; dist[source] = 0, all others = INF.
 * 2. Repeat n-1 times:
 *     a. For each edge u -> v with weight wt:
 *         - If dist[u] + wt < dist[v], then update dist[v] = dist[u] + wt.
 * 3. Optional n-th iteration to detect negative cycles:
 *     a. For each edge u -> v with weight wt:
 *         - If dist[u] + wt < dist[v], negative cycle exists.
 * 4. Return the distance array (or indicate negative cycle if detected).
 *
 * Time Complexity:
 * - O(V * E), where V = number of nodes, E = number of edges.
 *
 * Space Complexity:
 * - O(V + E) for storing the graph.
 * - O(V) for distance array.
 */

#include <bits/stdc++.h>
using namespace std;

bool bellmanFord(int n, vector<vector<int>>& edges, int source, vector<long long>& dist) {
    const long long INF = 1e18;
    dist.assign(n, INF);
    dist[source] = 0;

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (dist[u] != INF && dist[u] + wt < dist[v]) {
            return false; // Negative cycle detected
        }
    }

    return true; // No negative cycle
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 3, 7}
    };

    vector<long long> dist;
    bool noNegativeCycle = bellmanFord(n, edges, 0, dist);

    if (noNegativeCycle) {
        cout << "Shortest distances from source 0:\n";
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    } else {
        cout << "Graph contains a negative weight cycle!\n";
    }

    return 0;
}
