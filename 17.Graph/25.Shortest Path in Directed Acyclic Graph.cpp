/*
 * Problem Statement: Shortest Path in a Directed Acyclic Graph (DAG) Using Topological Sort
 *
 * You are given a weighted Directed Acyclic Graph (DAG) with N nodes (0-indexed)
 * represented as an adjacency list where each edge has a weight.
 *
 * Task: Find the shortest path from a given source node to all other nodes using
 *       topological sort and edge relaxation.
 *
 * Key Observations:
 * - DAGs have no cycles, allowing a linear ordering of nodes via topological sort.
 * - Processing nodes in topological order ensures that all shortest paths to a node
 *   are already computed when we relax its outgoing edges.
 * - Traditional shortest path algorithms (like Dijkstra) are not needed; a single
 *   pass over nodes in topo order is sufficient.
 *
 * Intuition:
 * 1. Perform a DFS-based topological sort to order nodes.
 * 2. Initialize a distance array with INF (or a large number) for all nodes.
 *    Set distance[source] = 0.
 * 3. Process nodes in topological order:
 *     - For each node u, relax edges to its neighbors v:
 *         if distance[u] + weight(u,v) < distance[v], update distance[v].
 * 4. After all nodes are processed, distance array contains shortest paths from source.
 *
 * Time Complexity:
 * - O(N + M), where N is number of nodes and M is number of edges (DFS + edge relaxation).
 *
 * Space Complexity:
 * - O(N + M) for adjacency list, O(N) for visited array, stack, and distance array.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS for Topological Sort
// ---------------------------
void topoSortDFS(int node, vector<vector<pair<int,int>>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto &edge : adj[node]) {
        int neighbor = edge.first;
        if (!visited[neighbor]) {
            topoSortDFS(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

// ---------------------------
// Shortest Path in DAG
// ---------------------------
vector<int> shortestPathDAG(int N, vector<vector<pair<int,int>>> &adj, int source) {
    vector<bool> visited(N, false);
    stack<int> st;

    // Step 1: Topological sort
    for (int i = 0; i < N; i++) {
        if (!visited[i]) topoSortDFS(i, adj, visited, st);
    }

    // Step 2: Initialize distances
    vector<int> distance(N, INT_MAX);
    distance[source] = 0;

    // Step 3: Process nodes in topo order
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (distance[u] != INT_MAX) {
            for (auto &edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                if (distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }
    }

    return distance;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    int N = 7;
    vector<vector<pair<int,int>>> adj(N);

    // Graph edges: {neighbor, weight}
    adj[0] = {{1,2}, {2,4}};
    adj[1] = {{3,1}};
    adj[2] = {{3,3}};
    adj[3] = {{4,2}};
    adj[4] = {{5,1}, {6,3}};
    adj[5] = {};
    adj[6] = {};

    int source = 0;
    vector<int> distances = shortestPathDAG(N, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < N; i++) {
        if (distances[i] == INT_MAX) cout << "INF ";
        else cout << distances[i] << " ";
    }
    cout << "\n";

    return 0;
}
