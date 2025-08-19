/*
 * Problem Statement: Dijkstra's Algorithm - Shortest Path Using Set
 *
 * You are given a weighted, directed graph with V vertices and E edges, represented
 * as an adjacency list. The goal is to find the shortest distance from a given source
 * node to all other nodes in the graph.
 *
 * Key Observations:
 * - Each edge has a non-negative weight.
 * - Dijkstra's algorithm finds the minimum distance from a source node to all other
 *   nodes in a weighted graph with non-negative edges.
 * - Using a set instead of a priority queue allows explicit removal of outdated
 *   (distance, node) pairs when a shorter path is found.
 *
 * Intuition:
 * 1. Initialize a distance array of size V with all values as infinity.
 * 2. Set the distance for the source node to 0.
 * 3. Initialize a set of pairs (distance, node) and insert (0, source) into it.
 * 4. While the set is not empty:
 *     - Extract the node with the minimum distance from the set and erase it.
 *     - For each neighbor of this node:
 *         - Calculate the potential new distance via this node.
 *         - If the new distance is shorter than the current distance:
 *             - If the neighbor was already in the set, erase its old entry.
 *             - Update the distance array.
 *             - Insert the neighbor with the new distance into the set.
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
 * - O(V) for the set.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Dijkstra's Algorithm using Set
// ---------------------------
vector<int> dijkstraSet(int V, vector<pair<int,int>> adj[], int source) {
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    set<pair<int,int>> st; // {distance, node}
    st.insert({0, source});

    while (!st.empty()) {
        auto [currDist, u] = *st.begin();
        st.erase(st.begin());

        for (auto &[v, weight] : adj[u]) {
            int newDist = currDist + weight;
            if (newDist < distance[v]) {
                if (distance[v] != INT_MAX) {
                    st.erase({distance[v], v}); // remove old entry
                }
                distance[v] = newDist;
                st.insert({newDist, v});
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
    vector<int> shortestDistances = dijkstraSet(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << "\n";
    }

    return 0;
}
