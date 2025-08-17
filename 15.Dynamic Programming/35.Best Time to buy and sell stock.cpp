/*
Problem Statement:
- You are given an array `prices` where prices[i] is the price of a given stock on day i (0-indexed).
- Task: Find the maximum profit you can achieve from one transaction (buy one and sell one share of the stock).
    1. You must buy before you sell.
    2. You can complete at most one transaction.

Why This is a DP Problem:
- At each day, the decision depends on the minimum price seen so far (information from the past).
- We are "remembering" the lowest price before the current day to decide the best sell price.
- The optimal profit for day i builds on optimal profit for day i-1 (overlapping subproblems).

Recursive Definition:
Let F(i) = maximum profit achievable from day 0 to day i.
We maintain:
    minPrice = minimum price seen from day 0 to day i.
    maxProfit = max(F(i-1), prices[i] - minPrice)

Base Case:
- Day 0: profit = 0, minPrice = prices[0].

Recurrence:
F(i) = max(F(i-1), prices[i] - minPrice)
minPrice = min(minPrice, prices[i])

Tabulation:
Iterate from day 1 to day n-1:
    Update minPrice and maxProfit at each step.

Space Optimization:
- We only need two variables: minPrice and maxProfit → O(1) space.

Time Complexity:
- O(N) — single pass through prices.

Space Complexity:
- O(1) — only constant variables.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Pure Recursion --------------------
// Not practical for this problem since recursion would recompute minPrice many times.
int solveRec(int i, vector<int>& prices, int minPrice) {
    if (i == prices.size()) return 0;
    int profitToday = prices[i] - minPrice;
    int option1 = solveRec(i + 1, prices, min(minPrice, prices[i])); // skip selling today
    return max(profitToday, option1);
}

// -------------------- 2. Memoization --------------------
int solveMemo(int i, vector<int>& prices, int minPrice, vector<vector<int>>& dp) {
    if (i == prices.size()) return 0;
    if (dp[i][minPrice] != -1) return dp[i][minPrice];
    int profitToday = prices[i] - minPrice;
    int option1 = solveMemo(i + 1, prices, min(minPrice, prices[i]), dp);
    return dp[i][minPrice] = max(profitToday, option1);
}

// -------------------- 3. Tabulation --------------------
int solveTab(vector<int>& prices) {
    int n = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}

// -------------------- 4. Space Optimization --------------------
// Same as tabulation — already O(1) space
int solveSpaceOpt(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int price : prices) {
        maxProfit = max(maxProfit, price - minPrice);
        minPrice = min(minPrice, price);
    }
    return maxProfit;
}

// -------------------- Main --------------------
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Recursion: " << solveRec(0, prices, prices[0]) << "\n";

    vector<vector<int>> dp(prices.size(), vector<int>(10001, -1)); // Large enough for minPrice values
    cout << "Memoization: " << solveMemo(0, prices, prices[0], dp) << "\n";

    cout << "Tabulation: " << solveTab(prices) << "\n";

    cout << "Space Optimized: " << solveSpaceOpt(prices) << "\n";

    return 0;
}
