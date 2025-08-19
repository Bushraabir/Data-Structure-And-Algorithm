/*
 * Problem Statement: Depth-First Search (DFS) Traversal in a Graph
 *
 * You are given a graph with N nodes and M edges, and a starting node S.
 * Task: Perform a DFS traversal of the graph starting from node S.
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
 * - DFS explores as far as possible along each branch before backtracking.
 * - Uses recursion (or an explicit stack) to traverse depth-first.
 * - A visited array prevents revisiting nodes and infinite loops in cyclic graphs.
 *
 * Intuition:
 * - Start from the starting node and mark it visited.
 * - For each unvisited neighbor, recursively perform DFS.
 * - Backtrack automatically via recursion once all neighbors are explored.
 *
 * Edge Cases:
 * - Disconnected graph → DFS will only cover the connected component of the starting node unless iterated over all nodes.
 * - Single node graph → DFS visits the node only.
 *
 * Time Complexity:
 * - O(N + M), as each node is visited once and each edge is checked once.
 *
 * Space Complexity:
 * - O(N) for visited array and dfs result list.
 * - O(N) recursion stack space in worst case (for skewed/deep graphs).
 * - Adjacency list uses O(N + M) space (not counted in DFS-specific complexity).
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Traversal Function
// ---------------------------
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsResult) {
    visited[node] = true;
    dfsResult.push_back(node);

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited, dfsResult);
        }
    }
}

// ---------------------------
// DFS Wrapper Function
// ---------------------------
vector<int> dfsTraversal(int N, vector<vector<int>> &adj, int start) {
    vector<bool> visited(N+1, false); // 1-based indexing
    vector<int> dfsResult;

    // Single component DFS from starting node
    dfs(start, adj, visited, dfsResult);

    // Uncomment below to handle disconnected components:
    /*
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, dfsResult);
        }
    }
    */

    return dfsResult;
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

    vector<int> dfsResult = dfsTraversal(N, adj, S);

    cout << "DFS Traversal starting from node " << S << ": ";
    for (int node : dfsResult) cout << node << " ";
    cout << "\n";

    return 0;
}
