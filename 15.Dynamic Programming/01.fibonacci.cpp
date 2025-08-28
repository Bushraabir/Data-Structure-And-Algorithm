/*
Dynamic Programming (DP) – Introduction with Fibonacci Example

Intuition & Logic:
- "Those who cannot remember the past are condemned to repeat it" – in DP, this means
  we store results of already-solved subproblems so we don't recompute them.
- Many problems have *overlapping subproblems* and *optimal substructure*.
- Naive recursion for Fibonacci recalculates the same values multiple times (e.g., f(2), f(3)).
- DP avoids this by:
    1. Memoization (Top-Down) – Solve the problem recursively and store results.
    2. Tabulation (Bottom-Up) – Build the solution iteratively from base cases.
    3. Space Optimization – Reduce memory usage by only keeping needed states.

Problem Example – Fibonacci:
- Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, ...
- Recurrence: f(n) = f(n-1) + f(n-2), with base cases f(0)=0, f(1)=1.

Working Principle:
1. **Naive Recursion** – Explores the recursion tree fully; exponential time.
2. **Memoization** – Store and reuse results for O(N) time, O(N) space.
3. **Tabulation** – Fill DP array iteratively; O(N) time, O(N) space.
4. **Space Optimization** – Only store the last two computed values; O(N) time, O(1) space.

TIME & SPACE COMPLEXITY:
1. Memoization:
    - Time: O(N) → Each subproblem computed once
    - Space: O(N) for dp[] + O(N) recursion stack
2. Tabulation:
    - Time: O(N)
    - Space: O(N) for dp[] only (no recursion stack)
3. Space Optimization:
    - Time: O(N)
    - Space: O(1) → Only constant variables used

Why We Do This:
- Avoid redundant computation (overlapping subproblems).
- Reduce recursion depth and memory usage.
- Achieve the most efficient solution possible.

*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */

#include <bits/stdc++.h>
using namespace std;

// Function to compute Fibonacci using Memoization
int fibMemo(int n, vector<int>& dp) {
    // Base condition: If n is 0 or 1, return n directly
    if (n <= 1) return n;

    // Before computing, check if dp[n] already has a stored answer
    if (dp[n] != -1) return dp[n]; // Avoid recomputation

    // If not computed yet, compute using the recurrence relation
    // Store the computed value in dp[n] before returning
    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */

int fibTab(int n) {
    // Create a DP array of size n+1 to store results for 0 to n
    vector<int> dp(n+1, 0);

    // Base cases: directly assign known values
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array iteratively from 2 to n
    for (int i = 2; i <= n; i++) {
        // Current value depends on the previous two values
        dp[i] = dp[i-1] + dp[i-2];
    }

    // The final answer is stored at dp[n]
    return dp[n];
}

/* -------------------- SPACE OPTIMIZATION -------------------- */

int fibOpt(int n) {
    // If n is 0 or 1, directly return it (base cases)
    if (n <= 1) return n;

    // Instead of storing the whole DP array,
    // we only keep track of the last two computed values
    int prev2 = 0; // This represents dp[i-2]
    int prev1 = 1; // This represents dp[i-1]

    // Loop from 2 to n, updating only two variables
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2; // Current Fibonacci number
        prev2 = prev1;            // Move dp[i-1] to dp[i-2]
        prev1 = curr;             // Move current to dp[i-1]
    }

    // prev1 now contains the answer for f(n)
    return prev1;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    int n = 10; 

    // MEMOIZATION
    vector<int> dp(n+1, -1); // Initialize dp array with -1 (uncomputed state)
    cout << "Fibonacci (Memoization) of " << n << " : " << fibMemo(n, dp) << "\n";

    // TABULATION
    cout << "Fibonacci (Tabulation) of " << n << " : " << fibTab(n) << "\n";

    // SPACE OPTIMIZED
    cout << "Fibonacci (Space Optimized) of " << n << " : " << fibOpt(n) << "\n";

    return 0;
}
