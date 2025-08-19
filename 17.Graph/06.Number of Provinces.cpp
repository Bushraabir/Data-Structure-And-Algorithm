/*
 * Problem Statement: Number of Provinces in an Undirected Graph
 *
 * You are given a graph with V vertices (nodes) represented either as an adjacency list or an adjacency matrix.
 * Task: Determine the number of provinces (connected components) in the graph.
 *
 * Example Input (Undirected, Unweighted):
 * V = 6
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
 * - A province is a connected component where any two nodes are connected directly or indirectly.
 * - Each DFS/BFS traversal from an unvisited node explores one complete province.
 * - Count the number of times a DFS/BFS traversal is initiated to get the number of provinces.
 *
 * Intuition:
 * - Use a visited array to mark nodes already explored.
 * - Iterate through all nodes:
 *   * If a node is unvisited, it is the start of a new province.
 *   * Increment the province count and perform DFS/BFS to mark all nodes in this province as visited.
 *
 * Edge Cases:
 * - Graph with no edges → each node is its own province.
 * - Fully connected graph → single province.
 *
 * Time Complexity:
 * - O(V + E), as each node and edge is visited at most once during the traversal.
 *
 * Space Complexity:
 * - O(V) for visited array.
 * - O(V) recursion stack in worst case (DFS).
 * - Adjacency list uses O(V + E) space (not counted in DFS-specific complexity).
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Traversal Function
// ---------------------------
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}

// ---------------------------
// Provinces Counting Function
// ---------------------------
int countProvinces(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V+1, false); // 1-based indexing
    int provinceCount = 0;

    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            provinceCount++;
            dfs(i, adj, visited);
        }
    }

    return provinceCount;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int V = 6;
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{2,5},{3,6},{5,6},{4,5}};

    // Build adjacency list
    vector<vector<int>> adj(V+1);
    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int provinces = countProvinces(V, adj);
    cout << "Number of Provinces: " << provinces << "\n";

    return 0;
}
