/*
 * Problem Statement: Shortest Distance in a Binary Maze
 *
 * You are given an N x M binary matrix (grid) where each cell is either 0 or 1.
 * - 1 represents a traversable cell.
 * - 0 represents a blocked cell.
 *
 * The goal is to find the shortest distance from a given source cell to a destination cell.
 * - Movement is allowed only in four directions: up, right, down, left.
 * - The distance to move from one cell to an adjacent cell is always 1.
 * - If no path exists, return -1.
 *
 * Key Observations:
 * - Since each move has the same cost (1), BFS is sufficient for shortest path calculation.
 * - Using BFS guarantees the first time we reach the destination, it's via the shortest path.
 *
 * Intuition:
 * 1. Initialize a distance matrix of size N x M with all values as a large number (INF).
 * 2. Set distance[source_row][source_col] = 0.
 * 3. Use a queue to store {distance, row, column}.
 * 4. While the queue is not empty:
 *     a. Extract the front element.
 *     b. For each of the 4 neighbors:
 *         - Check if it's within bounds.
 *         - Check if the cell value is 1.
 *         - Check if the new distance is smaller than the stored distance.
 *         - If valid, update the distance and push it to the queue.
 * 5. If destination is reached, return its distance.
 * 6. If queue empties without reaching destination, return -1.
 *
 * Time Complexity:
 * - O(N * M) because each cell is processed at most once.
 *
 * Space Complexity:
 * - O(N * M) for distance matrix.
 * - O(N * M) for queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Shortest Distance in Binary Maze
// ---------------------------
int shortestDistance(vector<vector<int>>& grid, pair<int,int> source, pair<int,int> destination) {
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> distance(N, vector<int>(M, INT_MAX));

    queue<tuple<int,int,int>> q; // {distance, row, col}
    distance[source.first][source.second] = 0;
    q.push({0, source.first, source.second});

    // Four direction vectors (up, right, down, left)
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [dist, row, col] = q.front(); q.pop();

        // Check neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Validity checks
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M
                && grid[newRow][newCol] == 1
                && dist + 1 < distance[newRow][newCol]) {

                distance[newRow][newCol] = dist + 1;
                // Check if destination is reached
                if (newRow == destination.first && newCol == destination.second)
                    return distance[newRow][newCol];

                q.push({dist + 1, newRow, newCol});
            }
        }
    }

    return -1; // Destination unreachable
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {0, 0, 1, 1}
    };

    pair<int,int> source = {0, 0};
    pair<int,int> destination = {2, 3};

    int dist = shortestDistance(grid, source, destination);

    if (dist != -1)
        cout << "Shortest distance from source to destination: " << dist << "\n";
    else
        cout << "Destination is unreachable.\n";

    return 0;
}
