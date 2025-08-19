/*
 * Problem Statement: Eventual Safe States in Directed Graph
 *
 * You are given a directed graph with N nodes represented as an adjacency list.
 * Task: Determine all "safe" nodes such that every possible path starting from
 *       that node eventually leads to a terminal node (a node with no outgoing edges).
 *
 * Example Input:
 * N = 7
 * adjacencyList = {
 *   {1, 2},    // Node 0 has edges to Node 1 and Node 2
 *   {2, 3},    // Node 1 has edges to Node 2 and Node 3
 *   {5},       // Node 2 has an edge to Node 5
 *   {0, 4},    // Node 3 has edges to Node 0 and Node 4
 *   {5},       // Node 4 has an edge to Node 5
 *   {},        // Node 5 is terminal
 *   {}         // Node 6 is terminal
 * }
 *
 * Key Observations:
 * - Nodes that are part of a cycle or lead to a cycle are unsafe.
 * - Nodes from which all paths eventually lead to terminal nodes are safe.
 * - Use three arrays:
 *     * visited: tracks all visited nodes
 *     * pathVisited: tracks nodes in the current recursion stack
 *     * safeState (check): tracks final safe (1) or unsafe (0) status of each node
 *
 * Intuition:
 * - Initialize visited, pathVisited as false and safeState as 0 for all nodes.
 * - For each unvisited node, perform DFS:
 *     * Mark node as visited and pathVisited.
 *     * Assume node is unsafe (safeState = 0).
 *     * For each neighbor:
 *         - If not visited, recursively DFS. If it returns false, node is unsafe.
 *         - If visited and pathVisited, cycle detected -> node is unsafe.
 *         - If visited, pathVisited false, but neighbor is unsafe (safeState = 0) -> node is unsafe.
 *     * After exploring all neighbors, if no unsafe paths found, mark node safe (safeState = 1).
 *     * Backtrack by unmarking pathVisited.
 * - Collect all nodes with safeState = 1 and return sorted.
 *
 * Edge Cases:
 * - Disconnected graphs (multiple components) must be checked separately.
 * - Terminal nodes are trivially safe.
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
// DFS Function to Determine Safe State of a Node
// ---------------------------
bool dfsSafe(int node, vector<vector<int>> &adj, vector<bool> &visited,
             vector<bool> &pathVisited, vector<int> &safeState) {
    visited[node] = true;
    pathVisited[node] = true;
    safeState[node] = 0; // temporarily assume unsafe

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (!dfsSafe(neighbor, adj, visited, pathVisited, safeState))
                return false; // path leads to unsafe node or cycle
        } else if (pathVisited[neighbor]) {
            return false; // cycle detected
        } else if (safeState[neighbor] == 0) {
            return false; // neighbor is unsafe
        }
    }

    safeState[node] = 1;          // mark node as safe
    pathVisited[node] = false;    // backtrack
    return true;
}

// ---------------------------
// Function to Get All Eventual Safe Nodes
// ---------------------------
vector<int> eventualSafeNodes(int N, vector<vector<int>> &adj) {
    vector<bool> visited(N, false);
    vector<bool> pathVisited(N, false);
    vector<int> safeState(N, 0);
    vector<int> result;

    for (int i = 0; i < N; i++) {
        if (!visited[i])
            dfsSafe(i, adj, visited, pathVisited, safeState);
    }

    for (int i = 0; i < N; i++) {
        if (safeState[i] == 1)
            result.push_back(i);
    }

    return result;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 7;
    vector<vector<int>> adjacencyList = {
        {1, 2}, // Node 0
        {2, 3}, // Node 1
        {5},    // Node 2
        {0, 4}, // Node 3
        {5},    // Node 4
        {},     // Node 5
        {}      // Node 6
    };

    vector<int> safeNodes = eventualSafeNodes(N, adjacencyList);

    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes)
        cout << node << " ";
    cout << "\n";

    return 0;
}
