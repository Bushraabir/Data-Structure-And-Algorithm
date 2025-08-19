/*
 * Problem Statement: Sliding Window & Two Pointers Patterns
 *
 * Given an array or string, solve problems involving subarrays or substrings
 * efficiently using the Sliding Window or Two Pointers technique.
 *
 * Core Concept:
 * - Maintain a "window" with two pointers: L (left) and R (right).
 * - Expand the window by moving R, shrink it by moving L.
 * - Four main patterns are commonly encountered in interviews:
 *   1. Constant window size.
 *   2. Longest subarray/substring satisfying a condition.
 *   3. Count number of subarrays with a condition.
 *   4. Shortest/minimum window satisfying a condition.
 *
 * Patterns:
 * 1. Constant Window (Fixed Size K):
 *    - Calculate sum or other property of a window of size K.
 *    - Slide the window by removing the leftmost element and adding the next element.
 *    - Example: Maximum sum of K consecutive elements.
 *
 * 2. Longest Subarray/Substring with a Condition:
 *    - Goal: Find the maximum length window satisfying a condition.
 *    - Brute Force: O(N^2) using nested loops to check all subarrays.
 *    - Better (Sliding Window): O(2N) using L, R pointers, expanding R and shrinking L if condition is violated.
 *    - Optimal: O(N) when only length is needed; shrink L by one step if condition is violated.
 *
 * 3. Number of Subarrays with a Condition:
 *    - Count subarrays where a property holds, e.g., sum == K.
 *    - Typically solved using Pattern 2 logic:
 *       X = number of subarrays with sum <= K
 *       Y = number of subarrays with sum <= K-1
 *       Result = X - Y
 *
 * 4. Shortest/Minimum Window with a Condition:
 *    - Goal: Find smallest window satisfying a condition.
 *    - Expand R to build a valid window.
 *    - Shrink L to minimize while maintaining validity.
 *    - Keep track of minimum window length or indices.
 *
 * Steps (Generic Sliding Window Template):
 * 1. Initialize L = 0, R = 0, sum or counter variable as needed, max_length or min_length.
 * 2. Iterate R from 0 to n-1:
 *    a. Expand window: include element at R.
 *    b. While window violates condition, shrink from L:
 *       - Subtract element at L or update counter accordingly.
 *       - Increment L.
 *    c. Update max/min values as required.
 * 3. Return results (length, count, or window indices).
 *
 * Time Complexity:
 * - O(N) or O(2N) depending on pattern; each pointer traverses the array at most once.
 *
 * Space Complexity:
 * - O(1) if only length/count is needed, O(N) if storing window elements.
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// Pattern 2 Example: Longest Subarray with sum <= K
// ---------------------------
int longestSubarrayWithSumAtMostK(vector<int>& arr, int K) {
    int L = 0, R = 0, sum = 0, maxLen = 0;
    int n = arr.size();

    while(R < n) {
        sum += arr[R];

        while(sum > K) {
            sum -= arr[L];
            L++;
        }

        maxLen = max(maxLen, R - L + 1);
        R++;
    }

    return maxLen;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 8;

    int len = longestSubarrayWithSumAtMostK(arr, K);
    cout << "Longest subarray length with sum <= " << K << ": " << len << endl;

    return 0;
}
