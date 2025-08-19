/*
 * Problem Statement: Number of Distinct Islands
 *
 * You are given a binary matrix of size N x M containing 0s (sea) and 1s (land).
 * Task: Count the number of distinct island shapes. Two islands are considered the same
 *       if their shapes are identical in relative coordinates, without any rotation or reflection.
 *
 * Example Input:
 * grid = {
 *   {1, 1, 0, 0},
 *   {1, 0, 0, 0},
 *   {0, 0, 1, 1},
 *   {0, 0, 1, 0}
 * }
 *
 * Key Observations:
 * - An island is a group of connected land cells (1s) in four directions.
 * - Two islands are distinct if their relative shapes differ.
 * - Store relative coordinates (base cell as origin) to identify identical shapes.
 *
 * Intuition:
 * - Initialize a visited matrix of size N x M.
 * - For each unvisited land cell, perform DFS to explore the island.
 * - Record relative coordinates of all cells in the island w.r.t the base cell.
 * - Insert the vector of relative coordinates into a set to track distinct islands.
 * - The size of the set gives the number of distinct islands.
 *
 * Edge Cases:
 * - Single row or single column grids.
 * - Grids with no land cells or all land cells forming one island.
 *
 * Time Complexity:
 * - O(N*M*log(N*M)) due to DFS traversal and inserting normalized shapes into a set.
 *
 * Space Complexity:
 * - O(N*M) for visited matrix, recursion stack, and set of island shapes.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function to Explore an Island
// ---------------------------
void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited,
         vector<pair<int,int>> &shape, int base_row, int base_col) {
    visited[row][col] = 1;
    shape.push_back({row - base_row, col - base_col}); // store relative coordinate

    int del_row[] = {-1, 0, 1, 0};
    int del_col[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int new_r = row + del_row[k];
        int new_c = col + del_col[k];

        if (new_r >= 0 && new_r < grid.size() && new_c >= 0 && new_c < grid[0].size()
            && grid[new_r][new_c] == 1 && !visited[new_r][new_c]) {
            dfs(new_r, new_c, grid, visited, shape, base_row, base_col);
        }
    }
}

// ---------------------------
// Function to Count Distinct Islands
// ---------------------------
int countDistinctIslands(vector<vector<int>> &grid) {
    int N = grid.size();
    if (N == 0) return 0;
    int M = grid[0].size();

    vector<vector<int>> visited(N, vector<int>(M, 0));
    set<vector<pair<int,int>>> distinctIslands;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                vector<pair<int,int>> shape;
                dfs(i, j, grid, visited, shape, i, j);
                distinctIslands.insert(shape);
            }
        }
    }

    return distinctIslands.size();
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
    };

    int numDistinct = countDistinctIslands(grid);
    cout << "Number of Distinct Islands: " << numDistinct << "\n";

    return 0;
}
