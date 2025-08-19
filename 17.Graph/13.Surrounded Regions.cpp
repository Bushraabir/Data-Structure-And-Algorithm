/*
 * Problem Statement: Surrounded Regions | Replace O's with X's
 *
 * You are given a matrix of size N x M containing 'O's and 'X's.
 * Task: Replace all 'O's that are "surrounded" by 'X's with 'X's.
 *
 * Example Input:
 * grid = {
 *   {'X', 'X', 'X', 'X'},
 *   {'X', 'O', 'O', 'X'},
 *   {'X', 'X', 'O', 'X'},
 *   {'X', 'O', 'X', 'X'}
 * }
 *
 * Key Observations:
 * - An 'O' is considered "surrounded" if all adjacent cells (up, down, left, right) are 'X'.
 * - Any 'O' connected to a boundary 'O' cannot be surrounded.
 * - The algorithm focuses on marking boundary-connected 'O's as safe.
 *
 * Intuition:
 * - Initialize a visited matrix of size N x M.
 * - Perform DFS from all boundary 'O's to mark them and their connected components as visited (safe).
 * - After DFS, iterate over the entire grid:
 *     * If a cell is 'O' and not visited, it is surrounded → replace with 'X'.
 *     * If a cell is 'O' and visited, leave it as 'O'.
 * - Return the modified grid.
 *
 * Edge Cases:
 * - Boundary 'O's and their connected 'O's should not be replaced.
 * - Single row or single column grids.
 *
 * Time Complexity:
 * - O(N*M), as each cell is visited at most once during DFS and final iteration.
 *
 * Space Complexity:
 * - O(N*M) for visited matrix and recursion stack in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// DFS Function to Mark Safe 'O's
// ---------------------------
void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int N, int M) {
    visited[row][col] = 1;
    int del_row[] = {-1, 0, 1, 0};
    int del_col[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int new_row = row + del_row[k];
        int new_col = col + del_col[k];

        if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M
            && grid[new_row][new_col] == 'O' && !visited[new_row][new_col]) {
            dfs(new_row, new_col, grid, visited, N, M);
        }
    }
}

// ---------------------------
// Function to Replace Surrounded 'O's
// ---------------------------
void replaceSurrounded(vector<vector<char>> &grid) {
    int N = grid.size();
    if (N == 0) return;
    int M = grid[0].size();

    vector<vector<int>> visited(N, vector<int>(M, 0));

    // Perform DFS from boundary 'O's
    for (int j = 0; j < M; j++) {
        if (grid[0][j] == 'O' && !visited[0][j]) dfs(0, j, grid, visited, N, M);
        if (grid[N-1][j] == 'O' && !visited[N-1][j]) dfs(N-1, j, grid, visited, N, M);
    }
    for (int i = 0; i < N; i++) {
        if (grid[i][0] == 'O' && !visited[i][0]) dfs(i, 0, grid, visited, N, M);
        if (grid[i][M-1] == 'O' && !visited[i][M-1]) dfs(i, M-1, grid, visited, N, M);
    }

    // Replace unvisited 'O's with 'X's
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'O' && !visited[i][j])
                grid[i][j] = 'X';
        }
    }
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<char>> grid = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    replaceSurrounded(grid);

    cout << "Modified Grid:\n";
    for (auto &row : grid) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }

    return 0;
}
