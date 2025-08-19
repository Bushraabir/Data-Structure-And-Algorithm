/*
 * Problem Statement: Dijkstra's Algorithm - Shortest Path Using Priority Queue
 *
 * You are given a weighted, directed graph with V vertices and E edges, represented
 * as an adjacency list. The goal is to find the shortest distance from a given source
 * node to all other nodes in the graph.
 *
 * Key Observations:
 * - Each edge has a non-negative weight.
 * - Dijkstra's algorithm is designed to find the minimum distance from a source node
 *   to all other nodes in an unweighted or weighted graph with non-negative edges.
 * - Using a priority queue (min-heap) ensures that the node with the currently shortest
 *   known distance is always processed first.
 *
 * Intuition:
 * 1. Initialize a distance array of size V with all values as infinity.
 * 2. Set the distance for the source node to 0.
 * 3. Initialize a min-priority queue and push (0, source) into it.
 * 4. While the priority queue is not empty:
 *     - Extract the node with the minimum distance from the queue.
 *     - For each neighbor of this node:
 *         - Calculate the potential new distance via this node.
 *         - If the new distance is shorter than the current distance:
 *             - Update the distance array.
 *             - Push the neighbor with the new distance into the priority queue.
 * 5. After processing, the distance array contains the shortest distances from
 *    the source node to all other nodes.
 *
 * Limitations:
 * - Dijkstra's algorithm does NOT work correctly for graphs with negative edge weights
 *   or negative weight cycles.
 *
 * Time Complexity:
 * - O(E log V), where E is the number of edges and V is the number of vertices.
 *
 * Space Complexity:
 * - O(V + E) for the adjacency list.
 * - O(V) for the distance array.
 * - O(V) for the priority queue.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Dijkstra's Algorithm using Priority Queue
// ---------------------------
vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int source) {
    vector<int> distance(V, INT_MAX);  // Initialize distances to "infinity"
    distance[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});  // {distance, node}

    while (!pq.empty()) {
        auto [currDist, u] = pq.top(); pq.pop();

        // If current distance is already larger than stored distance, skip
        if (currDist > distance[u]) continue;

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
    vector<int> shortestDistances = dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
