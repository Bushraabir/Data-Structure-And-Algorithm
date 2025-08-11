/*
Problem Statement:
- You are given an array of n positive integers.
- Task: Determine if it is possible to partition the array into two subsets such that the sum of elements in both subsets is equal.
- Return true if such a partition exists, otherwise false.

Why This is a DP Problem:
- We can reduce this problem to the "Subset Sum Equals to Target" problem.
- If the total sum of the array is S:
    - If S is odd → impossible to partition equally.
    - If S is even → check if there exists a subset with sum = S/2.
- Optimal substructure: Whether we can form sum = S/2 using the first i elements depends on including or excluding the current element.
- Overlapping subproblems: The same (index, target) states are recalculated multiple times.

Recurrence:
If (target == 0) return true
If (index == 0) return (arr[0] == target)
Else:
    notTake = f(index - 1, target)
    take = false
    if (arr[index] <= target) take = f(index - 1, target - arr[index])
    return (notTake || take)

Initial Call: f(n-1, S/2)

Time Complexity:
- Pure recursion: O(2^n)
- Memoization/Tabulation: O(n * (S/2))
- Space optimized: O(S/2)

Space Complexity:
- Memoization: O(n * (S/2)) + recursion stack O(n)
- Tabulation: O(n * (S/2))
- Space optimized: O(S/2)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
bool subsetSumMemo(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index == 0) return (arr[0] == target);
    if (dp[index][target] != -1) return dp[index][target];

    bool notTake = subsetSumMemo(index - 1, target, arr, dp);
    bool take = false;
    if (arr[index] <= target) take = subsetSumMemo(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = (notTake || take);
}

bool canPartitionMemo(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % 2 != 0) return false;
    int target = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return subsetSumMemo(n - 1, target, arr, dp);
}

/* -------------------- TABULATION -------------------- */
bool canPartitionTab(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % 2 != 0) return false;
    int k = totalSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
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

/* -------------------- SPACE OPTIMIZED -------------------- */
bool canPartitionSpaceOpt(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if (totalSum % 2 != 0) return false;
    int k = totalSum / 2;

    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
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

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> arr = {1, 5, 11, 5};

    cout << "Partition Equal Subset Sum (Memoization): "
         << (canPartitionMemo(arr) ? "true" : "false") << "\n";
    cout << "Partition Equal Subset Sum (Tabulation): "
         << (canPartitionTab(arr) ? "true" : "false") << "\n";
    cout << "Partition Equal Subset Sum (Space Optimized): "
         << (canPartitionSpaceOpt(arr) ? "true" : "false") << "\n";

    return 0;
}
