/*
 * Problem Statement: Maximum Stone Removal
 *
 * Given N stones on a 2D plane at distinct integer coordinates, you can remove a stone
 * only if it shares a row or a column with another stone that has not yet been removed.
 * Determine the maximum number of stones that can be removed.
 *
 * Core Concept:
 * - Treat stones as nodes and rows/columns as connections to form connected components.
 * - Use Disjoint Set (Union-Find) to efficiently merge stones sharing a row or column.
 * - The maximum stones removable from a component = size of component - 1.
 * - Total removable stones = N - number of connected components.
 *
 * Steps:
 * 1. Determine the maximum row and column indices among all stones.
 * 2. Initialize DSU for (maxRow + maxCol + 2) nodes to account for all rows and columns.
 * 3. For each stone (r, c):
 *    a. Map row r to node r.
 *    b. Map column c to node (maxRow + 1 + c) to avoid overlap with row nodes.
 *    c. Unite row node and column node in DSU.
 * 4. Collect unique ultimate parents of nodes involved in stones to count connected components.
 * 5. Return N - number of connected components.
 *
 * Time Complexity:
 * - O(N * α), N = number of stones, α = inverse Ackermann function (almost constant)
 *
 * Space Complexity:
 * - O(maxRow + maxCol + 2) for DSU parent/size arrays.
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
        if(pu == pv) return false;

        if(size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

// ---------------------------
// MAX STONE REMOVAL FUNCTION
// ---------------------------
int removeStones(vector<pair<int,int>>& stones) {
    int maxRow = 0, maxCol = 0;
    for(auto &[r,c] : stones) {
        maxRow = max(maxRow, r);
        maxCol = max(maxCol, c);
    }

    DisjointSet dsu(maxRow + maxCol + 2);

    // Step 1: Connect stones via rows and columns
    for(auto &[r,c] : stones) {
        int rowNode = r;
        int colNode = maxRow + 1 + c; // Shift column node to avoid overlap
        dsu.unite(rowNode, colNode);
    }

    // Step 2: Count unique connected components
    set<int> components;
    for(auto &[r,c] : stones) {
        int parent = dsu.findParent(r);
        components.insert(parent);
    }

    // Step 3: Maximum stones removable = N - number of components
    return stones.size() - components.size();
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<pair<int,int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

    int maxRemovable = removeStones(stones);
    cout << "Maximum stones that can be removed: " << maxRemovable << endl;

    return 0;
}
