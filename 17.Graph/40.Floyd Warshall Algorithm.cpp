/*
 * Problem Statement: All-Pairs Shortest Path (Floyd Warshall)
 *
 * You are given a directed or undirected graph with 'n' nodes numbered from 0 to n-1
 * and a cost matrix or list of edges. Each edge is represented as [u, v, wt], indicating
 * an edge from u to v with weight wt. The goal is to find the shortest distance between
 * every pair of nodes. Additionally, detect if any negative weight cycle exists.
 *
 * Key Observations:
 * - Unlike Dijkstra, Floyd Warshall can handle negative edge weights.
 * - It computes shortest paths between all pairs of nodes.
 * - Negative cycles can be detected if cost[i][i] < 0 after computation.
 * - The algorithm uses dynamic programming by iteratively considering each vertex as an intermediate node.
 *
 * Intuition:
 * 1. Initialize a distance matrix 'dist' of size n x n:
 *     a. dist[i][i] = 0 for all i.
 *     b. dist[u][v] = wt for all given edges u -> v with weight wt.
 *     c. dist[i][j] = INF if no direct edge exists between i and j.
 * 2. Iterate through all possible intermediate nodes k from 0 to n-1:
 *     a. For each source node i from 0 to n-1:
 *         i. For each destination node j from 0 to n-1:
 *             - Update dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
 *               if going through k provides a shorter path.
 * 3. After completion, check for negative cycles:
 *     a. If any dist[i][i] < 0, a negative cycle exists.
 * 4. Return the distance matrix (or indicate negative cycle if detected).
 *
 * Time Complexity:
 * - O(N^3), where N = number of nodes.
 *
 * Space Complexity:
 * - O(N^2) for the distance/cost matrix.
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

bool floydWarshall(int n, vector<vector<long long>>& dist) {
    // dist[i][j] is initially set to INF for no edge, 0 for i==j, or edge weight
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0)
            return false; // Negative cycle exists
    }

    return true; // No negative cycles
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 4;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    // Initialize distances for direct edges
    for (int i = 0; i < n; i++) dist[i][i] = 0; // distance to self = 0
    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 2, 6},
        {1, 2, 4},
        {1, 3, 4},
        {2, 3, 2}
    };
    for (auto &e : edges) {
        int u = e[0], v = e[1], wt = e[2];
        dist[u][v] = wt;
        // For undirected graphs, uncomment the following line
        // dist[v][u] = wt;
    }

    bool noNegativeCycle = floydWarshall(n, dist);

    if (noNegativeCycle) {
        cout << "Shortest distances between all pairs:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Graph contains a negative weight cycle!\n";
    }

    return 0;
}
