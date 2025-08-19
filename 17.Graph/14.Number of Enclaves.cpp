/*
 * Problem Statement: Number of Enclaves
 *
 * You are given a binary matrix of size N x M containing 0s (sea) and 1s (land).
 * Task: Count the number of land cells (1s) that cannot reach the boundary of the grid.
 *
 * Example Input:
 * grid = {
 *   {0, 0, 0, 0},
 *   {1, 0, 1, 0},
 *   {0, 1, 1, 0},
 *   {0, 0, 0, 0}
 * }
 *
 * Key Observations:
 * - Any land cell (1) on the boundary, or connected to a boundary land cell, is not an enclave.
 * - The algorithm focuses on marking boundary-connected land cells using BFS.
 *
 * Intuition:
 * - Initialize a visited matrix of size N x M.
 * - Enqueue all boundary land cells and mark them visited.
 * - Perform BFS to mark all land cells connected to boundaries.
 * - Iterate over the entire grid and count land cells that are unvisited (enclaves).
 *
 * Edge Cases:
 * - Single row or single column grids.
 * - Grids with no land cells or completely filled with land cells.
 *
 * Time Complexity:
 * - O(N*M), as each cell is visited at most once during BFS and final iteration.
 *
 * Space Complexity:
 * - O(N*M) for visited matrix and BFS queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Function to Mark Boundary-Connected Land Cells
// ---------------------------
void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int N, int M) {
    queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    int del_row[] = {-1, 0, 1, 0};
    int del_col[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int new_r = r + del_row[k];
            int new_c = c + del_col[k];

            if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < M
                && grid[new_r][new_c] == 1 && !visited[new_r][new_c]) {
                visited[new_r][new_c] = 1;
                q.push({new_r, new_c});
            }
        }
    }
}

// ---------------------------
// Function to Count Enclaves
// ---------------------------
int numEnclaves(vector<vector<int>> &grid) {
    int N = grid.size();
    if (N == 0) return 0;
    int M = grid[0].size();

    vector<vector<int>> visited(N, vector<int>(M, 0));

    // BFS from all boundary land cells
    for (int j = 0; j < M; j++) {
        if (grid[0][j] == 1 && !visited[0][j]) bfs(0, j, grid, visited, N, M);
        if (grid[N-1][j] == 1 && !visited[N-1][j]) bfs(N-1, j, grid, visited, N, M);
    }
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == 1 && !visited[i][0]) bfs(i, 0, grid, visited, N, M);
        if (grid[i][M-1] == 1 && !visited[i][M-1]) bfs(i, M-1, grid, visited, N, M);
    }

    // Count unvisited land cells (enclaves)
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1 && !visited[i][j])
                count++;
        }
    }

    return count;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int enclaves = numEnclaves(grid);
    cout << "Number of Enclaves: " << enclaves << "\n";

    return 0;
}
