/*
Problem Statement:
- You are given an array of n positive integers representing coin denominations and a target integer.
- Task: Find the minimum number of coins required to make the target sum.
- You have infinite supply of each coin denomination.
- If it's not possible to form the target, return -1.

Why This is a DP Problem:
- At each step, you can either take the current coin (stay at the same index since supply is infinite) or skip it.
- Overlapping subproblems: The same (index, target) states appear multiple times in recursion.
- Optimal substructure: The solution to the target can be built from solutions to smaller sub-targets.

Recurrence:
If (index == 0):
    If target % coins[0] == 0: return target / coins[0]
    Else: return INF (large number)
Else:
    notTake = f(index - 1, target)
    take = INF
    if coins[index] <= target:
        take = 1 + f(index, target - coins[index])
    return min(take, notTake)

Initial Call:
f(n-1, target)

Time Complexity:
- Pure recursion: Exponential
- Memoization/Tabulation: O(n * target)
- Space optimized: O(target)

Space Complexity:
- Memoization: O(n * target) + recursion stack O(target)
- Tabulation: O(n * target)
- Space optimized: O(target)
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

/* -------------------- MEMOIZATION -------------------- */
int minCoinsMemo(int index, int target, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target % coins[0] == 0) return target / coins[0];
        return INF;
    }
    if (dp[index][target] != -1) return dp[index][target];

    int notTake = minCoinsMemo(index - 1, target, coins, dp);
    int take = INF;
    if (coins[index] <= target) take = 1 + minCoinsMemo(index, target - coins[index], coins, dp);

    return dp[index][target] = min(take, notTake);
}

int coinChangeMemo(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = minCoinsMemo(n - 1, target, coins, dp);
    return (ans >= INF) ? -1 : ans;
}

/* -------------------- TABULATION -------------------- */
int coinChangeTab(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, INF));

    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0) dp[0][t] = t / coins[0];
    }

    for (int index = 1; index < n; index++) {
        for (int t = 0; t <= target; t++) {
            int notTake = dp[index - 1][t];
            int take = INF;
            if (coins[index] <= t) take = 1 + dp[index][t - coins[index]];
            dp[index][t] = min(take, notTake);
        }
    }
    return (dp[n - 1][target] >= INF) ? -1 : dp[n - 1][target];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int coinChangeSpaceOpt(vector<int>& coins, int target) {
    int n = coins.size();
    vector<int> prev(target + 1, INF), curr(target + 1, INF);

    for (int t = 0; t <= target; t++) {
        if (t % coins[0] == 0) prev[t] = t / coins[0];
    }

    for (int index = 1; index < n; index++) {
        for (int t = 0; t <= target; t++) {
            int notTake = prev[t];
            int take = INF;
            if (coins[index] <= t) take = 1 + curr[t - coins[index]];
            curr[t] = min(take, notTake);
        }
        prev = curr;
    }
    return (prev[target] >= INF) ? -1 : prev[target];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> coins = {1, 2, 5};
    int target = 11;

    cout << "Coin Change 1 (Memoization): " << coinChangeMemo(coins, target) << "\n";
    cout << "Coin Change 1 (Tabulation): " << coinChangeTab(coins, target) << "\n";
    cout << "Coin Change 1 (Space Optimized): " << coinChangeSpaceOpt(coins, target) << "\n";

    return 0;
}
