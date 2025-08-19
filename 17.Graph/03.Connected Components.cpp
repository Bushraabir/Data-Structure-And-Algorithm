/*
 * Problem Statement: Connected Components in an Undirected Graph
 *
 * You are given a graph with N nodes and M edges.
 * Task: Identify all connected components in the graph using a traversal algorithm (DFS or BFS).
 *
 * Example Input (Undirected, Unweighted):
 * N = 10, M = 8
 * Edges:
 * 1 2
 * 1 3
 * 2 4
 * 3 4
 * 5 6
 * 6 7
 * 5 7
 * 8 9
 *
 * Key Observations:
 * - A connected component is a set of nodes where each node is reachable from any other node in the set.
 * - Isolated nodes are also considered a single-node connected component.
 * - Multiple connected components may exist in a single graph.
 *
 * Intuition:
 * - Use a visited array to track nodes already explored.
 * - Iterate over all nodes:
 *   * If node i is unvisited, initiate DFS/BFS to mark all nodes in its component.
 * - Each DFS/BFS call starting from an unvisited node identifies one connected component.
 *
 * Edge Cases:
 * - Graph with no edges → each node is its own component.
 * - Fully connected graph → single connected component.
 *
 * Time Complexity:
 * - O(N + M), as each node and edge is visited once during traversal.
 *
 * Space Complexity:
 * - O(N + M) for adjacency list.
 * - O(N) for visited array.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Traversal Function
// ---------------------------
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component) {
    visited[node] = true;
    component.push_back(node);

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited, component);
        }
    }
}

// ---------------------------
// Connected Components Function
// ---------------------------
vector<vector<int>> connectedComponents(int N, vector<pair<int,int>> edges) {
    vector<vector<int>> adj(N+1); // 1-based indexing
    vector<bool> visited(N+1, false);

    // Build adjacency list
    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    vector<vector<int>> components;

    // Iterate all nodes to find connected components
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            components.push_back(component);
        }
    }

    return components;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 10;
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{3,4},{5,6},{6,7},{5,7},{8,9}};

    vector<vector<int>> components = connectedComponents(N, edges);

    cout << "Connected Components:\n";
    for (int i=0; i<components.size(); i++) {
        cout << "Component " << i+1 << ": ";
        for (int node : components[i]) cout << node << " ";
        cout << "\n";
    }

    return 0;
}
