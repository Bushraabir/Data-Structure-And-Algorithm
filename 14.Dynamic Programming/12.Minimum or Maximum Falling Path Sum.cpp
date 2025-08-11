/*
Problem Statement:
- You are given an n x m matrix of integers.
- You can start at ANY cell in the first row.
- You can end at ANY cell in the last row.
- From (i, j), you can move to:
    1. Down: (i+1, j)
    2. Down-left: (i+1, j-1)
    3. Down-right: (i+1, j+1)
- Your task: Find the maximum path sum from the first row to the last row.

Example:
Matrix:
   1   2   10
  100  3    2
    1  1   20
    2  2    1

Possible Paths:
- Path 1: 10 -> 2 -> 20 -> 2 = 34
- Path 2: 2 -> 3 -> 1 -> 2 = 8
- Path 3: 1 -> 100 -> 1 -> 2 = 104
Answer: 104

Why This is a DP Problem:
- Optimal substructure: The max path sum to (i, j) depends on the max sums from the cells in the previous row
  that can reach it: (i-1, j), (i-1, j-1), (i-1, j+1).
- Overlapping subproblems: Many positions share the same sub-path calculations.
- Define f(i, j) = maximum path sum to reach (i, j) from any cell in the first row.

Recurrence:
If (i == 0):
    f(i, j) = matrix[0][j]  // base case (first row)
Otherwise:
    f(i, j) = matrix[i][j] + max(
                    f(i-1, j),
                    f(i-1, j-1) if valid,
                    f(i-1, j+1) if valid
                )

Initial Call (top-down): For all j in [0, m-1], compute f(n-1, j) and take the maximum.

Time Complexity:
- Memoization/Tabulation: O(n*m)
- Pure recursion: Exponential (≈ 3^n)

Space Complexity:
- Memoization: O(n*m) + recursion stack O(n)
- Tabulation: O(n*m)
- Space optimized: O(m)
*/

#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = -1e9;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
int maxPathSumMemo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size(), m = matrix[0].size();

    if (j < 0 || j >= m) return NEG_INF; // out of bounds
    if (i == 0) return matrix[0][j];     // base case

    if (dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + maxPathSumMemo(i - 1, j, matrix, dp);
    int leftDiag = matrix[i][j] + maxPathSumMemo(i - 1, j - 1, matrix, dp);
    int rightDiag = matrix[i][j] + maxPathSumMemo(i - 1, j + 1, matrix, dp);

    return dp[i][j] = max({up, leftDiag, rightDiag});
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int maxPathSumTab(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // base case: first row
    for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

    // fill dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiag = matrix[i][j] + (j > 0 ? dp[i - 1][j - 1] : NEG_INF);
            int rightDiag = matrix[i][j] + (j < m - 1 ? dp[i - 1][j + 1] : NEG_INF);
            dp[i][j] = max({up, leftDiag, rightDiag});
        }
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

/* -------------------- SPACE OPTIMIZED (O(m) extra space) -------------------- */
int maxPathSumSpaceOpt(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> prev(matrix[0]), curr(m, 0);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int leftDiag = matrix[i][j] + (j > 0 ? prev[j - 1] : NEG_INF);
            int rightDiag = matrix[i][j] + (j < m - 1 ? prev[j + 1] : NEG_INF);
            curr[j] = max({up, leftDiag, rightDiag});
        }
        prev = curr;
    }

    return *max_element(prev.begin(), prev.end());
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 10},
        {100, 3, 2},
        {1, 1, 20},
        {2, 2, 1}
    };

    int n = matrix.size(), m = matrix[0].size();

    // Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ansMemo = NEG_INF;
    for (int j = 0; j < m; j++)
        ansMemo = max(ansMemo, maxPathSumMemo(n - 1, j, matrix, dp));
    cout << "Maximum Path Sum (Memoization): " << ansMemo << "\n";

    // Tabulation
    cout << "Maximum Path Sum (Tabulation): " << maxPathSumTab(matrix) << "\n";

    // Space Optimized
    cout << "Maximum Path Sum (Space Optimized): " << maxPathSumSpaceOpt(matrix) << "\n";

    return 0;
}
