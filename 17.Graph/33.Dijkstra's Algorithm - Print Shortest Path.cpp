/*
 * Problem Statement: Dijkstra's Algorithm - Print Shortest Path
 *
 * You are given a weighted, undirected graph with V vertices and E edges,
 * represented as an adjacency list. The goal is to find the shortest path
 * (sequence of nodes) from a source node (1) to a destination node (n).
 * If no path exists, return [-1].
 *
 * Key Observations:
 * - Each edge has a non-negative weight.
 * - Dijkstra's algorithm can find the shortest distances from source to all nodes.
 * - To reconstruct the actual path, we need a parent array to track the preceding node
 *   for each vertex on the shortest path.
 *
 * Intuition:
 * 1. Initialize a distance array of size V with all values as infinity.
 * 2. Initialize a parent array where parent[i] = i for all nodes.
 * 3. Set distance[source] = 0.
 * 4. Use a min-priority queue to process nodes by minimal distance.
 * 5. During relaxation, if a shorter distance to a neighbor is found:
 *     - Update distance[neighbor].
 *     - Update parent[neighbor] = current_node.
 *     - Push (new_distance, neighbor) into the priority queue.
 * 6. After Dijkstra's completes, reconstruct the path from destination to source
 *    using the parent array and reverse it for correct order.
 *
 * Time Complexity:
 * - O(E log V + V) : O(E log V) for Dijkstra's algorithm using priority queue,
 *   O(V) for backtracking the path.
 *
 * Space Complexity:
 * - O(V + E) for adjacency list.
 * - O(V) for distance array.
 * - O(V) for parent array.
 * - O(V) for priority queue.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Dijkstra's Algorithm with Path Reconstruction
// ---------------------------
vector<int> shortestPath(int V, vector<pair<int,int>> adj[], int source, int destination) {
    vector<int> distance(V, INT_MAX);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    distance[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currDist, u] = pq.top(); pq.pop();
        if (currDist > distance[u]) continue;

        for (auto &[v, weight] : adj[u]) {
            int newDist = currDist + weight;
            if (newDist < distance[v]) {
                distance[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    if (distance[destination] == INT_MAX) return {-1};

    int node = destination;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    return path;
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

    int source = 0, destination = 4;
    vector<int> path = shortestPath(V, adj, source, destination);

    cout << "Shortest path from node " << source << " to node " << destination << ":\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
