/*
Problem Statement:
- You are at the top-left corner (0, 0) of an m x n grid.
- You want to reach the bottom-right corner (m-1, n-1).
- You can only move either RIGHT or DOWN at any step.
- Some cells are blocked (represented by -1) and cannot be visited.
- Find the total number of unique paths from (0, 0) to (m-1, n-1) without stepping on blocked cells.
- Since the answer can be large, return it modulo 1e9+7.

Example:
Input Grid (3x3):
0  0  0
0 -1  0
0  0  0

Paths:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
3. Down -> Right -> Down -> Right

Answer: 3

Why This is a DP Problem:
- We count all ways to reach a cell avoiding obstacles — optimal substructure applies.
- Overlapping subproblems occur as multiple paths can lead to the same cell.
- Define f(i, j) = number of unique paths from (0, 0) to (i, j) avoiding blocked cells.

Recurrence:
If matrix[i][j] == -1 (blocked cell):
    f(i, j) = 0  // no path through blocked cell
Else if (i == 0 && j == 0):
    f(i, j) = 1  // start cell itself
Else if (i < 0 || j < 0):
    f(i, j) = 0  // out of bounds

Otherwise:
    f(i, j) = (f(i-1, j) + f(i, j-1)) % modulo  // from top + from left

Initial Call (top-down): f(m-1, n-1)

Time Complexity:
- Memoization/Tabulation: O(m * n)
- Pure recursion: Exponential (inefficient)

Space Complexity:
- Memoization: O(m * n) + recursion stack O(m+n)
- Tabulation: O(m * n)
- Space optimized: O(n)
*/

const int MOD = 1e9 + 7;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int uniquePathsMemo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;
    if (matrix[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int up   = uniquePathsMemo(i - 1, j, matrix, dp);
    int left = uniquePathsMemo(i, j - 1, matrix, dp);

    return dp[i][j] = (up + left) % MOD;
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int uniquePathsTab(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = (i > 0) ? dp[i - 1][j] : 0;
            int left = (j > 0) ? dp[i][j - 1] : 0;

            dp[i][j] = (up + left) % MOD;
        }
    }
    return dp[m - 1][n - 1];
}

/* -------------------- SPACE OPTIMIZED (O(n) extra space) -------------------- */
int uniquePathsSpaceOpt(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                curr[j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                curr[j] = 1;
                continue;
            }
            int up = (i > 0) ? prev[j] : 0;
            int left = (j > 0) ? curr[j - 1] : 0;

            curr[j] = (up + left) % MOD;
        }
        prev = curr;
    }
    return prev[n - 1];
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int m = matrix.size();
    int n = matrix[0].size();

    // Memoization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Unique Paths with Obstacles (Memoization): " << uniquePathsMemo(m - 1, n - 1, matrix, dp) << "\n";

    // Tabulation
    cout << "Unique Paths with Obstacles (Tabulation): " << uniquePathsTab(matrix) << "\n";

    // Space Optimized
    cout << "Unique Paths with Obstacles (Space Optimized): " << uniquePathsSpaceOpt(matrix) << "\n";

    return 0;
}
