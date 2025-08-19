/*
 * Problem Statement: Topological Sorting Using BFS (Kahn's Algorithm)
 *
 * You are given a directed acyclic graph (DAG) with N nodes represented as an adjacency list.
 * Task: Find a valid linear ordering of nodes such that for every directed edge u -> v,
 *       node u appears before node v in the ordering using BFS (Kahn's Algorithm).
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
 * - Topological sort is only possible for DAGs.
 * - Nodes with in-degree 0 have no dependencies and can be processed first.
 * - Use a queue to process nodes in BFS manner while decrementing in-degrees of neighbors.
 *
 * Intuition:
 * - Calculate in-degree of all nodes.
 * - Initialize a queue with nodes having in-degree 0.
 * - While the queue is not empty:
 *     * Pop node from queue and add to topological sort.
 *     * For each neighbor, decrement in-degree by 1.
 *     * If neighbor's in-degree becomes 0, push it to the queue.
 * - Continue until all nodes are processed. The order in which nodes are added forms a valid topological sort.
 *
 * Edge Cases:
 * - Disconnected graphs must include all components by checking in-degree for all nodes.
 * - Graphs with no edges will return nodes in any order.
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes and M is the number of edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for in-degree array, O(N) for queue,
 *   O(N) for result vector.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Function to Get Topological Ordering Using Kahn's Algorithm (BFS)
// ---------------------------
vector<int> topologicalSortBFS(int N, vector<vector<int>> &adj) {
    vector<int> inDegree(N, 0);
    vector<int> topoOrder;
    queue<int> q;

    // Calculate in-degree of each node
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Push all nodes with in-degree 0 to the queue
    for (int i = 0; i < N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    // Process nodes in BFS manner
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    return topoOrder;
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

    vector<int> topoOrder = topologicalSortBFS(N, adjacencyList);

    cout << "Topological Order (BFS / Kahn's Algorithm): ";
    for (int node : topoOrder)
        cout << node << " ";
    cout << "\n";

    return 0;
}
