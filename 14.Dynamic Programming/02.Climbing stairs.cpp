/*
Dynamic Programming (DP) – Climbing Stairs Problem

Problem Statement:
- You are given `n` stairs, starting at the 0th stair.
- From any stair, you can climb either 1 step or 2 steps.
- Task: Return the number of distinct ways to climb from the 0th stair to the nth stair.

Example:
n = 3
1. 0 -> 1 -> 2 -> 3
2. 0 -> 2 -> 3
3. 0 -> 1 -> 3
Answer: 3 ways

Identifying a DP Problem:
- If the problem asks "count total number of ways", "minimum cost", or "maximum result",
  it's likely a DP problem.
- Often involves "trying all possible ways".
- Always think recursion first → then optimize using DP.

Shortcut for Writing Recurrence Relations (Three Points):
1. Represent the problem in terms of an index:
   - Treat stairs 0 to n as indexes.
2. Do all possible actions on that index:
   - From stair i, you can come from i-1 (1 step) or i-2 (2 steps).
3. Sum or take min/max based on the problem:
   - Counting ways → sum results from all allowed moves.

Recurrence Relation:
f(n) = f(n-1) + f(n-2)
Base cases:
f(0) = 1  // 1 way to stay at stair 0
f(1) = 1  // 1 way to reach stair 1 (one step from 0)

Relation to Fibonacci:
- This is exactly the Fibonacci sequence shifted by 1 index.

Transition to DP:
1. Memoization – Store recursive results (Top-Down).
2. Tabulation – Build iteratively (Bottom-Up).
3. Space Optimization – Only keep last two results.

Handling Very Large n:
- For n up to 10^18 → O(N) is too slow.
- Use Matrix Exponentiation → O(log N).

TIME & SPACE COMPLEXITY:
Memoization:
    Time: O(N)
    Space: O(N) dp[] + O(N) recursion stack
Tabulation:
    Time: O(N)
    Space: O(N)
Space Optimization:
    Time: O(N)
    Space: O(1)
*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int climbMemo(int n, vector<int>& dp) {
    if (n == 0 || n == 1) return 1; // base cases

    if (dp[n] != -1) return dp[n]; // avoid recomputation

    return dp[n] = climbMemo(n-1, dp) + climbMemo(n-2, dp);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int climbTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/* -------------------- SPACE OPTIMIZATION -------------------- */
int climbOpt(int n) {
    if (n == 0 || n == 1) return 1;

    int prev2 = 1; // ways to reach i-2
    int prev1 = 1; // ways to reach i-1

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

/* -------------------- MAIN FUNCTION -------------------- */
int main() {
    int n = 5; // number of stairs

    // Memoization
    vector<int> dp(n+1, -1);
    cout << "Climbing Stairs (Memoization) : " << climbMemo(n, dp) << "\n";

    // Tabulation
    cout << "Climbing Stairs (Tabulation)  : " << climbTab(n) << "\n";

    // Space Optimized
    cout << "Climbing Stairs (Space Opt)   : " << climbOpt(n) << "\n";

    return 0;
}
