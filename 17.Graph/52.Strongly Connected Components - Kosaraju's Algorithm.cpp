/*
 * Problem Statement: Strongly Connected Components (Kosaraju's Algorithm)
 *
 * Given a directed graph, identify all Strongly Connected Components (SCCs).
 * An SCC is a maximal subgraph where every pair of vertices can reach each other.
 *
 * Core Concept:
 * - Perform DFS to record finishing times of nodes.
 * - Reverse all edges to get the transpose graph.
 * - Process nodes in decreasing order of finishing times on the transpose graph.
 * - Each DFS on the transposed graph identifies one SCC.
 *
 * Steps:
 * 1. Perform DFS on the original graph to fill a stack with nodes based on finishing times.
 * 2. Transpose the graph by reversing all edges.
 * 3. Initialize visited array for the transpose graph.
 * 4. While the stack is not empty:
 *    a. Pop a node.
 *    b. If not visited, perform DFS on the transpose graph starting from this node.
 *    c. All nodes visited in this DFS form one SCC.
 * 5. Count or print SCCs as needed.
 *
 * Time Complexity:
 * - O(V + E), three DFS traversals: original, transpose, and DFS on transpose.
 *
 * Space Complexity:
 * - O(V + E) for adjacency lists, O(V) for visited array and stack.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS to fill finishing times
// ---------------------------
void dfsOriginal(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) dfsOriginal(neighbor, adj, visited, st);
    }
    st.push(node); // push after finishing all descendants
}

// ---------------------------
// DFS on transposed graph to collect SCC
// ---------------------------
void dfsTranspose(int node, vector<vector<int>>& transposedAdj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for(int neighbor : transposedAdj[node]) {
        if(!visited[neighbor]) dfsTranspose(neighbor, transposedAdj, visited, component);
    }
}

// ---------------------------
// KOSARAJU'S SCC FUNCTION
// ---------------------------
vector<vector<int>> kosarajuSCC(int V, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(V, false);

    // Step 1: Fill stack with finishing times
    for(int i = 0; i < V; i++) {
        if(!visited[i]) dfsOriginal(i, adj, visited, st);
    }

    // Step 2: Transpose the graph
    vector<vector<int>> transposedAdj(V);
    for(int u = 0; u < V; u++) {
        for(int v : adj[u]) {
            transposedAdj[v].push_back(u);
        }
    }

    // Step 3: DFS on transposed graph in stack order
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> SCCs;

    while(!st.empty()) {
        int node = st.top(); st.pop();
        if(!visited[node]) {
            vector<int> component;
            dfsTranspose(node, transposedAdj, visited, component);
            SCCs.push_back(component);
        }
    }

    return SCCs;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int V = 8;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {5,7};
    adj[5] = {6};
    adj[6] = {4};
    adj[7] = {};

    vector<vector<int>> SCCs = kosarajuSCC(V, adj);

    cout << "Strongly Connected Components:\n";
    for(auto& comp : SCCs) {
        for(int node : comp) cout << node << " ";
        cout << endl;
    }

    return 0;
}
