/*
Problem Statement:
- You are given an array of positive integers 'nums'.
- You are also given an integer 'target' representing the desired sum.
- Task: Find the number of subsets in 'nums' that sum exactly to 'target'.
- Return the count of such subsets.

Why This is a DP Problem:
- At each element, you have two choices: pick it or not pick it.
- Overlapping subproblems arise because the same (index, sum) states repeat.
- Optimal substructure: Number of subsets for sum depends on smaller subproblems.

Recurrence:
f(index, sum) =
    if (sum == 0) return 1;  // empty subset counts as 1 way
    if (index == 0) {
        if (nums[0] == sum) return 1;
        else return 0;
    }
    notTake = f(index - 1, sum)
    take = 0
    if (nums[index] <= sum) take = f(index - 1, sum - nums[index])
    return notTake + take

Initial Call: f(n-1, target)

Time Complexity:
- Pure recursion: O(2^n)
- Memoization/Tabulation: O(n * target)
- Space optimized: O(target)

Space Complexity:
- Memoization: O(n * target) + recursion stack O(n)
- Tabulation: O(n * target)
- Space optimized: O(target)
*/

#include <bits/stdc++.h>
using namespace std;

/* -------------------- MEMOIZATION -------------------- */
int countSubsetsMemo(int index, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (sum == 0) return 1;
    if (index == 0) return (nums[0] == sum ? 1 : 0);
    if (dp[index][sum] != -1) return dp[index][sum];

    int notTake = countSubsetsMemo(index - 1, sum, nums, dp);
    int take = 0;
    if (nums[index] <= sum) take = countSubsetsMemo(index - 1, sum - nums[index], nums, dp);

    return dp[index][sum] = notTake + take;
}

int countSubsetsWithSumK_Memo(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countSubsetsMemo(n - 1, target, nums, dp);
}

/* -------------------- TABULATION -------------------- */
int countSubsetsWithSumK_Tab(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base cases: sum = 0 -> 1 way (empty subset)
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    // For index 0, if nums[0] <= target, then dp[0][nums[0]] = 1
    if (nums[0] <= target) dp[0][nums[0]] = 1;

    for (int index = 1; index < n; index++) {
        for (int sum = 0; sum <= target; sum++) {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if (nums[index] <= sum) take = dp[index - 1][sum - nums[index]];
            dp[index][sum] = notTake + take;
        }
    }

    return dp[n - 1][target];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int countSubsetsWithSumK_SpaceOpt(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    // Base case sum=0 => 1 way
    prev[0] = curr[0] = 1;

    if (nums[0] <= target) prev[nums[0]] = 1;

    for (int index = 1; index < n; index++) {
        for (int sum = 0; sum <= target; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (nums[index] <= sum) take = prev[sum - nums[index]];
            curr[sum] = notTake + take;
        }
        prev = curr;
    }

    return prev[target];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> nums = {1, 2, 2, 3};
    int target = 3;

    cout << "Count Subsets With Sum K (Memoization): "
         << countSubsetsWithSumK_Memo(nums, target) << "\n";

    cout << "Count Subsets With Sum K (Tabulation): "
         << countSubsetsWithSumK_Tab(nums, target) << "\n";

    cout << "Count Subsets With Sum K (Space Optimized): "
         << countSubsetsWithSumK_SpaceOpt(nums, target) << "\n";

    return 0;
}
