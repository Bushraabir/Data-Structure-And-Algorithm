/*
 * Problem Statement: Count Number of Nice Subarrays
 *
 * You are given an integer array nums and an integer K.
 * A subarray is called "nice" if it contains exactly K odd numbers.
 * The task is to return the total number of such "nice" subarrays.
 *
 * Core Concept:
 * - Subarrays are contiguous portions of the array.
 * - A subarray is valid if the count of odd numbers in it equals K.
 * - This problem is equivalent to the "Binary Subarrays With Sum" problem.
 *   Transformation:
 *     - Treat odd numbers as 1.
 *     - Treat even numbers as 0.
 *   Then, the problem reduces to:
 *     "Count subarrays with sum exactly equal to K" in the transformed binary array.
 *
 * Brute Force Solution (O(N^2)):
 * 1. Iterate over all possible subarray starts (i).
 * 2. For each start, extend end pointer (j), maintaining oddCount.
 * 3. If oddCount == K, increment count.
 * 4. Continue until oddCount > K (no need to extend further).
 *
 * Time Complexity: O(N^2)
 * Space Complexity: O(1)
 *
 * Optimal Solution (Sliding Window, O(N)):
 * 1. Define a helper function countAtMost(nums, k) that counts subarrays 
 *    with at most k odd numbers.
 * 2. Use two pointers L and R to represent a sliding window.
 * 3. Expand R:
 *      - Increment oddCount if nums[R] is odd.
 * 4. While oddCount > k, shrink window from left (L++) and decrement oddCount if nums[L] was odd.
 * 5. At each step, add (R - L + 1) to count (all subarrays ending at R are valid).
 * 6. Finally, answer = countAtMost(nums, K) - countAtMost(nums, K - 1).
 *
 * Key Insight:
 * - Exactly-K problem can be solved as: count(atMost K) - count(atMost K-1).
 * - The transformation nums[i] % 2 handles mapping odd→1, even→0.
 *
 * Example:
 * nums = [1,1,2,1,1], K = 3
 * Answer = 2
 * Valid subarrays: [1,1,2,1], [1,2,1,1]
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

// helper function: count subarrays with at most k odd numbers
int countAtMost(vector<int>& nums, int k) {
    if (k < 0) return 0; 
    int L = 0, oddCount = 0, count = 0;
    for (int R = 0; R < nums.size(); R++) {
        oddCount += nums[R] % 2; // odd -> 1, even -> 0
        while (oddCount > k) {
            oddCount -= nums[L] % 2;
            L++;
        }
        count += (R - L + 1);
    }
    return count;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return countAtMost(nums, k) - countAtMost(nums, k - 1);
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << "Number of nice subarrays with exactly " << k << " odd numbers: "
         << numberOfSubarrays(nums, k) << endl;
    return 0;
}
