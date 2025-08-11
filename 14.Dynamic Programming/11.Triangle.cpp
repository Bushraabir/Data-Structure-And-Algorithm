/*
Problem Statement:
- You are given a triangular array (n rows).
- The i-th row contains i+1 elements.
- You start at the top (0,0) and can move:
    1. Down to (i+1, j)
    2. Diagonally right to (i+1, j+1)
- Your task: Find the minimum path sum from the top to any element in the last row.

Example:
Triangle:
   2
  3 4
 6 5 7
4 1 8 3

Possible Paths:
- Path 1: 2 -> 3 -> 5 -> 1 = 11
- Path 2: 2 -> 3 -> 5 -> 8 = 18
- Path 3: 2 -> 4 -> 7 -> 3 = 16
Answer: 11

Why This is a DP Problem:
- Optimal substructure: The minimal path sum from (i, j) depends on the minimal sums from (i+1, j) and (i+1, j+1).
- Overlapping subproblems: Many paths share the same sub-path computations.
- Define f(i, j) = minimum path sum from (i, j) to the last row.

Recurrence:
If (i == n-1):
    f(i, j) = triangle[i][j]  // last row, base case
Otherwise:
    f(i, j) = triangle[i][j] + min(f(i+1, j), f(i+1, j+1))

Initial Call (top-down): f(0, 0)

Time Complexity:
- Memoization/Tabulation: O(n^2)
- Pure recursion: Exponential (≈ 2^n)

Space Complexity:
- Memoization: O(n^2) + recursion stack O(n)
- Tabulation: O(n^2)
- Space optimized: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
int minPathTriangleMemo(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    int n = triangle.size();
    if (i == n - 1) return triangle[i][j]; // base case

    if (dp[i][j] != -1) return dp[i][j];

    int down = minPathTriangleMemo(i + 1, j, triangle, dp);
    int diagonal = minPathTriangleMemo(i + 1, j + 1, triangle, dp);

    return dp[i][j] = triangle[i][j] + min(down, diagonal);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int minPathTriangleTab(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case: last row
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // bottom-up filling
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}

/* -------------------- SPACE OPTIMIZED (O(n) extra space) -------------------- */
int minPathTriangleSpaceOpt(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> front(triangle[n - 1]); // base case: last row

    for (int i = n - 2; i >= 0; i--) {
        vector<int> curr(i + 1, 0);
        for (int j = 0; j <= i; j++) {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            curr[j] = min(down, diagonal);
        }
        front = curr; // move up one row
    }

    return front[0];
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int n = triangle.size();

    // Memoization
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Minimum Path Sum (Memoization): " << minPathTriangleMemo(0, 0, triangle, dp) << "\n";

    // Tabulation
    cout << "Minimum Path Sum (Tabulation): " << minPathTriangleTab(triangle) << "\n";

    // Space Optimized
    cout << "Minimum Path Sum (Space Optimized): " << minPathTriangleSpaceOpt(triangle) << "\n";

    return 0;
}
