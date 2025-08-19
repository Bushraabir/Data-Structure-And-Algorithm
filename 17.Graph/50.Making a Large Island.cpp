/*
 * Problem Statement: Making a Large Island
 *
 * Given an N x N binary grid (1 = land, 0 = water), you can change at most
 * one 0 to 1. Determine the size of the largest island (connected 1s)
 * possible after this change. Connectivity is 4-directional (up, down, left, right).
 *
 * Core Concept:
 * - Use Disjoint Set (Union-Find) to track connected components of 1s.
 * - Convert 2D grid coordinates to 1D node IDs for DSU operations.
 * - First, union all existing 1s to form initial components.
 * - Then, for each 0, consider flipping it to 1 and merging adjacent components.
 * - Track the maximum size achieved across all possibilities.
 *
 * Steps:
 * 1. Initialize DSU for all N*N cells.
 * 2. Traverse the grid:
 *    a. For each cell with 1, check 4 neighbors.
 *    b. If neighbor is 1, union current cell with neighbor in DSU.
 * 3. Initialize max_size = 0.
 * 4. Traverse the grid again:
 *    a. For each 0 cell, check its 4 neighbors.
 *    b. Collect unique ultimate parents of adjacent 1 components.
 *    c. Sum sizes of these components + 1 (for flipped cell) to get potential island size.
 *    d. Update max_size if larger.
 * 5. Consider edge case: all 1s or largest existing component.
 * 6. Return max_size.
 *
 * Time Complexity:
 * - O(N^2), since each cell is visited twice and DSU operations are nearly O(1).
 *
 * Space Complexity:
 * - O(N^2) for DSU parent/size arrays.
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
// MAKING LARGE ISLAND FUNCTION
// ---------------------------
int largestIsland(vector<vector<int>>& grid) {
    int N = grid.size();
    DisjointSet dsu(N * N);

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Step 1: Union all existing 1s
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(grid[r][c] == 1) {
                int node = r * N + c;
                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] == 1) {
                        int adjNode = nr * N + nc;
                        dsu.unite(node, adjNode);
                    }
                }
            }
        }
    }

    int max_size = 0;

    // Step 2: Try flipping each 0
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(grid[r][c] == 0) {
                int current_size = 1;
                set<int> uniqueParents;
                for(int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr >= 0 && nr < N && nc >= 0 && nc < N && grid[nr][nc] == 1) {
                        int parent = dsu.findParent(nr * N + nc);
                        uniqueParents.insert(parent);
                    }
                }
                for(int p : uniqueParents) current_size += dsu.size[p];
                max_size = max(max_size, current_size);
            }
        }
    }

    // Step 3: Edge case - all 1s or largest existing component
    for(int i = 0; i < N * N; i++) {
        int parent = dsu.findParent(i);
        max_size = max(max_size, dsu.size[parent]);
    }

    return max_size;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {1,0,1},
        {1,0,0},
        {0,1,1}
    };

    int result = largestIsland(g
