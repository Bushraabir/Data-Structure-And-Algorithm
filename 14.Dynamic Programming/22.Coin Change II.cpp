/*
Problem Statement:
- You are given an array of n positive integers representing coin denominations and a target integer.
- Task: Count the total number of distinct ways to make the target sum using any number of coins.
- You have infinite supply of each coin denomination.

Why This is a DP Problem:
- At each step, you decide whether to take the current coin or skip it.
- Infinite supply property: If you take a coin, you can stay at the same index to take it again.
- Optimal substructure:
    Total ways to form target = ways without current coin + ways including current coin.
- Overlapping subproblems:
    The same (index, target) pairs are solved repeatedly in recursion.

Recurrence:
If (index == 0):
    return (target % coins[0] == 0) ? 1 : 0
Else:
    notTake = f(index - 1, target)
    take = 0
    if (coins[index] <= target) take = f(index, target - coins[index])
    return take + notTake

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

/* -------------------- MEMOIZATION -------------------- */
long long coinChangeMemo(int index, int target, vector<int>& coins, vector<vector<long long>>& dp) {
    if (index == 0) return (target % coins[0] == 0);
    if (dp[index][target] != -1) return dp[index][target];

    long long notTake = coinChangeMemo(index - 1, target, coins, dp);
    long long take = 0;
    if (coins[index] <= target) take = coinChangeMemo(index, target - coins[index], coins, dp);

    return dp[index][target] = take + notTake;
}

long long countWaysMemo(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(target + 1, -1));
    return coinChangeMemo(n - 1, target, coins, dp);
}

/* -------------------- TABULATION -------------------- */
long long countWaysTab(vector<int>& coins, int target) {
    int n = coins.size();
    vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));

    for (int t = 0; t <= target; t++) {
        dp[0][t] = (t % coins[0] == 0);
    }

    for (int index = 1; index < n; index++) {
        for (int t = 0; t <= target; t++) {
            long long notTake = dp[index - 1][t];
            long long take = 0;
            if (coins[index] <= t) take = dp[index][t - coins[index]];
            dp[index][t] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
long long countWaysSpaceOpt(vector<int>& coins, int target) {
    int n = coins.size();
    vector<long long> prev(target + 1, 0), curr(target + 1, 0);

    for (int t = 0; t <= target; t++) {
        prev[t] = (t % coins[0] == 0);
    }

    for (int index = 1; index < n; index++) {
        for (int t = 0; t <= target; t++) {
            long long notTake = prev[t];
            long long take = 0;
            if (coins[index] <= t) take = curr[t - coins[index]];
            curr[t] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> coins = {1, 2, 3};
    int target = 4;

    cout << "Coin Change 2 (Memoization): "
         << countWaysMemo(coins, target) << "\n";
    cout << "Coin Change 2 (Tabulation): "
         << countWaysTab(coins, target) << "\n";
    cout << "Coin Change 2 (Space Optimized): "
         << countWaysSpaceOpt(coins, target) << "\n";

    return 0;
}
