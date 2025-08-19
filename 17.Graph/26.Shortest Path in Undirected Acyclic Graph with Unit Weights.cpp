/*
 * Problem Statement: Shortest Path in an Undirected Graph with Unit Weights Using BFS
 *
 * You are given an undirected graph with N nodes (0-indexed) where all edges have
 * a unit weight of 1. The goal is to find the shortest distance from a specified
 * source node to all other nodes.
 *
 * Task: Return a vector of distances from the source to all nodes. If a node is
 *       unreachable, distance should be -1.
 *
 * Key Observations:
 * - BFS explores nodes layer by layer, making it ideal for shortest paths in unweighted or unit-weight graphs.
 * - Each edge contributes exactly 1 to the distance.
 * - Distances are naturally discovered in increasing order during BFS traversal.
 *
 * Intuition:
 * 1. Create an adjacency list for the undirected graph.
 * 2. Initialize a distance array of size N with INF (or a large number) and set distance[source] = 0.
 * 3. Initialize a queue and enqueue the source node with distance 0.
 * 4. While the queue is not empty:
 *     - Dequeue a node and its current distance.
 *     - For each neighbor:
 *         - If distance[neighbor] > current_distance + 1:
 *             - Update distance[neighbor] = current_distance + 1.
 *             - Enqueue neighbor with updated distance.
 * 5. After BFS, set distance[i] = -1 for all nodes i that remain at INF (unreachable).
 *
 * Time Complexity:
 * - O(V + E), where V is number of nodes and E is number of edges. Each node and edge is visited at most once.
 *
 * Space Complexity:
 * - O(V + E) for adjacency list, O(V) for distance array and queue.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS to find shortest distances in an undirected graph with unit weights
// ---------------------------
vector<int> shortestPathUnitGraph(int N, vector<vector<int>> &adj, int source) {
    vector<int> distance(N, INT_MAX);
    distance[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (distance[u] + 1 < distance[v]) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    // Set unreachable nodes to -1
    for (int i = 0; i < N; i++) {
        if (distance[i] == INT_MAX) distance[i] = -1;
    }

    return distance;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 7;
    vector<vector<int>> adj(N);

    // Undirected graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3, 5, 6};
    adj[5] = {4};
    adj[6] = {4};

    int source = 0;
    vector<int> distances = shortestPathUnitGraph(N, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < N; i++) {
        cout << distances[i] << " ";
    }
    cout << "\n";

    return 0;
}
