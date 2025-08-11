/*
Problem Statement:
- Given an array of coin denominations (infinite supply of each).
- Given a target sum.
- Task: Find the minimum number of coins needed to make the target sum.
- If not possible, return some large value (or -1).

Why This is a DP Problem:
- At each coin index and target, we choose to pick or not pick coins.
- Infinite supply means we can pick the same coin multiple times.
- Overlapping subproblems: same (index, target) states repeat.
- Optimal substructure: minimum coins for target depends on smaller subproblems.

Recurrence:
f(index, target) =
    if (index == 0)
        if (target % coins[0] == 0) return target / coins[0]
        else return INT_MAX (impossible)

    notPick = f(index-1, target)
    pick = INT_MAX
    if (coins[index] <= target)
        pick = 1 + f(index, target - coins[index])  // stay at same index due to infinite supply

    return min(pick, notPick)

Initial Call: f(n-1, target)

Time Complexity:
- Recursive: Exponential (very large)
- Memoization/Tabulation: O(N * Target)
- Space Optimized: O(Target)

Space Complexity:
- Memoization: O(N * Target) + recursion stack O(Target)
- Tabulation: O(N * Target)
- Space Optimized: O(Target)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int minCoinsMemo(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (idx == 0) {
        if (target % coins[0] == 0) return target / coins[0];
        else return 1e9;  // impossible large number
    }

    if (dp[idx][target] != -1) return dp[idx][target];

    int notPick = minCoinsMemo(idx - 1, target, coins, dp);
    int pick = 1e9;
    if (coins[idx] <= target)
        pick = 1 + minCoinsMemo(idx, target - coins[idx], coins, dp);

    return dp[idx][target] = min(pick, notPick);
}

/* -------------------- TABULATION -------------------- */
int minCoinsTab(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 1e9));

    // Base case for idx = 0
    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0) dp[0][t] = t / coins[0];
    }

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notPick = dp[i - 1][t];
            int pick = 1e9;
            if (coins[i] <= t)
                pick = 1 + dp[i][t - coins[i]];
            dp[i][t] = min(pick, notPick);
        }
    }

    return dp[n - 1][target] >= 1e9 ? -1 : dp[n - 1][target];
}

/* -------------------- SPACE OPTIMIZATION (Two Rows) -------------------- */
int minCoinsSpaceOptTwoRows(vector<int>& coins, int target) {
    int n = coins.size();
    vector<int> prev(target + 1, 1e9), curr(target + 1, 1e9);

    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0) prev[t] = t / coins[0];
    }

    for (int i = 1; i < n; i++) {
        for (int t = 0; t <= target; t++) {
            int notPick = prev[t];
            int pick = 1e9;
            if (coins[i] <= t)
                pick = 1 + curr[t - coins[i]];
            curr[t] = min(pick, notPick);
        }
        prev = curr;
    }

    return prev[target] >= 1e9 ? -1 : prev[target];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> coins = {1, 2, 3};
    int target = 7;

    cout << "Minimum Coins (Memoization): " << minCoinsMemo(coins.size() - 1, target, coins, vector<vector<int>>(coins.size(), vector<int>(target + 1, -1))) << "\n";

    cout << "Minimum Coins (Tabulation): " << minCoinsTab(coins, target) << "\n";

    cout << "Minimum Coins (Space Optimized - Two Rows): " << minCoinsSpaceOptTwoRows(coins, target) << "\n";

    return 0;
}
