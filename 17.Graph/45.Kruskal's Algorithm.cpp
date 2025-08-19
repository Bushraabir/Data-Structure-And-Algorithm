/*
 * Problem Statement: Kruskal's Algorithm (Minimum Spanning Tree)
 *
 * Given a connected, undirected, weighted graph with 'n' nodes and 'm' edges, 
 * the goal is to find the Minimum Spanning Tree (MST). An MST connects all nodes 
 * with exactly n-1 edges such that the total weight is minimized.
 *
 * Core Concept:
 * - Greedily select edges with the smallest weight that do not form a cycle.
 * - The Disjoint Set (Union-Find) data structure is used to efficiently check 
 *   if two nodes belong to the same connected component.
 *
 * Steps:
 * 1. Collect and sort all edges by weight in ascending order.
 * 2. Initialize a Disjoint Set for all vertices.
 * 3. Iterate through sorted edges:
 *    - For edge (u, v) with weight w:
 *        a. Find ultimate parents pu = findParent(u), pv = findParent(v).
 *        b. If pu != pv (different components):
 *            - Include this edge in MST.
 *            - Union the components: unite(pu, pv).
 *        c. If pu == pv, discard edge to avoid cycles.
 * 4. Continue until n-1 edges are included in MST.
 *
 * Time Complexity:
 * - Sorting edges: O(M log M), M = number of edges.
 * - Disjoint Set operations: O(M * α), effectively constant due to path compression.
 * - Total: O(M log M)
 *
 * Space Complexity:
 * - O(V + M) for Disjoint Set arrays and storing edges.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DISJOINT SET (UNION-FIND)
// ---------------------------
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return false;

        if(rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if(rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }
};

// ---------------------------
// KRUSKAL'S MST IMPLEMENTATION
// ---------------------------
long long kruskalMST(int n, vector<tuple<int,int,int>>& edges, vector<pair<int,int>>& mstEdges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return get<2>(a) < get<2>(b);
    });

    DisjointSet dsu(n);
    long long mstWeight = 0;

    for(auto &[u, v, w] : edges) {
        if(dsu.unite(u, v)) {
            mstWeight += w;
            mstEdges.push_back({u, v});
        }
    }

    return mstWeight;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 6;
    vector<tuple<int,int,int>> edges = {
        {0,1,3}, {0,3,1}, {1,3,3}, {1,2,1}, {2,3,1}, {2,4,5}, {3,4,6}, {4,5,2}, {3,5,4}
    };

    vector<pair<int,int>> mstEdges;
    long long mstWeight = kruskalMST(n, edges, mstEdges);

    cout << "MST total weight: " << mstWeight << "\nEdges in MST:\n";
    for(auto &[u,v] : mstEdges) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}
