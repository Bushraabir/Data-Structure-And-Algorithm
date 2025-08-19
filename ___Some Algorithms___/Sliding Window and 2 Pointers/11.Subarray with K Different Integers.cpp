/*
 * Problem Statement: Subarray with K Different Integers
 *
 * You are given an integer array nums and an integer K.
 * A subarray is called valid if it contains exactly K distinct integers.
 * The task is to return the total number of such subarrays.
 *
 * Core Concept:
 * - Subarrays are contiguous portions of the array.
 * - A subarray is valid if the count of unique (distinct) numbers in it equals K.
 * - Directly solving "exactly K distinct" with sliding window is tricky, 
 *   because when you shrink from the left you may miss subarrays.
 * - Key Insight:
 *     Instead of "exactly K", solve "at most K" and use:
 *     countExactlyK = countAtMostK - countAtMost(K-1).
 *
 * Brute Force Solution (O(N^2)):
 * 1. Iterate over all subarray starts (i).
 * 2. Extend end pointer (j) while maintaining a frequency map of elements.
 * 3. If the map.size() == K, increment count.
 * 4. If map.size() > K, break (no point extending further).
 *
 * Time Complexity: O(N^2) in worst case.
 * Space Complexity: O(N) for frequency map.
 *
 * Optimal Solution (Sliding Window, O(N)):
 * 1. Define a helper function countAtMost(nums, k) that counts subarrays 
 *    with at most k distinct integers.
 * 2. Use two pointers L and R for the sliding window.
 * 3. Expand R:
 *      - Add nums[R] into the map, increasing frequency.
 * 4. While map.size() > k:
 *      - Shrink window by removing nums[L] from the map.
 *      - If its frequency becomes 0, erase it from the map.
 *      - Increment L.
 * 5. At each step, add (R - L + 1) to count (all subarrays ending at R are valid).
 * 6. Finally, answer = countAtMost(nums, K) - countAtMost(nums, K - 1).
 *
 * Key Insight:
 * - Exactly-K problem can be reduced using "at most K" formula.
 *
 * Example:
 * nums = [1,2,1,2,3], K = 2
 * Answer = 7
 * Valid subarrays:
 * [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,3]
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N) (frequency map for distinct elements)
 */

#include <bits/stdc++.h>
using namespace std;

// helper function: count subarrays with at most k distinct numbers
int countAtMost(vector<int>& nums, int k) {
    if (k < 0) return 0;
    int L = 0, count = 0;
    unordered_map<int, int> freq;
    for (int R = 0; R < nums.size(); R++) {
        freq[nums[R]]++;
        while (freq.size() > k) {
            freq[nums[L]]--;
            if (freq[nums[L]] == 0) freq.erase(nums[L]);
            L++;
        }
        count += (R - L + 1);
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return countAtMost(nums, k) - countAtMost(nums, k - 1);
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << "Number of subarrays with exactly " << k << " distinct integers: "
         << subarraysWithKDistinct(nums, k) << endl;
    return 0;
}
