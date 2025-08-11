/*
==============================================
Minimum Cost to Cut a Stick — Partition DP
==============================================

Problem Summary:
----------------
We have:
- A stick of total length 'n'.
- An array 'cuts[]' specifying positions along the stick where cuts must be made.

Rules:
------
- The cost of making a cut = length of the stick being cut *at that moment*.
- Once a cut is made, it splits the stick into two *independent* smaller sticks.
- Goal: Perform all cuts in the order that results in the *minimum total cost*.

Key Insight (Partition DP):
---------------------------
When you cut at position 'k', the problem splits into two **independent** subproblems:
    - Left side: from the left boundary to k
    - Right side: from k to the right boundary

So:
- The total cost = cost of current cut + cost of optimally cutting left side + cost of optimally cutting right side.

Preprocessing Steps:
--------------------
1. Insert 0 at the start and 'n' at the end of the cuts array.
   → This allows us to treat each stick segment uniformly and easily compute lengths as:
       length = cuts[j+1] - cuts[i-1]
2. Sort the cuts array.
   → Ensures that the subproblems are properly defined (no overlapping cuts in the wrong order).

DP Definition:
--------------
Let f(i, j) = minimum cost to make all cuts between cuts[i-1] and cuts[j+1]
             where i and j are indices in the **modified** cuts array
             (excluding 0 and n boundaries).

Base Case:
----------
If i > j → No cuts to be made → cost = 0.

Recurrence:
-----------
f(i, j) = min over k from i to j:
              (cuts[j+1] - cuts[i-1])  // cost of current cut segment
              + f(i, k-1)              // cost of cutting left segment
              + f(k+1, j)              // cost of cutting right segment

Time Complexity:
----------------
- States: O(M^2) where M = number of cuts + 2 (for boundaries)
- Transitions: O(M) for iterating over 'k'
- Total: O(M^3)

Space Complexity:
-----------------
O(M^2) for the DP table.

We'll implement:
1. Pure Recursion (for learning)
2. Memoization (Top-Down DP)
3. Tabulation (Bottom-Up DP, optimal for competitive programming)
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Recursive Solution --------------------
int solveRec(int i, int j, vector<int> &cuts) {
    // Base case: no cuts in this segment
    if (i > j) return 0;

    int mini = INT_MAX;
    // Try making each cut 'k' first
    for (int k = i; k <= j; k++) {
        int cost = (cuts[j+1] - cuts[i-1])  // cost of cutting current stick
                 + solveRec(i, k-1, cuts)   // cost of cutting left segment
                 + solveRec(k+1, j, cuts);  // cost of cutting right segment
        mini = min(mini, cost);
    }
    return mini;
}

// -------------------- 2. Memoization --------------------
int solveMem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for (int k = i; k <= j; k++) {
        int cost = (cuts[j+1] - cuts[i-1])
                 + solveMem(i, k-1, cuts, dp)
                 + solveMem(k+1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

// -------------------- 3. Tabulation (Optimal) --------------------
int solveTab(vector<int> &cuts) {
    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    // i goes backwards so t
