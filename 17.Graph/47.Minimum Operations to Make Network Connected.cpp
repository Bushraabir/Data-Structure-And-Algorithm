/*
 * Problem Statement: Minimum Operations to Make Network Connected
 *
 * Given an undirected graph with 'n' vertices and 'm' edges, determine the
 * minimum number of operations required to make the graph fully connected.
 * An operation consists of removing an existing edge and adding it between
 * any two different vertices. Only existing edges can be reused.
 *
 * Core Concept:
 * - Use the Disjoint Set (Union-Find) data structure to track connected
 *   components efficiently.
 * - Count the number of connected components and extra/redundant edges.
 * - To connect all components, we need (components - 1) edges.
 * - If the number of extra edges >= components - 1, the graph can be connected.
 *
 * Steps:
 * 1. Initialize a Disjoint Set for all vertices (0 to n-1).
 * 2. Process all edges:
 *    - For each edge (u, v):
 *        a. If findParent(u) == findParent(v), it is a redundant edge; increment extra_edges.
 *        b. Else, unite(u, v) to merge components.
 * 3. Count unique connected components by checking ultimate parents.
 * 4. Compute required edges: required = components - 1.
 * 5. If extra_edges >= required, return required; else return -1.
 *
 * Time Complexity:
 * - O(M * α) for processing M edges with Union-Find (effectively constant time).
 *
 * Space Complexity:
 * - O(N) for parent and rank arrays.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DISJOINT SET (UNION-FIND)
// ---------------------------
struct DisjointSet {
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false; // redundant edge

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

// ---------------------------
// MINIMUM OPERATIONS FUNCTION
// ---------------------------
int makeConnected(int n, vector<pair<int,int>>& edges) {
    DisjointSet dsu(n);
    int extra_edges = 0;

    for(auto &[u, v] : edges) {
        if(!dsu.unite(u, v)) extra_edges++;
    }

    int components = 0;
    for(int i = 0; i < n; i++) {
        if(dsu.findParent(i) == i) components++;
    }

    int required = components - 1;
    return extra_edges >= required ? required : -1;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 6;
    vector<pair<int,int>> edges = {{0,1},{0,2},{0,3},{1,2},{1,3},{4,5}};

    int minOperations = makeConnected(n, edges);
    if(minOperations != -1)
        cout << "Minimum operations to connect the network: " << minOperations << endl;
    else
        cout << "Not enough extra edges to connect the network. Answer: -1" << endl;

    return 0;
}
