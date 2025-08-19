/*
 * Problem Statement: Dijkstra's Algorithm - Why Priority Queue / Set over Queue, Intuition, and Time Complexity
 *
 * You are given a weighted, directed graph with V vertices and E edges, represented
 * as an adjacency list. The goal is to find the shortest distance from a given source
 * node to all other nodes in the graph.
 *
 * Key Observations:
 * - Each edge has a non-negative weight.
 * - Using a standard queue (FIFO) might yield correct results but is inefficient.
 *   Redundant processing occurs when longer paths to the same node are explored.
 * - Priority Queue (Min-Heap) or Set ensures that nodes are processed in order of
 *   minimal distance, reducing unnecessary iterations.
 *
 * Intuition:
 * 1. Dijkstra's algorithm is greedy: it always chooses the unvisited node with the
 *    smallest known distance from the source.
 * 2. Once a node's minimal distance is finalized, it cannot be improved further.
 * 3. Using a priority queue or set guarantees that the next node processed is always
 *    the closest unvisited node, preventing redundant exploration of longer paths.
 *
 * Time Complexity Derivation (O(E log V)):
 * 1. Let V be the number of vertices and E be the number of edges.
 * 2. Each node is extracted from the priority queue at most once: O(V log V) for pops.
 * 3. For each edge, the potential distance update (push) into the priority queue costs O(log V).
 * 4. Total edge operations = O(E log V).
 * 5. Combining: O(V log V + E log V) ≈ O(E log V) (dominant term).
 *
 * Limitations:
 * - Dijkstra's algorithm does NOT work correctly for graphs with negative edge weights
 *   or negative weight cycles.
 *
 * Space Complexity:
 * - O(V + E) for the adjacency list.
 * - O(V) for the distance array.
 * - O(V) for the priority queue or set.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Dijkstra's Algorithm using Priority Queue
// ---------------------------
vector<int> dijkstraPQ(int V, vector<pair<int,int>> adj[], int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source}); // {distance, node}

    while (!pq.empty()) {
        auto [currDist, u] = pq.top(); pq.pop();

        if (currDist > distance[u]) continue; // Skip outdated longer paths

        for (auto &[v, weight] : adj[u]) {
            int newDist = currDist + weight;
            if (newDist < distance[v]) {
                distance[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    return distance;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int V = 5;  // Number of vertices
    vector<pair<int,int>> adj[V];

    // Example graph edges {node, weight}
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int source = 0;
    vector<int> shortestDistances = dijkstraPQ(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
