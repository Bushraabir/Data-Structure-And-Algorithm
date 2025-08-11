/*
Problem Statement:
- You are given an array prices[] where prices[i] is the price of a stock on day i.
- You can complete at most ONE transaction (buy one day, sell on a later day).
- Return the maximum profit achievable, or 0 if no profit is possible.

Why this is a DP problem:
- At each day, you make a decision based on previous results:
    - If you can buy: decide to buy or skip
    - If you can sell: decide to sell or skip
- Overlapping subproblems: profit at day i depends on optimal profit at day i+1
- Optimal substructure: the optimal decision at day i uses optimal decisions from the future.

Recurrence:
Let F(i, buy) = maximum profit achievable starting at day i, where:
    buy = 1 → we are allowed to buy on this day
    buy = 0 → we are holding a stock, so we must sell or skip

Base Case:
    If i == n → return 0 (no days left)

Transitions:
    If buy == 1:
        F(i, 1) = max(-prices[i] + F(i+1, 0), 0 + F(i+1, 1))
    If buy == 0:
        F(i, 0) = max(prices[i] + F(i+1, 1), 0 + F(i+1, 0))

Time Complexity:
    O(N) for iterative, O(N) recursion with memoization
Space Complexity:
    Recursion: O(N) stack
    Memoization: O(N*2) table
    Tabulation: O(N*2) array
    Space Optimized: O(2)
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Recursion --------------------
int solveRec(int i, int buy, vector<int> &prices) {
    if (i == prices.size()) return 0;

    if (buy) { // Allowed to buy
        return max(-prices[i] + solveRec(i + 1, 0, prices),  // Buy today
                   0 + solveRec(i + 1, 1, prices));          // Skip today
    } else { // Must sell
        return max(prices[i] + solveRec(i + 1, 1, prices),   // Sell today
                   0 + solveRec(i + 1, 0, prices));          // Skip today
    }
}

// -------------------- 2. Memoization --------------------
int solveMemo(int i, int buy, vector<int> &prices, vector<vector<int>> &dp) {
    if (i == prices.size()) return 0;
    if (dp[i][buy] != -1) return dp[i][buy];

    if (buy) {
        return dp[i][buy] = max(-prices[i] + solveMemo(i + 1, 0, prices, dp),
                                0 + solveMemo(i + 1, 1, prices, dp));
    } else {
        return dp[i][buy] = max(prices[i] + solveMemo(i + 1, 1, prices, dp),
                                0 + solveMemo(i + 1, 0, prices, dp));
    }
}

// -------------------- 3. Tabulation --------------------
int solveTab(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                dp[i][buy] = max(-prices[i] + dp[i + 1][0],
                                 0 + dp[i + 1][1]);
            } else {
                dp[i][buy] = max(prices[i] + dp[i + 1][1],
                                 0 + dp[i + 1][0]);
            }
        }
    }
    return dp[0][1]; // Start on day 0, allowed to buy
}

// -------------------- 4. Space Optimization --------------------
int solveSpaceOpt(vector<int> &prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy) {
                curr[buy] = max(-prices[i] + ahead[0],
                                 0 + ahead[1]);
            } else {
                curr[buy] = max(prices[i] + ahead[1],
                                 0 + ahead[0]);
            }
        }
        ahead = curr;
    }
    return ahead[1];
}

// -------------------- Main --------------------
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Recursion: " << solveRec(0, 1, prices) << "\n";

    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    cout << "Memoization: " << solveMemo(0, 1, prices, dp) << "\n";

    cout << "Tabulation: " << solveTab(prices) << "\n";

    cout << "Space Optimized: " << solveSpaceOpt(prices) << "\n";

    return 0;
}
