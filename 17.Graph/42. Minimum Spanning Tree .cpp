/*
 * Problem Statement: Minimum Spanning Tree (MST)
 *
 * You are given an undirected weighted graph with 'n' nodes numbered from 0 to n-1
 * and a list of edges. Each edge is represented as [u, v, wt], indicating an edge
 * between u and v with weight wt. The goal is to construct a spanning tree that
 * connects all nodes using exactly n-1 edges and has the minimum total sum of edge weights.
 *
 * Key Observations:
 * - A spanning tree is a connected acyclic subgraph containing all n nodes.
 * - The MST is the spanning tree with the minimum total edge weight.
 * - A graph can have multiple spanning trees, but MST ensures the total weight is minimum.
 * - Algorithms like Prim's or Kruskal's are used to efficiently compute MSTs.
 *
 * Intuition (Kruskal's Algorithm Example):
 * 1. Sort all edges based on their weights in non-decreasing order.
 * 2. Initialize a disjoint set (Union-Find) to keep track of connected components.
 * 3. Iterate over sorted edges:
 *     a. If the edge connects two different components (i.e., does not form a cycle):
 *         i. Include the edge in the MST.
 *         ii. Union the two components.
 * 4. Repeat until n-1 edges are added to the MST.
 * 5. Return the list of edges in the MST and/or its total weight.
 *
 * Time Complexity:
 * - O(E log E) due to sorting the edges, where E = number of edges.
 * - Union-Find operations are nearly O(1) on average with path compression.
 *
 * Space Complexity:
 * - O(V) for storing parent/rank arrays in Union-Find, where V = number of nodes.
 * - O(E) for storing edges.
 */

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) with path compression
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

// ---------------------------
// KRUSKAL'S MST IMPLEMENTATION
// ---------------------------
long long kruskalMST(int n, vector<tuple<int,int,int>>& edges, vector<tuple<int,int,int>>& mstEdges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return get<2>(a) < get<2>(b);
    });

    DSU dsu(n);
    long long totalWeight = 0;

    for (auto &[u,v,wt] : edges) {
        if (dsu.unite(u,v)) { // if edge connects two different components
            mstEdges.push_back({u,v,wt});
            totalWeight += wt;
        }
    }

    return totalWeight;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int n = 4;
    vector<tuple<int,int,int>> edges = {
        {0,1,3},
        {0,2,6},
        {1,2,4},
        {1,3,4},
        {2,3,2}
    };

    vector<tuple<int,int,int>> mstEdges;
    long long mstWeight = kruskalMST(n, edges, mstEdges);

    cout << "MST total weight: " << mstWeight << "\nEdges in MST:\n";
    for (auto &[u,v,wt] : mstEdges) {
        cout << u << " - " << v << " : " << wt << "\n";
    }

    return 0;
}
