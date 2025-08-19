/*
 * Problem Statement: Path With Minimum Effort
 *
 * You are given a 2D grid 'heights' of size N x M, where heights[row][col] represents
 * the height of that cell. You need to find a path from the top-left cell (0,0) to the
 * bottom-right cell (N-1, M-1) such that the maximum absolute difference in heights
 * between consecutive cells along the path (effort) is minimized.
 *
 * Movement is allowed in four directions: up, right, down, left.
 *
 * Key Observations:
 * - The effort of a path is defined as the maximum absolute height difference
 *   between consecutive cells along the path.
 * - Dijkstra's algorithm can be applied because we want the minimum "maximum effort".
 *
 * Intuition:
 * 1. Initialize a 2D array 'effort' of size N x M with all values as INF.
 * 2. Set effort[0][0] = 0 (starting cell requires 0 effort).
 * 3. Use a min-priority queue to store {current_effort, row, col}.
 * 4. While the queue is not empty:
 *     a. Extract the top element (minimum effort).
 *     b. For each of the 4 neighbors:
 *         - Check if it's within bounds.
 *         - Calculate abs_diff = abs(heights[new_row][new_col] - heights[row][col]).
 *         - new_effort = max(current_effort, abs_diff).
 *         - If new_effort < effort[new_row][new_col], update and push to queue.
 * 5. When destination (N-1, M-1) is extracted from the queue, return its effort.
 *
 * Time Complexity:
 * - O(N*M*log(N*M)) due to Dijkstra's with priority queue.
 *
 * Space Complexity:
 * - O(N*M) for effort array.
 * - O(N*M) for priority queue in worst case.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Path With Minimum Effort
// ---------------------------
int minimumEffortPath(vector<vector<int>>& heights) {
    int N = heights.size();
    int M = heights[0].size();
    vector<vector<int>> effort(N, vector<int>(M, INT_MAX));
    
    // Min-priority queue: {effort, row, col}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    effort[0][0] = 0;
    pq.push({0, 0, 0});
    
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    
    while (!pq.empty()) {
        auto [currEffort, row, col] = pq.top(); pq.pop();
        
        // Destination reached
        if (row == N-1 && col == M-1) return currEffort;
        
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];
            
            if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                int absDiff = abs(heigh
