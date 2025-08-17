#include <bits/stdc++.h>
using namespace std;

/*
======================================================================
    DP 54: Partition Array for Maximum Sum
======================================================================

PROBLEM STATEMENT:
------------------
Given:
    - An integer array `arr`
    - An integer `k` (maximum allowed partition length)

Goal:
    Partition the array into contiguous subarrays such that:
      1. Each subarray length ≤ k
      2. Replace all elements in a subarray with its maximum value
      3. Maximize the total sum after this transformation

Return:
    The maximum possible sum.

Example:
--------
    arr = [1,15,7,9,2,5,10], k = 3

    One optimal partition:
       [1,15,7] [9,2,5] [10]
       becomes: [15,15,15] [9,9,9] [10]
       sum = 45 + 27 + 10 = 82

======================================================================
    FRONT PARTITION DP APPROACH
======================================================================

The problem is similar to "Palindrome Partitioning - II" and uses the
"Front Partition" logic:

    We define:
        f(i) = Maximum sum we can get starting from index i

Recurrence:
-----------
    f(i) = max over all j from i to min(n-1, i+k-1):
              maxElem_in_segment * length_of_segment + f(j+1)

    - length_of_segment = j - i + 1
    - maxElem_in_segment = max(arr[i...j])
    - We take the maximum total sum possible

Base Case:
----------
    If i == n → return 0 (no elements left to partition)

======================================================================
*/

// ============================================================
//  MEMOIZATION (Top-Down DP)
// ============================================================

int solveMemo(int i, vector<int> &arr, int k, vector<int> &dp) {
    int n = arr.size();

    // Base case: No elements left
    if (i == n) return 0;

    // If already computed, return stored result
    if (dp[i] != -1) return dp[i];

    int maxSum = INT_MIN;     // Store the best sum for index i
    int maxElem = INT_MIN;    // Track maximum in the current segment
    int len = 0;              // Track segment length

    // Try all partition sizes from 1 to k (or until array ends)
    for (int j = i; j < min(n, i + k); j++) {
        len++;  // Current segment length
        maxElem = max(maxElem, arr[j]);  // Update max element in segment

        // Sum from this partition + best sum for remaining elements
        int sumForThisPartition = (len * maxElem) + solveMemo(j + 1, arr, k, dp);

        // Update the best answer
        maxSum = max(maxSum, sumForThisPartition);
    }

    // Store and return the result
    return dp[i] = maxSum;
}

int maxSumAfterPartitioningMemo(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);  // dp[i] = best sum from index i
    return solveMemo(0, arr, k, dp);
}

// ============================================================
//  TABULATION (Bottom-Up DP)
// ============================================================

int maxSumAfterPartitioningTab(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0); // dp[n] = 0 (base case)

    // Fill dp[] from back to front
    for (int i = n - 1; i >= 0; i--) {
        int maxSum = INT_MIN;
        int maxElem = INT_MIN;
        int len = 0;

        // Try all partitions starting at i
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxElem = max(maxElem, arr[j]);
            int sumForThisPartition = (len * maxElem) + dp[j + 1];
            maxSum = max(maxSum, sumForThisPartition);
        }

        dp[i] = maxSum;
    }

    return dp[0]; // The answer is best sum starting from index 0
}

/*
======================================================================
    COMPLEXITY ANALYSIS
======================================================================

Let:
    N = length of arr
    K = maximum partition length

Time Complexity:
    O(N*K)
    - For each index i (N states), we try up to K partitions

Space Complexity:
    Memoization: O(N) for dp[] + O(N) recursion stack
    Tabulation : O(N) for dp[], no recursion stack

======================================================================
*/


int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Max Sum (Memoization): " << maxSumAfterPartitioningMemo(arr, k) << "\n";
    cout << "Max Sum (Tabulation) : " << maxSumAfterPartitioningTab(arr, k) << "\n";

    return 0;
}
