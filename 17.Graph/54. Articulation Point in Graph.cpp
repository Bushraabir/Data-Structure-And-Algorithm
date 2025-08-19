/*
 * Problem Statement: Articulation Points in Graph (Tarjan's Algorithm)
 *
 * Given an undirected graph, identify all articulation points (cut vertices).
 * An articulation point is a vertex whose removal increases the number of connected components.
 *
 * Core Concept:
 * - Use DFS to assign each node a "time of insertion" and "lowest reachable time".
 * - During DFS, update the lowest reachable time of a node using its children and back-edges.
 * - A node u is an articulation point if:
 *     1. u is the root of DFS and has more than one child.
 *     2. u is not the root and there exists a child v such that low[v] >= tin[u].
 *
 * Steps:
 * 1. Initialize visited array, tin array, low array, mark array, and timer = 0.
 * 2. For each unvisited node u, perform DFS:
 *    a. Mark u as visited, set tin[u] = low[u] = timer++, initialize child count = 0.
 *    b. For each adjacent node v:
 *       i. If v is parent, skip it.
 *       ii. If v is unvisited:
 *           - Increment child count.
 *           - DFS(v, u), then update low[u] = min(low[u], low[v]).
 *           - If parent != -1 and low[v] >= tin[u], mark u as articulation point.
 *       iii. If v is visited and not parent, update low[u] = min(low[u], tin[v]).
 *    c. After visiting all children, if parent == -1 and child count > 1, mark u as articulation point.
 * 3. Collect all nodes marked as articulation points.
 *
 * Time Complexity:
 * - O(V + E), single DFS traversal.
 *
 * Space Complexity:
 * - O(V + E) for adjacency list, O(V) for visited, tin, low, and mark arrays.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS to find articulation points
// ---------------------------
void dfsAP(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<bool>& mark, int& timer) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    int child = 0;

    for(int v : adj[u]) {
        if(v == parent) continue;
        if(!visited[v]) {
            child++;
            dfsAP(v, u, adj, tin, low, visited, mark, timer);
            low[u] = min(low[u], low[v]);
            if(parent != -1 && low[v] >= tin[u]) mark[u] = true;
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }

    if(parent == -1 && child > 1) mark[u] = true;
}

// ---------------------------
// ARTICULATION POINTS FUNCTION
// ---------------------------
vector<int> findArticulationPoints(int V, vector<vector<int>>& adj) {
    vector<int> tin(V, -1), low(V, -1);
    vector<bool> visited(V, false), mark(V, false);
    int timer = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) dfsAP(i, -1, adj, tin, low, visited, mark, timer);
    }

    vector<int> articulationPoints;
    for(int i = 0; i < V; i++) {
        if(mark[i]) articulationPoints.push_back(i);
    }

    return articulationPoints;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4};
    adj[4] = {3};

    vector<int> articulationPoints = findArticulationPoints(V, adj);

    cout << "Articulation points in the graph:\n";
    for(int node : articulationPoints) cout << node << " ";
    cout << endl;

    return 0;
}
