/*
 * Problem Statement: Detect Cycle in a Directed Graph Using BFS (Kahn's Algorithm)
 *
 * You are given a directed graph with N nodes represented as an adjacency list.
 * Task: Determine whether the graph contains a cycle using Kahn's Algorithm.
 *       The approach leverages BFS-based topological sorting: if a complete
 *       topological order of all nodes cannot be formed, the graph has a cycle.
 *
 * Example Input:
 * N = 6
 * adjacencyList = {
 *   {},        // Node 0
 *   {},        // Node 1
 *   {3},       // Node 2 has an edge to Node 3
 *   {1},       // Node 3 has an edge to Node 1
 *   {0,1},     // Node 4 has edges to Node 0 and Node 1
 *   {0,2}      // Node 5 has edges to Node 0 and Node 2
 * }
 *
 * Key Observations:
 * - A cycle exists if and only if a complete topological sort is not possible.
 * - Nodes with in-degree 0 can be processed first.
 * - BFS (Kahn's Algorithm) can detect cycles by counting nodes processed.
 *
 * Intuition:
 * - Calculate in-degree of all nodes.
 * - Initialize a queue with nodes having in-degree 0.
 * - While the queue is not empty:
 *     * Dequeue a node and increment a counter.
 *     * For each neighbor, decrement in-degree by 1.
 *     * If neighbor's in-degree becomes 0, enqueue it.
 * - After processing, if counter < N, the graph contains a cycle.
 *
 * Edge Cases:
 * - Disconnected graphs must include all components by checking all nodes.
 * - Graphs with no edges are trivially acyclic.
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes and M is the number of edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for in-degree array, O(N) for queue.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Function to Detect Cycle Using Kahn's Algorithm (BFS)
// ---------------------------
bool hasCycleBFS(int N, vector<vector<int>> &adj) {
    vector<int> inDegree(N, 0);
    queue<int> q;
    int processedNodes = 0;

    // Step 1: Calculate in-degree of each node
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Enqueue nodes with in-degree 0
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // Step 3: Process nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processedNodes++;

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: If all nodes were processed, graph is acyclic
    return processedNodes != N; // true if cycle exists
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 6;
    vector<vector<int>> adjacencyList = {
        {},    // Node 0
        {},    // Node 1
        {3},   // Node 2
        {1},   // Node 3
        {0,1}, // Node 4
        {0,2}  // Node 5
    };

    bool containsCycle = hasCycleBFS(N, adjacencyList);

    if (containsCycle)
        cout << "The graph contains a cycle.\n";
    else
        cout << "The graph does not contain a cycle (DAG).\n";

    return 0;
}
