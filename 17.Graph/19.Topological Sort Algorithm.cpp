/*
 * Problem Statement: Topological Sorting Using DFS
 *
 * You are given a directed acyclic graph (DAG) with N nodes represented as an adjacency list.
 * Task: Find a valid linear ordering of nodes such that for every directed edge u -> v,
 *       node u appears before node v in the ordering.
 *
 * Example Input:
 * N = 6
 * adjacencyList = {
 *   {0},       // Node 5 has an edge to Node 0
 *   {0},       // Node 4 has an edge to Node 0
 *   {3},       // Node 5 has an edge to Node 2
 *   {1},       // Node 2 has an edge to Node 3
 *   {1},       // Node 4 has an edge to Node 1
 *   {}         // Node 3 has no outgoing edges
 * }
 *
 * Key Observations:
 * - Topological sort is only possible for DAGs.
 * - A node u must appear before node v if an edge u -> v exists.
 * - DFS can be used to traverse nodes, and a stack can record the finish order.
 *
 * Intuition:
 * - Initialize visited array of size N as false and an empty stack.
 * - For each unvisited node, perform DFS:
 *     * Mark node as visited.
 *     * For each neighbor, recursively DFS if not visited.
 *     * After visiting all neighbors, push current node onto stack.
 * - After DFS completes for all nodes, pop elements from stack to get topological order.
 *
 * Edge Cases:
 * - Disconnected graphs must have DFS called on all components.
 * - Graphs with no edges will simply return nodes in any order.
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes and M is the number of edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for visited array, O(N) for recursion stack,
 *   O(N) for stack to store topological order.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function for Topological Sorting
// ---------------------------
void dfsTopo(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsTopo(neighbor, adj, visited, st);
        }
    }

    st.push(node); // push after visiting all neighbors
}

// ---------------------------
// Function to Get Topological Ordering
// ---------------------------
vector<int> topologicalSort(int N, vector<vector<int>> &adj) {
    vector<bool> visited(N, false);
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < N; i++) {
        if (!visited[i])
            dfsTopo(i, adj, visited, st);
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
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

    vector<int> topoOrder = topologicalSort(N, adjacencyList);

    cout << "Topological Order: ";
    for (int node : topoOrder)
        cout << node << " ";
    cout << "\n";

    return 0;
}
