/*
 * Problem Statement: Disjoint Set (Union-Find)
 *
 * The Disjoint Set Data Structure efficiently manages a collection of disjoint sets.
 * It is particularly useful in graph problems involving connectivity queries, such as
 * Kruskal's algorithm for finding the Minimum Spanning Tree (MST) or dynamic connectivity
 * queries in evolving graphs.
 *
 * Key Observations:
 * - Each node starts as its own parent, representing an independent set.
 * - Two main operations:
 *     1. findParent(node): Returns the ultimate parent (representative) of the node's set.
 *     2. union(u, v): Merges the sets containing nodes u and v.
 * - Optimizations:
 *     - Path Compression in findParent: Flattens the tree during find operations to speed up future queries.
 *     - Union by Rank or Union by Size: Attaches smaller trees/components under larger ones to maintain a shallow tree.
 *
 * Core Operations:
 * 1. findParent(node):
 *     - If node is its own parent, return node.
 *     - Otherwise, recursively find the ultimate parent and update parent[node] (path compression).
 *
 * 2. union(u, v):
 *     - Find ultimate parents of u and v.
 *     - If they are already in the same set, do nothing.
 *     - Otherwise, attach smaller rank/size tree to larger one.
 *
 * Time Complexity:
 * - Amortized O(α) per operation, where α is the inverse Ackermann function (practically constant).
 *
 * Space Complexity:
 * - O(V) for storing parent and rank/size arrays.
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
        iota(parent.begin(), parent.end(), 0); // Initially each node is its own parent
    }

    // Find ultimate parent with path compression
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union by rank
    bool unite(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return false; // Already in same set

        if (rank[pu] < rank[pv]) swap(pu, pv); // Attach smaller rank under larger rank
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }
};

// ---------------------------
// DRIVER CODE EXAMPLE
// ---------------------------
int main() {
    int n = 7;
    DisjointSet dsu(n);

    // Union operations
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(5, 6);

    // Connectivity queries
    cout << "0 and 2 connected? " << (dsu.findParent(0) == dsu.findParent(2) ? "Yes" : "No") << "\n";
    cout << "0 and 3 connected? " << (dsu.findParent(0) == dsu.findParent(3) ? "Yes" : "No") << "\n";

    // Merge components
    dsu.unite(2, 3);

    cout << "0 and 4 connected after union(2,3)? " 
         << (dsu.findParent(0) == dsu.findParent(4) ? "Yes" : "No") << "\n";

    return 0;
}
