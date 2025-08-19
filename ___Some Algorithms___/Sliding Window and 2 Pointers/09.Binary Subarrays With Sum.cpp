/*
 * Problem Statement: Binary Subarrays With Sum
 *
 * You are given a binary array nums (containing only 0s and 1s) and an integer goal.
 * The task is to return the number of subarrays such that the sum of elements in that subarray
 * is exactly equal to the given goal.
 *
 * Core Concept:
 * - Subarrays are contiguous parts of the array.
 * - Directly counting all subarrays with sum == goal using two pointers is tricky 
 *   because zeros at the start of a subarray don’t affect the sum.
 * - Instead, compute:
 *   countSubarraysWithSum(goal) 
 *       = countSubarraysWithSumLessThanOrEqualTo(goal) 
 *       - countSubarraysWithSumLessThanOrEqualTo(goal - 1).
 *
 * Brute Force Solution (O(N^2)):
 * 1. Iterate over all possible subarray starts (i).
 * 2. For each start, extend end pointer (j), maintaining running sum.
 * 3. If running sum == goal, increment count.
 * 4. Continue until sum exceeds goal (since all values are non-negative).
 *
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 *
 * Optimal Solution (Sliding Window, O(N)):
 * 1. Define a helper function countAtMost(nums, k) that counts subarrays with sum <= k.
 * 2. Use two pointers L and R, expand window with R.
 * 3. Keep currentSum of window nums[L..R].
 * 4. While currentSum > k, shrink from left (L++).
 * 5. At each step, add (R - L + 1) to count (all subarrays ending at R are valid).
 * 6. Return countAtMost(goal) - countAtMost(goal - 1).
 *
 * Key Insight:
 * - For binary arrays, subarray sums are non-decreasing with R.
 * - Zeros do not affect sums but extend window size, which naturally gets counted.
 *
 * Example:
 * nums = [1,0,1,0,1], goal = 2
 * Answer = 4
 * Valid subarrays: [1,0,1], [0,1,0,1], [1,0,1], [1,0,1,0,1]
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

// helper function: count subarrays with sum <= k
int countAtMost(vector<int>& nums, int k) {
    if (k < 0) return 0; // edge case: binary array can't have negative sums
    int L = 0, currentSum = 0, count = 0;
    for (int R = 0; R < nums.size(); R++) {
        currentSum += nums[R];
        while (currentSum > k) {
            currentSum -= nums[L];
            L++;
        }
        count += (R - L + 1);
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << "Number of subarrays with sum " << goal << ": "
         << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
