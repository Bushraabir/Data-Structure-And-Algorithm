/*
Problem Statement:
- Given an array of n integers.
- You need to find the **maximum sum of a subsequence** such that 
  no two elements picked are adjacent in the original array.

Example:
arr = {2, 1, 4, 9}
Possible picks:
    {2, 4} → sum = 6
    {2, 9} → sum = 11 (maximum)
    {1, 9} → sum = 10
Answer: 11

Why This is a DP Problem:
- We want the **maximum** sum over all valid subsequences.
- Overlapping subproblems: same index considered in different subsequences.
- Optimal substructure: best sum for index i depends only on earlier indices.

Recurrence Relation (Pick / Not Pick):
Let f(index) = maximum sum of non-adjacent elements from 0 to index.

Options:
1. Pick current element arr[index]:
    - Must skip previous element (index-1), so add f(index-2)
    pick_sum = arr[index] + f(index-2)
2. Do not pick current element:
    - Can take the best till index-1
    not_pick_sum = f(index-1)

Formula:
f(index) = max(
    arr[index] + f(index-2), 
    0 + f(index-1)
)

Base Cases:
- f(0) = arr[0]
- f(index) = 0 if index < 0

Time Complexity:
- Memoization: O(N)
- Tabulation: O(N)
Space Complexity:
- Memoization: O(N) + O(N) recursion stack
- Tabulation: O(N)
- Space Optimized: O(1)
*/

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int maxSumMemo(int index, vector<int>& arr, vector<int>& dp) {
    if (index == 0) return arr[0];
    if (index < 0) return 0;
    if (dp[index] != -1) return dp[index];

    int pick = arr[index] + maxSumMemo(index - 2, arr, dp);
    int notPick = 0 + maxSumMemo(index - 1, arr, dp);

    return dp[index] = max(pick, notPick);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
int maxSumTab(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1) pick += dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

/* -------------------- SPACE OPTIMIZATION -------------------- */
int maxSumSpaceOpt(vector<int>& arr) {
    int n = arr.size();
    int prev = arr[0], prev2 = 0;

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1) pick += prev2;
        int notPick = prev;
        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

/* -------------------- MAIN FUNCTION -------------------- */
int main() {
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();

    // Memoization
    vector<int> dp(n, -1);
    cout << "Max Sum (Memoization): " 
         << maxSumMemo(n - 1, arr, dp) << "\n";

    // Tabulation
    cout << "Max Sum (Tabulation): " 
         << maxSumTab(arr) << "\n";

    // Space Optimization
    cout << "Max Sum (Space Optimized): " 
         << maxSumSpaceOpt(arr) << "\n";

    return 0;
}
