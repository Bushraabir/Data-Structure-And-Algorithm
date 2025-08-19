/*
 * Problem Statement: Rotten Oranges in a 2D Grid
 *
 * You are given a 2D grid of size n x m, where each cell can be:
 * 0 → Empty cell
 * 1 → Fresh orange
 * 2 → Rotten orange
 *
 * Task: Determine the minimum time required to rot all fresh oranges. 
 * If it is impossible for all fresh oranges to rot, return -1.
 *
 * Example Input:
 * n = 3, m = 3
 * Grid:
 * 2 1 1
 * 1 1 0
 * 0 1 1
 *
 * Key Observations:
 * - A rotten orange spreads rot to its 4-directionally connected fresh neighbors in 1 unit of time.
 * - The process happens simultaneously for all rotten oranges in each time unit.
 * - BFS (level-order traversal) is ideal to simulate this simultaneous rotting process.
 *
 * Intuition:
 * - Enqueue all initially rotten oranges with time = 0.
 * - Keep track of fresh oranges count.
 * - Perform BFS:
 *   * For each rotten orange, rot its 4-directionally connected fresh neighbors.
 *   * Increment the time as BFS moves to the next level.
 * - If any fresh orange remains unrotted after BFS, return -1.
 * - Otherwise, return the maximum time taken.
 *
 * Edge Cases:
 * - No fresh oranges initially → return 0.
 * - Isolated fresh oranges that cannot be reached → return -1.
 *
 * Time Complexity:
 * - O(n * m), since each cell is visited at most once.
 *
 * Space Complexity:
 * - O(n * m) for the queue and visited array in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// BFS Function to Rot Oranges
// ---------------------------
int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<tuple<int,int,int>> q; // row, col, time
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int freshCount = 0, maxTime = 0;

    // Populate initial queue with rotten oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
                visited[i][j] = 2;
            } else if (grid[i][j] == 1) {
                freshCount++;
            } else {
                visited[i][j] = 0; // empty cell
            }
        }
    }

    int delta_row[] = {-1, 0, 1, 0}; // up, right, down, left
    int delta_col[] = {0, 1, 0, -1};

    // BFS traversal
    while (!q.empty()) {
        auto [r, c, time] = q.front(); q.pop();
        maxTime = max(maxTime, time);

        for (int i = 0; i < 4; i++) {
            int n_row = r + delta_row[i];
            int n_col = c + delta_col[i];

            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                grid[n_row][n_col] == 1 && visited[n_row][n_col] != 2) {
                freshCount--;
                visited[n_row][n_col] = 2; // mark as rotten
                q.push({n_row, n_col, time + 1});
            }
        }
    }

    return (freshCount == 0) ? maxTime : -1;
}

// ---------------------------
// MAIN FUNCTION
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);
    if (result != -1) 
        cout << "Minimum time to rot all oranges: " << result << "\n";
    else 
        cout << "Not all fresh oranges can rot. Return -1\n";

    return 0;
}
