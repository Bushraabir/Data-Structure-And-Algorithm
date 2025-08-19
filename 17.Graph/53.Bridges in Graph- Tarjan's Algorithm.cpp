/*
 * Problem Statement: Bridges in Graph (Tarjan's Algorithm)
 *
 * Given an undirected graph, identify all bridges (critical edges).
 * A bridge is an edge whose removal increases the number of connected components.
 *
 * Core Concept:
 * - Use DFS to assign each node a "time of insertion" and "lowest reachable time".
 * - During DFS, update the lowest reachable time of a node using its children and back-edges.
 * - An edge (u, v) is a bridge if low[v] > time[u], meaning v (and its subtree) cannot reach u or its ancestors through any other path.
 *
 * Steps:
 * 1. Initialize visited array, time array, low array, and a timer = 0.
 * 2. For each unvisited node u, perform DFS:
 *    a. Mark u as visited and set time[u] = low[u] = timer++.
 *    b. For each adjacent node v:
 *       i. If v is parent of u, ignore it.
 *       ii. If v is unvisited, DFS(v, u), then update low[u] = min(low[u], low[v]).
 *           - If low[v] > time[u], (u, v) is a bridge.
 *       iii. If v is visited and not parent, update low[u] = min(low[u], time[v]).
 * 3. Collect all bridges found during DFS.
 *
 * Time Complexity:
 * - O(V + E), single DFS traversal.
 *
 * Space Complexity:
 * - O(V + E) for adjacency list, O(V) for visited, time, and low arrays.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS to find bridges
// ---------------------------
void dfsBridge(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<bool>& visited, int& timer, vector<pair<int,int>>& bridges) {
    visited[u] = true;
    tin[u] = low[u] = timer++;
    
    for(int v : adj[u]) {
        if(v == parent) continue;
        if(!visited[v]) {
            dfsBridge(v, u, adj, tin, low, visited, timer, bridges);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) {
                bridges.push_back({u, v});
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
}

// ---------------------------
// BRIDGES FUNCTION
// ---------------------------
vector<pair<int,int>> findBridges(int V, vector<vector<int>>& adj) {
    vector<int> tin(V, -1), low(V, -1);
    vector<bool> visited(V, false);
    vector<pair<int,int>> bridges;
    int timer = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfsBridge(i, -1, adj, tin, low, visited, timer, bridges);
        }
    }

    return bridges;
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

    vector<pair<int,int>> bridges = findBridges(V, adj);

    cout << "Bridges in the graph:\n";
    for(auto& e : bridges) {
        cout << e.first << " - " << e.second << endl;
    }

    return 0;
}
