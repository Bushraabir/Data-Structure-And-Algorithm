#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Number of Longest Increasing Subsequences
    --------------------------------------------------
    We are given an integer array. We need to:
        1. Find the length of the Longest Increasing Subsequence (LIS).
        2. Count how many subsequences exist that have that maximum length.

    Key Idea:
        - This is a variation of LIS (DP 42) but with an extra "count" array.
        - dp[i]   -> length of the LIS ending at index i
        - count[i] -> number of LIS of length dp[i] that end at index i

    Steps:
        1. Initialize dp[i] = 1, count[i] = 1 for all i (each element forms LIS of length 1 in one way).
        2. Iterate over all pairs (j, i) where j < i.
        3. If nums[i] > nums[j], we can extend LIS ending at j to i:
            Case 1: Found longer LIS ending at i
                - dp[i] = dp[j] + 1
                - count[i] = count[j] (inherit the count from j)
            Case 2: Found another way to get same length LIS ending at i
                - dp[i] stays same
                - count[i] += count[j] (add the ways from j)
        4. After filling dp[] and count[], find maxLen = max(dp).
        5. Sum all count[i] where dp[i] == maxLen → this is the answer.
*/

int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);      // dp[i] = length of LIS ending at i
    vector<int> count(n, 1);   // count[i] = number of LIS ending at i

    int maxLen = 1; // track maximum length of LIS found

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // Case 1: We found a longer LIS by extending j -> i
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;   // update length
                    count[i] = count[j]; // inherit ways from j
                }
                // Case 2: We found another LIS of same length ending at i
                else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j]; // add the ways from j
                }
            }
        }
        // Track global maximum LIS length
        maxLen = max(maxLen, dp[i]);
    }

    // Count how many LIS have length maxLen
    int numberOfLIS = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) {
            numberOfLIS += count[i];
        }
    }

    return numberOfLIS;
}

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};

    /*
        Example:
            LIS length = 4
            LIS are: {1,3,5,7}, {1,3,4,7}
            Answer = 2
    */

    cout << "Number of Longest Increasing Subsequences: "
         << findNumberOfLIS(nums) << endl;

    return 0;
}
