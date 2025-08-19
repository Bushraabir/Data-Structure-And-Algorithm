/*
 * Problem Statement: Max Consecutive Ones III
 *
 * You are given a binary array nums (containing only 0s and 1s) and an integer k. 
 * You can flip at most k zeros to ones. 
 * The task is to return the length of the longest subarray containing only 1s after performing at most k flips.
 *
 * Core Concept:
 * - This can be transformed into finding the longest subarray with at most k zeros.
 * - Use the Sliding Window technique with two pointers (L and R).
 * - Expand the window by moving R, and shrink it by moving L when the number of zeros exceeds k.
 *
 * Brute Force Solution (O(N^2)):
 * 1. Iterate with two nested loops (I for start, J for end).
 * 2. Keep track of zeros_count in [I...J].
 * 3. If zeros_count <= k, update max_length = max(max_length, J - I + 1).
 * 4. If zeros_count > k, break inner loop early.
 * 
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 *
 * Optimal Solution 1 (Sliding Window with inner loop):
 * 1. Initialize L=0, R=0, zeros=0, max_length=0.
 * 2. Iterate R from 0 to n-1:
 *    - If nums[R] == 0, increment zeros.
 *    - While zeros > k:
 *        - If nums[L] == 0, decrement zeros.
 *        - Increment L (shrink window).
 *    - Update max_length = max(max_length, R - L + 1).
 *
 * Time Complexity: O(N), because L and R each traverse at most N steps.
 * Space Complexity: O(1)
 *
 * Optimal Solution 2 (Sliding Window without inner loop, Most Optimal):
 * 1. Initialize L=0, zeros=0, max_length=0.
 * 2. Iterate R from 0 to n-1:
 *    - If nums[R] == 0, increment zeros.
 *    - If zeros > k:
 *        - If nums[L] == 0, decrement zeros.
 *        - Increment L by 1 (shrink window by one step).
 *    - Update max_length = max(max_length, R - L + 1).
 *
 * Key Insight:
 * - This version avoids the inner while loop, so it's cleaner.
 * - We only shrink the window by one step when zeros exceed k.
 *
 * Example:
 * nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * - Longest subarray after flipping at most 2 zeros = 6
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int L = 0, zeros = 0, max_length = 0;

    for (int R = 0; R < n; R++) {
        if (nums[R] == 0) zeros++;

        if (zeros > k) {
            if (nums[L] == 0) zeros--;
            L++; // shrink window by one
        }

        max_length = max(max_length, R - L + 1);
    }
    return max_length;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << "Longest subarray of 1s after flipping at most " << k << " zeros: "
         << longestOnes(nums, k) << endl;
    return 0;
}
