/*
Problem Statement:
- You are given an array of n positive integers and an integer k (target).
- Task: Check if there exists any subset in the array whose elements sum up to k. Return true if such a subset exists, otherwise false.

Why This is a DP Problem:
- Optimal substructure: Whether a subset sums to k from index i depends on including or excluding the element at index i and solving for the remaining elements.
- Overlapping subproblems: The same (index, target) states are computed multiple times in recursion.
- Define f(index, target) = true if a subset from index 0 to index sums to target, false otherwise.

Recurrence:
If (target == 0) return true
If (index == 0) return (arr[0] == target)
Else:
    notTake = f(index - 1, target)
    take = false
    if (arr[index] <= target) take = f(index - 1, target - arr[index])
    return (notTake || take)

Initial Call: f(n-1, k)

Time Complexity:
- Pure recursion: O(2^n)
- Memoization/Tabulation: O(n*k)
- Space optimized: O(n*k)

Space Complexity:
- Memoization: O(n*k) + recursion stack O(n)
- Tabulation: O(n*k)
- Space optimized: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION (Top-Down) -------------------- */
bool solveMemo(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index == 0) return (arr[0] == target);
    if (dp[index][target] != -1) return dp[index][target];

    bool notTake = solveMemo(index - 1, target, arr, dp);
    bool take = false;
    if (arr[index] <= target) take = solveMemo(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = (notTake || take);
}

/* -------------------- TABULATION (Bottom-Up) -------------------- */
bool solveTab(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: target = 0
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // Base case: index = 0
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int index = 1; index < n; index++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[index - 1][target];
            bool take = false;
            if (arr[index] <= target) take = dp[index - 1][target - arr[index]];
            dp[index][target] = (notTake || take);
        }
    }
    return dp[n - 1][k];
}

/* -------------------- SPACE OPTIMIZED (O(k) extra space) -------------------- */
bool solveSpaceOpt(vector<int>& arr, int k) {
    int n = arr.size();
    vector<bool> prev(k + 1, false), curr(k + 1, false);

    // Base case: target = 0
    prev[0] = curr[0] = true;

    // Base case: index = 0
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int index = 1; index < n; index++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[index] <= target) take = prev[target - arr[index]];
            curr[target] = (notTake || take);
        }
        prev = curr;
    }
    return prev[k];
}

/* -------------------- MAIN function -------------------- */
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    // Memoization
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << "Subset Sum (Memoization): " << (solveMemo(n - 1, k, arr, dp) ? "true" : "false") << "\n";

    // Tabulation
    cout << "Subset Sum (Tabulation): " << (solveTab(arr, k) ? "true" : "false") << "\n";

    // Space Optimized
    cout << "Subset Sum (Space Optimized): " << (solveSpaceOpt(arr, k) ? "true" : "false") << "\n";

    return 0;
}