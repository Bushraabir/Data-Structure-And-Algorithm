/*
Problem Statement:
- You are given an array of non-negative integers 'nums'.
- You are also given an integer 'D' representing the desired difference.
- Task: Partition the array into two subsets S1 and S2 such that:
    * S1 ∪ S2 = nums and S1 ∩ S2 = ∅ (disjoint subsets).
    * The difference of their sums is D: sum(S1) - sum(S2) = D.
- Return the count of such partitions.

Why This is a DP Problem:
- The problem can be transformed into counting subsets with a particular sum.
- Overlapping subproblems arise because the same (index, sum) states repeat.
- Optimal substructure: Number of partitions depends on solutions to smaller subproblems.

Key Insight / Transformation:
- Let totalSum = sum of all elements in nums.
- We have sum(S1) + sum(S2) = totalSum and sum(S1) - sum(S2) = D.
- Solving gives sum(S2) = (totalSum - D) / 2.
- Thus, count partitions reduces to counting subsets with sum = (totalSum - D) / 2.
- If (totalSum - D) is negative or odd, no valid partitions exist (return 0).

Handling Zeros (Correction over DP17):
- When nums contains zeros, subsets that include zeros can multiply the count (each zero doubles count).
- Base cases for index == 0:
    * If target == 0 and nums[0] == 0: return 2 (take or not take zero).
    * Else if target == 0: return 1 (not take element).
    * Else if target == nums[0]: return 1 (take element).
    * Else return 0.

Recurrence (with modulo arithmetic):
f(index, sum) =
    if index == 0:
        if sum == 0 and nums[0] == 0: return 2
        else if sum == 0: return 1
        else if sum == nums[0]: return 1
        else return 0

    notTake = f(index - 1, sum) % MOD
    take = 0
    if nums[index] <= sum: take = f(index - 1, sum - nums[index]) % MOD

    return (notTake + take) % MOD

Initial Call: f(n-1, new_target) where new_target = (totalSum - D) / 2

Time Complexity:
- Memoization/Tabulation: O(n * target)
- Space optimized: O(target)

Space Complexity:
- Memoization: O(n * target) + recursion stack O(n)
- Tabulation: O(n * target)
- Space optimized: O(target)
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

/* -------------------- MEMOIZATION -------------------- */
int countPartitionsWithSumMemo(int index, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if (index == 0) {
        if (sum == 0 && nums[0] == 0) return 2;
        if (sum == 0) return 1;
        if (sum == nums[0]) return 1;
        return 0;
    }

    if (dp[index][sum] != -1) return dp[index][sum];

    int notTake = countPartitionsWithSumMemo(index - 1, sum, nums, dp) % MOD;
    int take = 0;
    if (nums[index] <= sum)
        take = countPartitionsWithSumMemo(index - 1, sum - nums[index], nums, dp) % MOD;

    return dp[index][sum] = (notTake + take) % MOD;
}

int countPartitionsWithGivenDiff(vector<int>& nums, int D) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Edge case checks
    if (totalSum < D || (totalSum - D) % 2 != 0) return 0;

    int target = (totalSum - D) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countPartitionsWithSumMemo(n - 1, target, nums, dp);
}

/* -------------------- TABULATION -------------------- */
int countPartitionsWithGivenDiff_Tab(vector<int>& nums, int D) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum < D || (totalSum - D) % 2 != 0) return 0;

    int target = (totalSum - D) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base cases for index=0
    if (nums[0] == 0) dp[0][0] = 2;        // take or not take zero
    else dp[0][0] = 1;                      // not take element

    if (nums[0] != 0 && nums[0] <= target)
        dp[0][nums[0]] = 1;                 // take element if <= target

    for (int index = 1; index < n; index++) {
        for (int sum = 0; sum <= target; sum++) {
            int notTake = dp[index - 1][sum];
            int take = 0;
            if (nums[index] <= sum)
                take = dp[index - 1][sum - nums[index]];
            dp[index][sum] = (notTake + take) % MOD;
        }
    }
    return dp[n - 1][target];
}

/* -------------------- SPACE OPTIMIZED -------------------- */
int countPartitionsWithGivenDiff_SpaceOpt(vector<int>& nums, int D) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum < D || (totalSum - D) % 2 != 0) return 0;

    int target = (totalSum - D) / 2;

    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    if (nums[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= target)
        prev[nums[0]] = 1;

    for (int index = 1; index < n; index++) {
        curr[0] = 1; // sum=0 can always be formed by not taking any element except the zero case handled already
        for (int sum = 1; sum <= target; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (nums[index] <= sum)
                take = prev[sum - nums[index]];
            curr[sum] = (notTake + take) % MOD;
        }
        prev = curr;
    }

    return prev[target];
}

/* -------------------- MAIN -------------------- */
int main() {
    vector<int> nums = {1, 1, 2, 3};
    int D = 1;

    cout << "Count Partitions With Given Difference (Memoization): "
         << countPartitionsWithGivenDiff(nums, D) << "\n";

    cout << "Count Partitions With Given Difference (Tabulation): "
         << countPartitionsWithGivenDiff_Tab(nums, D) << "\n";

    cout << "Count Partitions With Given Difference (Space Optimized): "
         << countPartitionsWithGivenDiff_SpaceOpt(nums, D) << "\n";

    return 0;
}
