/*
 * Problem Statement: Distance of Nearest Cell having 1 in a 0/1 Matrix
 *
 * You are given a binary grid of size N x M containing only 0s and 1s.
 * Task: For each cell, find the distance to the nearest cell containing 1.
 *
 * Example Input:
 * grid = {
 *   {0, 0, 0},
 *   {0, 1, 0},
 *   {0, 0, 0}
 * }
 *
 * Key Observations:
 * - Distance is measured as Manhattan distance: |r1 - r2| + |c1 - c2|.
 * - BFS is ideal because it explores level by level, guaranteeing the minimum distance.
 * - Multi-source BFS can be used by starting from all cells containing 1.
 *
 * Intuition:
 * - Initialize a visited matrix of size N x M.
 * - Initialize a distance matrix of size N x M.
 * - Enqueue all cells containing 1 with distance 0 and mark them visited.
 * - Perform BFS:
 *   * For each dequeued cell (row, col, steps):
 *       - Set distance[row][col] = steps.
 *       - Explore four neighbors (up, right, down, left).
 *       - If a neighbor is valid and unvisited, mark it visited and enqueue with steps + 1.
 * - Return the distance matrix after BFS completes.
 *
 * Edge Cases:
 * - Grid may have multiple disconnected 0 regions.
 * - Cells already containing 1 → distance 0.
 *
 * Time Complexity:
 * - O(N*M), since each cell is visited once and four neighbors are checked.
 *
 * Space Complexity:
 * - O(N*M) for visited matrix, distance matrix, and BFS queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Function for Distance Calculation
// ---------------------------
vector<vector<int>> nearestCellDistance(vector<vector<int>> &grid) {
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> distance(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<tuple<int,int,int>> q; // {row, col, steps}

    // Initialize queue with all 1 cells
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j, 0});
                visited[i][j] = 1;
                distance[i][j] = 0;
            }
        }
    }

    int del_row[] = {-1, 0, 1, 0};
    int del_col[] = {0, 1, 0, -1};

    // BFS traversal
    while (!q.empty()) {
        auto [row, col, steps] = q.front(); q.pop();
        distance[row][col] = steps;

        for (int k = 0; k < 4; k++) {
            int new_row = row + del_row[k];
            int new_col = col + del_col[k];

            if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < M
                && !visited[new_row][new_col]) {
                visited[new_row][new_col] = 1;
                q.push({new_row, new_col, steps + 1});
            }
        }
    }

    return distance;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> dist = nearestCellDistance(grid);

    cout << "Distance Matrix:\n";
    for (auto &row : dist) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
