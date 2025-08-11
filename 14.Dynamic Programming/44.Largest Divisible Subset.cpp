#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
Problem:
Given a set of distinct positive integers, find the largest subset
such that for every pair (Si, Sj) in the subset:
    - Either Si % Sj == 0  OR  Sj % Si == 0

Example:
Input:  nums = [1, 16, 7, 8]
Output: [1, 8, 16]  (or [1, 16, 8] — order doesn't matter)

------------------------------------------------------------
Key Observations:
1. Order in a subset does NOT matter — so we can sort the array first.
2. After sorting, if nums[i] % nums[j] == 0 for j < i, 
   and nums[j] was divisible by all earlier elements in that chain,
   then nums[i] is automatically divisible by all those earlier elements.
   → This is the **transitive property** of divisibility.
3. This makes the problem equivalent to finding a 
   Longest Increasing Subsequence (LIS)-style chain,
   but with the condition "nums[i] % nums[j] == 0"
   instead of "nums[i] > nums[j]".

------------------------------------------------------------
Approach (O(N^2) DP, similar to LIS):
Step 1: Sort nums in ascending order.
Step 2: Create two arrays:
    - dp[i] = length of the largest divisible subset ending at index i.
    - hash[i] = index of the previous element in that subset (for reconstruction).
Step 3: Nested loops:
    For i from 0 to N-1:
        For j from 0 to i-1:
            If nums[i] % nums[j] == 0 AND dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                hash[i] = j
Step 4: Find index with maximum dp[i] → last index of the best subset.
Step 5: Backtrack using hash[] to reconstruct the subset.

Time Complexity:
    Sorting → O(N log N)
    Nested loops → O(N^2)
    Backtracking → O(N)
    Overall → O(N^2)
Space Complexity:
    O(N) for dp and hash arrays

------------------------------------------------------------
*/

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Initialize dp and hash arrays
    vector<int> dp(n, 1);    // Every element is a subset of length 1 by itself
    vector<int> hash(n);     // To reconstruct the path
    for (int i = 0; i < n; i++) {
        hash[i] = i;         // Initially, each element points to itself
    }

    // Track the overall best length and ending index
    int maxLen = 1;
    int lastIndex = 0;

    // Step 3: Fill dp[] using nested loops (LIS-style)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Check divisibility
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;  // Extend the chain
                hash[i] = j;        // Remember predecessor
            }
        }

        // Update global max if needed
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // Step 4: Reconstruct the subset using hash[]
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex) { // Until we reach the start element
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }

    // Step 5: The reconstructed subset is in reverse order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int> nums = {1, 16, 7, 8};
    vector<int> result = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
