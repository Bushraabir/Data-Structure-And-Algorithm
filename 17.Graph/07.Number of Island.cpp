/*
 * Problem Statement: Number of Islands in a 2D Grid
 *
 * You are given a 2D grid of size n x m, where each cell contains either:
 * 0 → Water
 * 1 → Land
 *
 * Task: Determine the total number of islands in the grid.
 * An island is defined as a group of connected land cells (1s). 
 * Cells are connected horizontally, vertically, or diagonally (8 directions).
 *
 * Example Input:
 * n = 4, m = 5
 * Grid:
 * 1 1 0 0 0
 * 0 1 0 0 1
 * 1 0 0 1 1
 * 0 0 0 0 0
 *
 * Key Observations:
 * - Each island corresponds to a connected component of land cells.
 * - BFS or DFS can be used to traverse all land cells of an island.
 * - Counting the number of times a traversal starts from an unvisited land cell gives the number of islands.
 *
 * Intuition:
 * - Use a visited 2D array to mark processed land cells.
 * - Iterate through every cell in the grid:
 *   * If the cell is land and unvisited, it is the start of a new island.
 *   * Increment the island count and perform BFS/DFS to mark all connected land cells as visited.
 *
 * Edge Cases:
 * - Grid with no land → 0 islands.
 * - Grid fully filled with land → 1 island.
 *
 * Time Complexity:
 * - O(n * m), since each cell is visited at most once.
 *
 * Space Complexity:
 * - O(n * m) for visited array.
 * - O(n * m) for BFS queue or DFS recursion stack in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Function to explore an island
// ---------------------------
void bfs(int startRow, int startCol, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    int n = grid.size();
    int m = grid[0].size();
    visited[startRow][startCol] = true;

    queue<pair<int,int>> q;
    q.push({startRow, startCol});

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Row deltas for 8 directions
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Column deltas for 8 directions

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                grid[newR][newC] == '1' && !visited[newR][newC]) {
                visited[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
}

// ---------------------------
// Function to count total islands
// ---------------------------
int countIslands(vector<vector<char>> &grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int islandCount = 0;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == '1' && !visited[r][c]) {
                islandCount++;
                bfs(r, c, grid, visited);
            }
        }
    }

    return islandCount;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'0','1','0','0','1'},
        {'1','0','0','1','1'},
        {'0','0','0','0','0'}
    };

    int totalIslands = countIslands(grid);
    cout << "Number of Islands: " << totalIslands << "\n";

    return 0;
}
