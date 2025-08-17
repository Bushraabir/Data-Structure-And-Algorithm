/*
Problem Statement:
- You are given an array of n positive integers and a target integer.
- Task: Count the number of ways to assign '+' or '-' signs to each element 
  so that the resulting sum equals the given target.

Why This is a DP Problem:
- Assigning signs effectively splits the array into two subsets:
    s1 = subset with '+' sign elements
    s2 = subset with '-' sign elements
- We have: sum(s1) - sum(s2) = target
- Also, sum(s1) + sum(s2) = totalSum of the array
- Adding the two equations:
    2 * sum(s1) = totalSum + target
    sum(s1) = (totalSum + target) / 2
- This reduces the problem to: 
    Count subsets with sum = (totalSum + target) / 2.
- Optimal substructure: 
    Number of ways to form a target sum using first i elements depends 
    on including or excluding the current element.
- Overlapping subproblems:
    Same (index, target) pairs are recalculated multiple times in recursion.

Recurrence:
If (index == 0):
    if (target == 0 && arr[0] == 0) return 2 // two ways: take or not take
    if (target == 0 || arr[0] == target) return 1
    return 0
Else:
    notTake = f(index - 1, target)
    take = 0
    if (arr[index] <= target) take = f(index - 1, target - arr[index])
    return take + notTake

Initial Call:
f(n-1, subsetSumTarget)

Time Complexity:
- Pure recursion: O(2^n)
- Memoization/Tabulation: O(n * subsetSumTarget)
- Space optimized: O(subsetSumTarget)

Space Complexity:
- Memoization: O(n * subsetSumTarget) + recursion stack O(n)
- Tabulation: O(n * subsetSumTarget)
- Space optimized: O(subsetSumTarget)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int countSubsetsMemo(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }
    if (dp[index][target] != -1) return dp[index][target];

    int notTake = countSubsetsMemo(index - 1, target, arr, dp);
    int take = 0;
    if (arr[index] <= target)
        take = countSubsetsMemo(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = take + notTake;
}

int targetSumMemo(vector<int>& arr, int target) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) return 0;
    int subsetSumTarget = (totalSum + target) / 2;
    vector<vector<int>> dp(arr.size(), vector<int>(subsetSumTarget + 1, -1));
    return countSubsetsMemo(arr.size() - 1, subsetSumTarget, arr, dp);
}

/* -------------------- TABULATION -------------------- */
int targetSumTab(vector<int>& arr, int target) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) return 0;
    int k = (totalSum + target) / 2;

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if (arr[0] == 0) dp[0][0] = 2; 
    else dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for (int index = 1; index < n; index++) {
        for (int sum = 0; sum <= k; sum++) {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if (arr[index] <= sum)
                take = dp[index - 1][sum - arr[index]];
            dp[index][sum] = take + notTake;
        }
    }
    return dp[n - 1][k];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int targetSumSpaceOpt(vector<int>& arr, int target) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) return 0;
    int k = (totalSum + target) / 2;

    vector<int> prev(k + 1, 0), curr(k + 1, 0);

    if (arr[0] == 0) prev[0] = 2; 
    else prev[0] = 1;

    if (arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

    for (int index = 1; index < arr.size(); index++) {
        for (int sum = 0; sum <= k; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (arr[index] <= sum)
                take = prev[sum - arr[index]];
            curr[sum] = take + notTake;
        }
        prev = curr;
    }
    return prev[k];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> arr = {1, 1, 2, 3};
    int target = 1;

    cout << "Target Sum (Memoization): "
         << targetSumMemo(arr, target) << "\n";
    cout << "Target Sum (Tabulation): "
         << targetSumTab(arr, target) << "\n";
    cout << "Target Sum (Space Optimized): "
         << targetSumSpaceOpt(arr, target) << "\n";

    return 0;
}
