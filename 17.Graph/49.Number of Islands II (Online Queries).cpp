/*
 * Problem Statement: Number of Islands II (Online Queries)
 *
 * Given an initially empty grid (all water), process a list of queries where
 * each query adds land at a specific coordinate. After each query, return
 * the current number of islands in the grid. Islands are formed by
 * connecting adjacent lands (up, down, left, right) and diagonals are ignored.
 *
 * Core Concept:
 * - Use Disjoint Set (Union-Find) to dynamically track connected components
 *   of land cells.
 * - Convert 2D grid coordinates to 1D node IDs to manage DSU efficiently.
 * - For each new land, check its four neighbors and union if they are land.
 * - Adjust the island count as components merge.
 *
 * Steps:
 * 1. Initialize DSU for all R * C grid cells.
 * 2. Maintain a visited array to mark land positions.
 * 3. For each query (row, col):
 *    a. If already land, append current island count.
 *    b. Else, mark as land and increment island count.
 *    c. For each of the 4 neighbors:
 *        i. Check bounds and if neighbor is land.
 *        ii. If neighbor belongs to a different component, union them and
 *            decrement island count.
 *    d. Append current island count to result.
 *
 * Time Complexity:
 * - O(Q * α), Q = number of queries, α = inverse Ackermann function
 *   (effectively constant) due to DSU operations.
 *
 * Space Complexity:
 * - O(R * C) for DSU parent/size arrays and visited array.
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
// NUMBER OF ISLANDS II FUNCTION
// ---------------------------
vector<int> numIslands2(int R, int C, vector<pair<int,int>>& positions) {
    DisjointSet dsu(R * C);
    vector<int> res;
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    int count = 0;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    for(auto &[r, c] : positions) {
        if(visited[r][c]) {
            res.push_back(count);
            continue;
        }
        visited[r][c] = true;
        count++;
        int node = r * C + c;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < R && nc >= 0 && nc < C && visited[nr][nc]) {
                int adjNode = nr * C + nc;
                if(dsu.unite(node, adjNode)) count--;
            }
        }
        res.push_back(count);
    }

    return res;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    int R = 3, C = 3;
    vector<pair<int,int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}, {1,1}};

    vector<int> islandsCount = numIslands2(R, C, positions);

    cout << "Number of Islands after each query:\n";
    for(int count : islandsCount) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
