/*
 * Problem Statement: Maximum Points You Can Obtain from Cards
 *
 * You are given an array of card points and an integer K.
 * You must pick exactly K cards, but only from the front or back of the array.
 * The goal is to maximize the total number of points obtained.
 *
 * Core Concept:
 * - You can take cards from the left or right, but only consecutively.
 * - This means every possible choice of K cards is a combination of:
 *   (K from left, 0 from right), (K-1 from left, 1 from right), ..., (0 from left, K from right).
 * - Instead of recalculating sums from scratch, use a Sliding Window approach.
 *
 * Steps:
 * 1. Compute initial sum by taking all K cards from the left side (left_sum).
 *    - Set max_sum = left_sum.
 * 2. Now, slide the window:
 *    - Remove one card at a time from the left_sum (from the right end of left picks).
 *    - Add one card at a time from the right end of the array (into right_sum).
 *    - Update max_sum at each step with (left_sum + right_sum).
 * 3. Continue this until all possibilities are checked (K+1 possibilities).
 * 4. The result is the maximum possible sum.
 *
 * Example:
 * nums = [6, 2, 3, 4, 7, 1, 2], K = 4
 *
 * Initial: left_sum = 6+2+3+4 = 15, right_sum = 0, max_sum = 15
 * Iteration 1: remove 4, add 2 → left_sum=11, right_sum=2, total=13, max_sum=15
 * Iteration 2: remove 3, add 1 → left_sum=8, right_sum=3, total=11, max_sum=15
 * Iteration 3: remove 2, add 7 → left_sum=6, right_sum=10, total=16, max_sum=16
 * Iteration 4: remove 6, add 4 → left_sum=0, right_sum=14, total=14, max_sum=16
 * Final answer = 16
 *
 * Time Complexity:
 * - O(K): one pass to calculate left_sum, one pass to slide the window.
 * - Since K ≤ N, this is effectively O(N).
 *
 * Space Complexity:
 * - O(1): only variables for sums and result.
 */

#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& nums, int K) {
    int n = nums.size();
    int left_sum = 0, right_sum = 0, max_sum = 0;

    // Step 1: Take first K cards from the left
    for (int i = 0; i < K; i++) {
        left_sum += nums[i];
    }
    max_sum = left_sum;

    // Step 2: Slide the window by removing left cards and adding right cards
    int right_index = n - 1;
    for (int i = K - 1; i >= 0; i--) {
        left_sum -= nums[i];
        right_sum += nums[right_index];
        right_index--;

        max_sum = max(max_sum, left_sum + right_sum);
    }

    return max_sum;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> nums = {6, 2, 3, 4, 7, 1, 2};
    int K = 4;

    cout << "Maximum points from " << K << " cards: " << maxScore(nums, K) << endl;

    return 0;
}
