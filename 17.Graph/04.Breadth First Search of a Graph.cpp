/*
 * Problem Statement: Breadth-First Search (BFS) Traversal in a Graph
 *
 * You are given a graph with N nodes and M edges, and a starting node S.
 * Task: Perform a BFS traversal of the graph starting from node S.
 *
 * Example Input (Undirected, Unweighted):
 * N = 6, M = 7, S = 1
 * Edges:
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 6
 * 5 6
 * 4 5
 *
 * Key Observations:
 * - BFS explores the graph level by level.
 * - It guarantees that nodes closer to the starting node are visited first.
 * - Uses a queue to maintain the order of traversal.
 * - A visited array prevents revisiting nodes.
 *
 * Intuition:
 * - Use a queue for FIFO traversal.
 * - Enqueue the starting node and mark it visited.
 * - While queue is not empty:
 *   * Dequeue a node, add it to the BFS result.
 *   * Enqueue all unvisited neighbors, marking them visited.
 *
 * Edge Cases:
 * - Disconnected graph → BFS will only cover the connected component of the starting node.
 * - Single node graph → BFS visits the node only.
 *
 * Time Complexity:
 * - O(N + M), as each node is visited once and each edge is checked once.
 *
 * Space Complexity:
 * - O(N) for visited array and BFS queue.
 * - Adjacency list uses O(N + M) space (not counted in BFS-specific complexity).
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Traversal Function
// ---------------------------
vector<int> bfsTraversal(int N, vector<vector<int>> &adj, int start) {
    vector<bool> visited(N+1, false); // 1-based indexing
    vector<int> bfsResult;
    queue<int> q;

    // Initialize
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfsResult.push_back(node);

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }

    return bfsResult;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 6, S = 1;
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{2,5},{3,6},{5,6},{4,5}};

    // Build adjacency list
    vector<vector<int>> adj(N+1);
    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<int> bfsResult = bfsTraversal(N, adj, S);

    cout << "BFS Traversal starting from node " << S << ": ";
    for (int node : bfsResult) cout << node << " ";
    cout << "\n";

    return 0;
}
