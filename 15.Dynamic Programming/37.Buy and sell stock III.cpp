/*
Problem Statement:
- You are given an array `prices[]` where prices[i] is the price of a stock on day i.
- You want to maximize your profit by choosing a single day to buy and a different day in the future to sell.
- Return the maximum profit you can achieve from this transaction.
- If no profit is possible, return 0.

Why This is a DP Problem:
- To decide the best selling price for day i, you need the lowest buying price from any day before i.
- The optimal solution for day i depends on results from day i-1 (overlapping subproblems).
- We build our solution from smaller subproblems (minimum price so far, maximum profit so far).

Recursive Definition:
Let F(i, minPrice) = maximum profit achievable from day i to the end if the minimum price so far is `minPrice`.

Base Case:
- If i == n (past the last day), return 0.

Recurrence:
F(i, minPrice) = max(
    prices[i] - minPrice,                // Sell today
    F(i+1, min(minPrice, prices[i]))     // Skip today, update minPrice
)

Tabulation:
- Iterate from left to right.
- Maintain two variables:
    minPrice = minimum price seen so far
    maxProfit = maximum profit seen so far

Space Optimization:
- Already O(1) space — we only keep two variables.

Time Complexity:
- O(N) — one pass through the array.

Space Complexity:
- O(1) — constant extra variables.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Recursion --------------------
int solveRec(int i, vector<int>& prices, int minPrice) {
    if (i == prices.size()) return 0;
    int sellToday = prices[i] - minPrice;
    int skipToday = solveRec(i + 1, prices, min(minPrice, prices[i]));
    return max(sellToday, skipToday);
}

// -------------------- 2. Memoization --------------------
int solveMemo(int i, vector<int>& prices, int minPrice, vector<vector<int>>& dp) {
    if (i == prices.size()) return 0;
    if (dp[i][minPrice] != -1) return dp[i][minPrice];
    int sellToday = prices[i] - minPrice;
    int skipToday = solveMemo(i + 1, prices, min(minPrice, prices[i]), dp);
    return dp[i][minPrice] = max(sellToday, skipToday);
}

// -------------------- 3. Tabulation --------------------
int solveTab(vector<int>& prices) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++) {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}

// -------------------- 4. Space Optimization --------------------
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

    vector<vector<int>> dp(prices.size(), vector<int>(10001, -1)); // minPrice range safeguard
    cout << "Memoization: " << solveMemo(0, prices, prices[0], dp) << "\n";

    cout << "Tabulation: " << solveTab(prices) << "\n";

    cout << "Space Optimized: " << solveSpaceOpt(prices) << "\n";

    return 0;
}
