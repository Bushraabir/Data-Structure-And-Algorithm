/*
Problem Statement:
- You are at the top-left corner (0, 0) of an m x n grid.
- You want to reach the bottom-right corner (m-1, n-1).
- You can only move either RIGHT or DOWN at any step.
- Find the total number of unique paths from (0, 0) to (m-1, n-1).

Example:
For a 2x2 grid:
Paths:
    1. Right -> Down
    2. Down  -> Right
Answer: 2

Why This is a DP Problem:
- We are counting all possible ways to reach a cell — optimal substructure applies.
- Overlapping subproblems occur when multiple paths reach the same cell.
- We define f(i, j) = number of unique paths from (0, 0) to (i, j).

Recurrence:
If (i == 0 && j == 0):
    f(i, j) = 1  // Only one way: start point itself
If (i < 0 || j < 0):
    f(i, j) = 0  // Out of bounds, no path

Otherwise:
    f(i, j) = f(i-1, j) + f(i, j-1)  // From top + from left

Initial Call (top-down): f(m-1, n-1)

Time Complexity:
- Memoization/Tabulation: O(m * n)
- Pure recursion: O(2^(m+n)) (inefficient)

Space Complexity:
- Memoization: O(m * n) + recursion stack O(m+n)
- Tabulation: O(m * n)
- Space optimized: O(n)
*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int uniquePathsMemo(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int up   = uniquePathsMemo(i - 1, j, dp);
    int left = uniquePathsMemo(i, j - 1, dp);

    return dp[i][j] = up + left;
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int uniquePathsTab(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) dp[i][j] = 1;
            else {
                int up   = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

/* -------------------- SPACE OPTIMIZED (O(n) extra space) -------------------- */
int uniquePathsSpaceOpt(int m, int n) {
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) curr[j] = 1;
            else {
                int up   = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

/* -------------------- MAIN function -------------------- */
int main() {
    int m = 3, n = 3; 

    // Memoization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Unique Paths (Memoization): " << uniquePathsMemo(m - 1, n - 1, dp) << "\n";

    // Tabulation
    cout << "Unique Paths (Tabulation): " << uniquePathsTab(m, n) << "\n";

    // Space Optimized
    cout << "Unique Paths (Space Optimized): " << uniquePathsSpaceOpt(m, n) << "\n";

    return 0;
}
