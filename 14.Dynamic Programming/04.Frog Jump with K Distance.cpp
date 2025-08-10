/*

Problem Statement:
- There is a frog at stair 0 of an n-stair staircase.
- heights[i] = height of stair i (0-based index).
- From stair i, frog can jump to:
    i+1, i+2, ..., i+k  (up to k steps ahead)
- Energy Cost: abs(heights[i] - heights[j]) where j is the target stair.
- Goal: Find the **minimum total energy** to reach stair n-1 from stair 0.

Example:
heights = {10, 30, 40, 50, 20}, n = 5, k = 3
Possible paths:
    0 -> 2 -> 4: cost = |10-40| + |40-20| = 30 + 20 = 50
    0 -> 1 -> 4: cost = |10-30| + |30-20| = 20 + 10 = 30 (soln)
    0 -> 3 -> 4: cost = |10-50| + |50-20| = 40 + 30 = 70
Answer: 30

Why This is a DP Problem:
- We want the **minimum** energy over all valid jump paths.
- Overlapping subproblems: same index reached via different paths.
- Optimal substructure: best way to reach i uses best ways to reach earlier stairs.

Generalized Recurrence for K Jumps:
Let f(index) = min energy to reach `index` from 0.

For each possible jump distance j (1 ≤ j ≤ k):
    if (index - j >= 0):
        jumpEnergy = f(index - j) + abs(heights[index] - heights[index - j])
        take minimum over all valid j.

Formula:
f(index) = min(
    f(index - j) + |h[index] - h[index - j]|   for all j in [1, k] and index-j >= 0
)

Base Case:
- f(0) = 0  (already at the first stair)

Time Complexity: O(N*K)
Space Complexity: O(N) for dp[] (O(N) extra for recursion in memoization)

Space Optimization:
- Not possible in O(1) if k > 2, because we need last k states.
- Can be reduced to O(K) by storing only last k dp values, but for k ≈ N this is same as O(N).

*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int frogKMemo(int index, vector<int>& heights, int k, vector<int>& dp) {
    if (index == 0) return 0;
    if (dp[index] != -1) return dp[index];

    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (index - j >= 0) {
            int jumpEnergy = frogKMemo(index - j, heights, k, dp) + 
                             abs(heights[index] - heights[index - j]);
            minEnergy = min(minEnergy, jumpEnergy);
        }
    }
    return dp[index] = minEnergy;
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int frogKTab(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jumpEnergy = dp[i - j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(dp[i], jumpEnergy);
            }
        }
    }
    return dp[n - 1];
}

/* -------------------- MAIN FUNCTION -------------------- */
int main() {
    vector<int> heights = {10, 30, 40, 50, 20};
    int n = heights.size();
    int k = 3;

    // Memoization
    vector<int> dp(n, -1);
    cout << "Frog Jump K Distance (Memoization): " 
         << frogKMemo(n - 1, heights, k, dp) << "\n";

    // Tabulation
    cout << "Frog Jump K Distance (Tabulation) : " 
         << frogKTab(heights, k) << "\n";

    return 0;
}
