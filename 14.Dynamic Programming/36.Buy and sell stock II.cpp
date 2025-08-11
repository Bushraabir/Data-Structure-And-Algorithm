/*
Problem Statement:
- You are given an array `prices[]` where `prices[i]` represents the price of a stock on the i-th day.
- Task: Find the maximum profit you can achieve by completing at most one transaction:
    1. You must buy the stock before you sell it.
    2. You can only make one buy and one sell.

Why This is a DP Problem:
- The decision on which day to sell depends on remembering the lowest price so far (past state).
- This is "remembering the past" — a core DP concept.
- Each day's decision is based on optimal solutions to subproblems: minimum so far and maximum profit so far.

Recursive Definition (0-based indexing):
Let F(i) = maximum profit possible from day 0 to day i.

Base Cases:
- At day 0: No transaction can be made, so profit = 0.

Recurrence:
- Keep track of:
    minPrice = minimum price seen so far up to day i.
    profit   = maximum profit seen so far.
- For each price[i]:
    potentialProfit = prices[i] - minPrice
    profit = max(profit, potentialProfit)
    minPrice = min(minPrice, prices[i])

Tabulation:
We don't actually need a DP table here — just variables to store:
    minPrice (minimum price so far)
    profit (maximum profit so far)

Space Optimization:
- Already O(1) since we only store two variables.

Time Complexity:
- O(N) — single pass over the array.

Space Complexity:
- O(1) — constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- 1. Pure Recursion (for understanding) --------------------
int solveRec(vector<int> &prices, int idx, int minPrice) {
    if (idx == prices.size()) return 0;

    int profitToday = prices[idx] - minPrice;
    int bestIfSellToday = max(profitToday, solveRec(prices, idx + 1, min(minPrice, prices[idx])));
    return bestIfSellToday;
}

// -------------------- 2. Iterative Approach (Optimal) --------------------
int maxProfit(vector<int> &prices) {
    int minPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int potentialProfit = prices[i] - minPrice;
        profit = max(profit, potentialProfit);
        minPrice = min(minPrice, prices[i]);
    }
    return profit;
}

// -------------------- Main --------------------
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Recursive version (for learning, not optimal for large inputs)
    cout << "Recursion: " << solveRec(prices, 0, prices[0]) << "\n";

    // Iterative optimal version
    cout << "Iterative (Optimal): " << maxProfit(prices) << "\n";

    return 0;
}
