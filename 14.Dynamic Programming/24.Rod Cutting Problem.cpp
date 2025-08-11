/*
Problem Statement:
- You are given an integer n representing the length of a rod and an array price[] of size n.
  price[i] represents the selling price of a rod piece of length (i+1).
- Task: Cut the rod into pieces (any lengths from 1 to n) to maximize the total selling price.
- You have an infinite supply of each rod length.

Why This is a DP Problem:
- At each step, you can either take a piece of the current length (stay at the same index since supply is infinite) or skip it and move to smaller lengths.
- Overlapping subproblems: The same (index, remaining_length) states appear multiple times in recursion.
- Optimal substructure: The optimal price for length n can be built from optimal prices of smaller lengths.

Recurrence:
If (index == 0):
    // Only length-1 rods are available
    return n * price[0]
Else:
    notTake = f(index - 1, n) // skip current length
    take = -INF
    rodLength = index + 1
    if (rodLength <= n):
        take = price[index] + f(index, n - rodLength) // stay at same index (unbounded)
    return max(take, notTake)

Initial Call:
f(n-1, n)

Time Complexity:
- Pure recursion: Exponential
- Memoization/Tabulation: O(n * N)
- Space optimized: O(N)

Space Complexity:
- Memoization: O(n * N) + recursion stack O(N)
- Tabulation: O(n * N)
- Space optimized: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int rodCutMemo(int index, int N, vector<int>& price, vector<vector<int>>& dp) {
    if (index == 0) return N * price[0];
    if (dp[index][N] != -1) return dp[index][N];

    int notTake = rodCutMemo(index - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= N)
        take = price[index] + rodCutMemo(index, N - rodLength, price, dp);

    return dp[index][N] = max(take, notTake);
}

int rodCuttingMemo(vector<int>& price, int N) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, -1));
    return rodCutMemo(n - 1, N, price, dp);
}

/* -------------------- TABULATION -------------------- */
int rodCuttingTab(vector<int>& price, int N) {
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(N + 1, 0));

    // Base case: only length-1 rods available
    for (int len = 0; len <= N; len++) dp[0][len] = len * price[0];

    for (int index = 1; index < n; index++) {
        for (int len = 0; len <= N; len++) {
            int notTake = dp[index - 1][len];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= len)
                take = price[index] + dp[index][len - rodLength];
            dp[index][len] = max(take, notTake);
        }
    }
    return dp[n - 1][N];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int rodCuttingSpaceOpt(vector<int>& price, int N) {
    int n = price.size();
    vector<int> dp(N + 1, 0);

    // Base case
    for (int len = 0; len <= N; len++) dp[len] = len * price[0];

    for (int index = 1; index < n; index++) {
        for (int len = 0; len <= N; len++) {
            int notTake = dp[len];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= len)
                take = price[index] + dp[len - rodLength];
            dp[len] = max(take, notTake);
        }
    }
    return dp[N];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> price = {2, 5, 7, 8, 10}; // prices for lengths 1..n
    int N = 5;

    cout << "Rod Cutting (Memoization): " << rodCuttingMemo(price, N) << "\n";
    cout << "Rod Cutting (Tabulation): " << rodCuttingTab(price, N) << "\n";
    cout << "Rod Cutting (Space Optimized): " << rodCuttingSpaceOpt(price, N) << "\n";

    return 0;
}
