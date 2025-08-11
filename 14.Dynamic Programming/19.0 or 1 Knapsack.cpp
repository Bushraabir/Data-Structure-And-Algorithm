/*
Problem Statement:
- You are given N items, each with a weight and a value.
- You have a bag with maximum capacity W.
- Task: Select items to maximize total value without exceeding capacity.
- Constraint: 0/1 Knapsack — each item can be chosen at most once.

Why This is a DP Problem:
- Choices at each item: pick or not pick.
- Overlapping subproblems: same (index, capacity) pairs repeat.
- Optimal substructure: solution depends on smaller subproblems.

Recurrence:
f(index, W) =
    if (index == 0)
        if (weight[0] <= W) return value[0]
        else return 0

    notPick = f(index-1, W)
    pick = -∞
    if (weight[index] <= W)
        pick = value[index] + f(index-1, W - weight[index])

    return max(pick, notPick)

Initial Call: f(n-1, W)

Time Complexity:
- Recursive: O(2^N)
- Memoization/Tabulation: O(N*W)
- Space Optimized: O(W)

Space Complexity:
- Memoization: O(N*W) + recursion stack O(N)
- Tabulation: O(N*W)
- Space Optimized: O(W)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int knapsackMemo(int idx, int W, vector<int>& weights, vector<int>& values, vector<vector<int>>& dp) {
    if (idx == 0) {
        if (weights[0] <= W) return values[0];
        else return 0;
    }

    if (dp[idx][W] != -1) return dp[idx][W];

    int notPick = knapsackMemo(idx - 1, W, weights, values, dp);
    int pick = INT_MIN;
    if (weights[idx] <= W)
        pick = values[idx] + knapsackMemo(idx - 1, W - weights[idx], weights, values, dp);

    return dp[idx][W] = max(pick, notPick);
}

/* -------------------- TABULATION -------------------- */
int knapsackTab(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: only first item
    for (int w = weights[0]; w <= W; w++) {
        dp[0][w] = values[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notPick = dp[i - 1][w];
            int pick = INT_MIN;
            if (weights[i] <= w)
                pick = values[i] + dp[i - 1][w - weights[i]];
            dp[i][w] = max(pick, notPick);
        }
    }

    return dp[n - 1][W];
}

/* -------------------- SPACE OPTIMIZATION (Two Rows) -------------------- */
int knapsackSpaceOptTwoRows(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    for (int w = weights[0]; w <= W; w++) {
        prev[w] = values[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int notPick = prev[w];
            int pick = INT_MIN;
            if (weights[i] <= w)
                pick = values[i] + prev[w - weights[i]];
            curr[w] = max(pick, notPick);
        }
        prev = curr;
    }

    return prev[W];
}

/* -------------------- SPACE OPTIMIZATION (Single Array) -------------------- */
int knapsackSpaceOptSingleArray(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<int> dp(W + 1, 0);

    for (int w = weights[0]; w <= W; w++) {
        dp[w] = values[0];
    }

    for (int i = 1; i < n; i++) {
        for (int w = W; w >= 0; w--) {  // iterate backwards to avoid overwriting dp[w - weights[i]]
            int notPick = dp[w];
            int pick = INT_MIN;
            if (weights[i] <= w)
                pick = values[i] + dp[w - weights[i]];
            dp[w] = max(pick, notPick);
        }
    }

    return dp[W];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> weights = {5, 3, 4};
    vector<int> values = {60, 40, 50};
    int maxWeight = 8;

    cout << "0/1 Knapsack (Memoization): "
         << knapsackMemo((int)weights.size() - 1, maxWeight, weights, values, vector<vector<int>>(weights.size(), vector<int>(maxWeight + 1, -1)))
         << "\n";

    cout << "0/1 Knapsack (Tabulation): " << knapsackTab(weights, values, maxWeight) << "\n";

    cout << "0/1 Knapsack (Space Optimized - Two Rows): " << knapsackSpaceOptTwoRows(weights, values, maxWeight) << "\n";

    cout << "0/1 Knapsack (Space Optimized - Single Array): " << knapsackSpaceOptSingleArray(weights, values, maxWeight) << "\n";

    return 0;
}