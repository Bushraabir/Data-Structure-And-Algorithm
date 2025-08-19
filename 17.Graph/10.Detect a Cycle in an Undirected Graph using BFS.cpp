/*
 * Problem Statement: Detect Cycle in an Undirected Graph using BFS
 *
 * You are given an undirected graph with V vertices and E edges, represented as an adjacency list.
 * Task: Determine if the graph contains a cycle.
 *
 * Example Input:
 * V = 7
 * Edges:
 * 1-2, 1-3, 2-5, 3-4, 3-6, 5-7, 6-7
 *
 * Key Observations:
 * - BFS explores nodes level by level (all neighbors of the current node before moving deeper).
 * - To detect cycles, we must track the parent node from which we arrived at the current node.
 * - If we encounter a visited neighbor that is not the parent, a cycle exists.
 *
 * Intuition:
 * - Initialize a visited array of size V to track processed nodes.
 * - For each unvisited node (to handle disconnected components):
 *   * Perform BFS starting from that node.
 *   * For each dequeued node, check all neighbors:
 *     - If neighbor is unvisited, mark it visited and enqueue with current node as parent.
 *     - If neighbor is visited and is not parent, cycle detected → return true.
 * - If BFS completes without detecting a cycle in any component, return false.
 *
 * Edge Cases:
 * - Graph has multiple disconnected components.
 * - Single node with no edges → no cycle.
 * - Self-loops or parallel edges in input should be considered.
 *
 * Time Complexity:
 * - O(V + E), since each vertex and each edge is visited once.
 *
 * Space Complexity:
 * - O(V) for visited array and BFS queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Function to Detect Cycle
// ---------------------------
bool detectCycleBFS(int src, vector<vector<int>> &adj, vector<int> &visited) {
    queue<pair<int,int>> q; // {node, parent}
    visited[src] = 1;
    q.push({src, -1}); // source has no parent

    while (!q.empty()) {
        auto [node, parent] = q.front(); q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                // Visited neighbor not parent → cycle detected
                return true;
            }
        }
    }
    return false; // no cycle found in this component
}

// ---------------------------
// Cycle Detection in Graph
// ---------------------------
bool isCycle(int V, vector<vector<int>> &adj) {
    vector<int> visited(V + 1, 0); // 1-based indexing

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            if (detectCycleBFS(i, adj, visited))
                return true;
        }
    }
    return false; // no cycle in any component
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int V = 7;
    vector<vector<int>> adj(V + 1); // 1-based indexing

    // Adding edges
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[3].push_back(4); adj[4].push_back(3);
    adj[3].push_back(6); adj[6].push_back(3);
    adj[5].push_back(7); adj[7].push_back(5);
    adj[6].push_back(7); adj[7].push_back(6);

    if (isCycle(V, adj))
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}
