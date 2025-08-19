/*
 * Problem Statement: Detect Cycle in Directed Graph
 *
 * You are given a directed graph with N nodes represented as an adjacency list.
 * Task: Determine if the graph contains a cycle.
 *
 * Example Input:
 * N = 4
 * adjacencyList = {
 *   {1},    // Node 0 has an edge to Node 1
 *   {2},    // Node 1 has an edge to Node 2
 *   {3},    // Node 2 has an edge to Node 3
 *   {1}     // Node 3 has an edge back to Node 1, forming a cycle
 * }
 *
 * Key Observations:
 * - In directed graphs, a cycle exists if a node is revisited "on the same path" of DFS.
 * - A visited node not in the current recursion path does not indicate a cycle.
 * - Use two arrays:
 *     * visited: tracks nodes visited in any DFS traversal
 *     * pathVisited: tracks nodes currently in the recursion stack
 *
 * Intuition:
 * - Initialize visited and pathVisited arrays of size N as false.
 * - For each unvisited node, perform DFS:
 *     * Mark node as visited and pathVisited.
 *     * For each neighbor:
 *         - If not visited, recursively DFS.
 *         - If visited and pathVisited, a cycle is detected.
 *     * After exploring all neighbors, unmark node from pathVisited.
 * - If DFS completes without detecting a cycle, graph is acyclic.
 *
 * Edge Cases:
 * - Disconnected graphs (multiple components) must be checked separately.
 * - Graphs with no edges are trivially acyclic.
 *
 * Time Complexity:
 * - O(N + M), where N is the number of nodes and M is the number of edges.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for visited arrays, O(N) for recursion stack.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function to Detect Cycle from a Node
// ---------------------------
bool dfsCycle(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited) {
    visited[node] = true;
    pathVisited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycle(neighbor, adj, visited, pathVisited))
                return true;
        } else if (pathVisited[neighbor]) {
            return true; // cycle detected
        }
    }

    pathVisited[node] = false; // backtrack
    return false;
}

// ---------------------------
// Function to Check if Graph Has a Cycle
// ---------------------------
bool hasCycle(int N, vector<vector<int>> &adj) {
    vector<bool> visited(N, false);
    vector<bool> pathVisited(N, false);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (dfsCycle(i, adj, visited, pathVisited))
                return true;
        }
    }

    return false;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 4;
    vector<vector<int>> adjacencyList = {
        {1}, // Node 0
        {2}, // Node 1
        {3}, // Node 2
        {1}  // Node 3
    };

    if (hasCycle(N, adjacencyList))
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph is acyclic\n";

    return 0;
}
