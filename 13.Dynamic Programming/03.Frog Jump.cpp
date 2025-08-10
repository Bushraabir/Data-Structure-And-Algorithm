/*
Frog Jump Problem

Problem Statement:
- There is a frog at the first stair (index 0) of an n-stair staircase.
- heights[i] = height of stair i (0-based index).
- From stair i, frog can jump to:
    1. i+1 (one step)
    2. i+2 (two steps)
- Energy Cost: abs(heights[i] - heights[j]) where j is the target stair.
- Goal: Find the **minimum total energy** to reach stair n-1 from stair 0.

Example:
heights = {10, 20, 30, 10}, n = 4 (indices: 0, 1, 2, 3)
Paths:
    0 -> 1 -> 2 -> 3: 10 + 10 + 20 = 40
    0 -> 1 -> 3:      10 + 10 = 20 (minimum)
    0 -> 2 -> 3:      20 + 20 = 40
Answer: 20

Why This is a DP Problem:
- Problem asks for **minimum cost** by trying all possible paths.
- Greedy fails → optimal substructure & overlapping subproblems exist.
- Best approach: Think recursion → optimize using DP.

Greedy Fails Example:
- Always choosing minimum immediate jump cost can lead to higher total cost later.

*** Shortcut Trick for Recurrence Relation:
*** 1. Represent in terms of index:
***     - f(index) = min energy to reach index from stair 0.
*** 2. Do all possible actions:
***     - From index:
***         Option 1: From index-1 → cost = f(index-1) + abs(h[index] - h[index-1])
***         Option 2: From index-2 → cost = f(index-2) + abs(h[index] - h[index-2]) (only if index > 1)
*** 3. Take min (since goal is to minimize cost):
***     f(index) = min(
***         f(index-1) + abs(h[index] - h[index-1]),
***         f(index-2) + abs(h[index] - h[index-2])   // if index > 1
***     )

Base Cases:
- f(0) = 0 (already at first stair)
- f(1) = abs(h[1] - h[0])

Memoization (Top-Down):
- Store results in dp[] to avoid recomputation.
- Time: O(N)  | Space: O(N) + O(N) recursion stack.

Tabulation (Bottom-Up):
- Iteratively build dp array from base cases.
- Time: O(N)  | Space: O(N).

Space Optimization:
- Only depends on previous two states → store in prev, prev2 variables.
- Time: O(N)  | Space: O(1).

Follow-up (K Jumps):
- Frog can jump up to k stairs ahead.
- Requires iterating over all k possible previous stairs → O(N*k).
- O(1) space optimization not possible if k > 2.

*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int frogMemo(int index, vector<int>& heights, vector<int>& dp) {
    if (index == 0) return 0;
    if (index == 1) return abs(heights[1] - heights[0]);

    if (dp[index] != -1) return dp[index];

    int oneStep = frogMemo(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);
    int twoStep = frogMemo(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);

    return dp[index] = min(oneStep, twoStep);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int frogTab(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i < n; i++) {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}

/* -------------------- SPACE OPTIMIZATION -------------------- */
int frogOpt(vector<int>& heights) {
    int n = heights.size();
    if (n == 1) return 0;
    int prev = abs(heights[1] - heights[0]);
    int prev2 = 0;

    for (int i = 2; i < n; i++) {
        int oneStep = prev + abs(heights[i] - heights[i - 1]);
        int twoStep = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(oneStep, twoStep);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

/* -------------------- MAIN FUNCTION -------------------- */
int main() {
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size();

    // Memoization
    vector<int> dp(n, -1);
    cout << "Frog Jump (Memoization) : " << frogMemo(n - 1, heights, dp) << "\n";

    // Tabulation
    cout << "Frog Jump (Tabulation)  : " << frogTab(heights) << "\n";

    // Space Optimized
    cout << "Frog Jump (Space Opt)   : " << frogOpt(heights) << "\n";

    return 0;
}
