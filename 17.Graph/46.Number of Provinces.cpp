/*
 * Problem Statement: Number of Provinces (Connected Components)
 *
 * Given an undirected graph represented as an adjacency matrix, the goal is to
 * determine the number of connected components (provinces) in the graph.
 * Each province is a group of cities such that there is a path between any two
 * cities in the same province.
 *
 * Core Concept:
 * - Use the Disjoint Set (Union-Find) data structure to efficiently track connected
 *   components.
 * - Each connected component has an "ultimate parent" or "boss" node.
 * - Counting unique ultimate parents gives the total number of provinces.
 *
 * Steps:
 * 1. Initialize a Disjoint Set for all vertices (0 to V-1).
 * 2. Iterate through the adjacency matrix:
 *    - For each adjacency[i][j] == 1:
 *        a. Perform union(i, j) to merge the connected components.
 * 3. Count unique ultimate parents:
 *    - For each node i, if findParent(i) == i, increment count.
 * 4. Return the count as the number of provinces.
 *
 * Time Complexity:
 * - O(V^2) for iterating through the adjacency matrix.
 * - Union-Find operations are effectively O(α) per operation due to path compression.
 *
 * Space Complexity:
 * - O(V) for parent and rank/size arrays.
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
        iota(parent.begin(), parent.end(), 0); // each node is its own parent
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
// NUMBER OF PROVINCES FUNCTION
// ---------------------------
int findNumberOfProvinces(vector<vector<int>>& adjacency) {
    int V = adjacency.size();
    DisjointSet dsu(V);

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(adjacency[i][j] == 1) {
                dsu.unite(i, j);
            }
        }
    }

    int count = 0;
    for(int i = 0; i < V; i++) {
        if(dsu.findParent(i) == i) count++;
    }
    return count;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<vector<int>> adjacency = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    int provinces = findNumberOfProvinces(adjacency);
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}
