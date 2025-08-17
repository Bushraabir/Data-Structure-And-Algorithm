/*
Problem Statement:
- You are given an n x m matrix of integers representing chocolates in each cell.
- Alice starts at (0, 0) and Bob starts at (0, m-1).
- From (i, j), each can move to:
    1. Down: (i+1, j)
    2. Down-left: (i+1, j-1)
    3. Down-right: (i+1, j+1)
- Both move simultaneously, picking chocolates from their cells.
- If they land on the same cell, chocolates are counted only once.
- Task: Find the maximum chocolates they can collect.

Why This is a DP Problem:
- Optimal substructure: The max chocolates from (i, j1, j2) depends on the best moves from the next row.
- Overlapping subproblems: Many (i, j1, j2) states repeat.
- Define f(i, j1, j2) = maximum chocolates collected starting from row i when Alice is at col j1 and Bob at col j2.

Recurrence:
If (i == n-1):
    if (j1 == j2) return grid[i][j1]
    else return grid[i][j1] + grid[i][j2]
Else:
    For delta1 in {-1, 0, 1}:
        For delta2 in {-1, 0, 1}:
            newJ1 = j1 + delta1, newJ2 = j2 + delta2
            value = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2])
            ans = max(ans, value + f(i+1, newJ1, newJ2))

Initial Call: f(0, 0, m-1)

Time Complexity:
- Memoization/Tabulation: O(n*m*m*9) ≈ O(n*m^2)
- Pure recursion: Exponential (≈ 9^n)

Space Complexity:
- Memoization: O(n*m*m) + recursion stack O(n)
- Tabulation: O(n*m*m)
- Space optimized: O(m*m)
*/

#include <bits/stdc++.h>
using namespace std;

const int NEG_INF = -1e9;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
int solveMemo(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    int n = grid.size(), m = grid[0].size();

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return NEG_INF;
    if (i == n - 1) {
        if (j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = NEG_INF;
    for (int delta1 = -1; delta1 <= 1; delta1++) {
        for (int delta2 = -1; delta2 <= 1; delta2++) {
            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
            value += solveMemo(i + 1, j1 + delta1, j2 + delta2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int solveTab(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Base case
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
            else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = NEG_INF;
                for (int delta1 = -1; delta1 <= 1; delta1++) {
                    for (int delta2 = -1; delta2 <= 1; delta2++) {
                        int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                        int newJ1 = j1 + delta1, newJ2 = j2 + delta2;
                        if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m)
                            value += dp[i + 1][newJ1][newJ2];
                        else value += NEG_INF;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

/* -------------------- SPACE OPTIMIZED (O(m*m) extra space) -------------------- */
int solveSpaceOpt(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    // Base case
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) front[j1][j2] = grid[n - 1][j1];
            else front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = NEG_INF;
                for (int delta1 = -1; delta1 <= 1; delta1++) {
                    for (int delta2 = -1; delta2 <= 1; delta2++) {
                        int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                        int newJ1 = j1 + delta1, newJ2 = j2 + delta2;
                        if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m)
                            value += front[newJ1][newJ2];
                        else value += NEG_INF;
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1];
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    int n = grid.size(), m = grid[0].size();

    // Memoization
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << "Maximum Chocolates (Memoization): " << solveMemo(0, 0, m - 1, grid, dp) << "\n";

    // Tabulation
    cout << "Maximum Chocolates (Tabulation): " << solveTab(grid) << "\n";

    // Space Optimized
    cout << "Maximum Chocolates (Space Optimized): " << solveSpaceOpt(grid) << "\n";

    return 0;
}
