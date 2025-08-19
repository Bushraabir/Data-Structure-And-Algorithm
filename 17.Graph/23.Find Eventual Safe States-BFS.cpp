/*
 * Problem Statement: Eventual Safe States Using BFS (Kahn's Algorithm)
 *
 * You are given a directed graph with N nodes (0-indexed) represented as an adjacency list.
 * A node is considered:
 * - Terminal: if it has no outgoing edges.
 * - Safe: if every possible path starting from it leads to a terminal node.
 *
 * Task: Return a sorted list of all safe nodes using a BFS-based topological sort.
 *
 * Key Observations:
 * - Terminal nodes are always safe.
 * - Nodes in cycles or that lead to cycles are unsafe.
 * - Reverse the graph and perform BFS using Kahn's Algorithm to find safe nodes.
 *
 * Intuition:
 * 1. Reverse all edges: u -> v becomes v -> u.
 * 2. Compute in-degree for all nodes in the reversed graph.
 * 3. Initialize a queue with nodes having in-degree 0 (original terminals).
 * 4. While queue is not empty:
 *     * Dequeue node u and add it to the safe nodes list.
 *     * For each neighbor v of u in reversed graph:
 *         - Decrement in-degree[v].
 *         - If in-degree[v] becomes 0, enqueue v.
 * 5. Sort the safe nodes in ascending order before returning.
 *
 * Time Complexity:
 * - O(V + E) for graph reversal and BFS traversal.
 * - O(S log S) for sorting safe nodes, where S is the number of safe nodes.
 *
 * Space Complexity:
 * - O(V + E) for reversed adjacency list.
 * - O(V) for in-degree array, queue, and result list.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Function to find eventual safe nodes using BFS (Kahn's Algorithm)
// ---------------------------
vector<int> eventualSafeNodes(int N, vector<vector<int>> &adj) {
    vector<vector<int>> adjRev(N);
    vector<int> inDegree(N, 0);

    // Step 1: Reverse the graph and calculate in-degree
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            adjRev[v].push_back(u); // reverse edge
            inDegree[u]++;          // in-degree in reversed graph
        }
    }

    queue<int> q;
    // Step 2: Enqueue nodes with in-degree 0 (original terminals)
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> safeNodes;
    // Step 3: BFS traversal
    while (!q.empty()) {
        int node = q.front(); q.pop();
        safeNodes.push_back(node);

        for (int neighbor : adjRev[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 7;
    vector<vector<int>> adjacencyList = {
        {1,2},    // Node 0
        {2,3},    // Node 1
        {5},      // Node 2
        {0},      // Node 3
        {5},      // Node 4
        {},       // Node 5 (terminal)
        {}        // Node 6 (terminal)
    };

    vector<int> safeNodes = eventualSafeNodes(N, adjacencyList);

    cout << "Eventual safe nodes: ";
    for (int node : safeNodes) cout << node << " ";
    cout << "\n";

    return 0;
}
