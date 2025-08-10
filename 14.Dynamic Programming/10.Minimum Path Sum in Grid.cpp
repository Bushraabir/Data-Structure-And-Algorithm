/*
Problem Statement:
- You are at the top-left corner (0, 0) of an m x n grid.
- You want to reach the bottom-right corner (m-1, n-1).
- You can only move either RIGHT or DOWN at any step.
- Each cell contains a cost, and you want to minimize the sum of costs along your path.
- Return the minimum path sum from (0, 0) to (m-1, n-1).

Example:
Input Grid (3x3):
1  3  1
1  5  1
4  2  1

Paths:
- One possible path: 1 -> 3 -> 1 -> 1 -> 1 = 7
- Another path: 1 -> 1 -> 5 -> 1 -> 1 = 9
Answer: 7

Why This is a DP Problem:
- The problem has optimal substructure: the minimal cost to reach (i, j) depends on minimal costs to reach (i-1, j) and (i, j-1).
- Overlapping subproblems: many paths share common subpaths.
- Define f(i, j) = minimum path sum from (0, 0) to (i, j).

Recurrence:
If (i == 0 && j == 0):
    f(i, j) = grid[i][j]  // start cell cost
If (i < 0 || j < 0):
    f(i, j) = INT_MAX     // invalid path, ignore in min

Otherwise:
    f(i, j) = grid[i][j] + min(f(i-1, j), f(i, j-1))

Initial Call (top-down): f(m-1, n-1)

Time Complexity:
- Memoization/Tabulation: O(m * n)
- Pure recursion: Exponential (inefficient)

Space Complexity:
- Memoization: O(m * n) + recursion stack O(m+n)
- Tabulation: O(m * n)
- Space optimized: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
int minPathSumMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return INT_MAX;
    if (i == 0 && j == 0) return grid[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int up = minPathSumMemo(i - 1, j, grid, dp);
    int left = minPathSumMemo(i, j - 1, grid, dp);

    return dp[i][j] = grid[i][j] + min(up, left);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int minPathSumTab(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;

            int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
            int left = (j > 0) ? dp[i][j - 1] : INT_MAX;

            dp[i][j] = grid[i][j] + min(up, left);
        }
    }
    return dp[m - 1][n - 1];
}

/* -------------------- SPACE OPTIMIZED (O(n) extra space) -------------------- */
int minPathSumSpaceOpt(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, INT_MAX);
    prev[0] = grid[0][0];

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, INT_MAX);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                curr[j] = grid[i][j];
                continue;
            }

            int up = (i > 0) ? prev[j] : INT_MAX;
            int left = (j > 0) ? curr[j - 1] : INT_MAX;

            curr[j] = grid[i][j] + min(up, left);
        }
        prev = curr;
    }
    return prev[n - 1];
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    // Memoization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Minimum Path Sum (Memoization): " << minPathSumMemo(m - 1, n - 1, grid, dp) << "\n";

    // Tabulation
    cout << "Minimum Path Sum (Tabulation): " << minPathSumTab(grid) << "\n";

    // Space Optimized
    cout << "Minimum Path Sum (Space Optimized): " << minPathSumSpaceOpt(grid) << "\n";

    return 0;
}
