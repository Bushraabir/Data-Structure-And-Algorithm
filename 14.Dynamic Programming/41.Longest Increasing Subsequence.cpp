#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------
Problem: Longest Increasing Subsequence (LIS) - Memoization
--------------------------------------------------------------

1. Understanding the Problem:
   - We are given an array of integers.
   - We need to find the length of the longest subsequence such that 
     all elements of the subsequence are strictly increasing.
   - A subsequence is formed by deleting some or no elements without 
     changing the order of the remaining elements.

2. Recursion Idea:
   - At each index, we have two choices:
     a) Take the element (if it is greater than the previously taken element).
     b) Not take the element (skip it).
   - This is the "Take / Not Take" pattern.

3. State Definition:
   f(index, prev_index):
     - index → current position in the array.
     - prev_index → index of the last element we took in the subsequence.
       Initially, prev_index = -1 meaning we have not taken any element yet.

4. Transition:
   - Not Take:
        length = f(index + 1, prev_index)
   - Take (if nums[index] > nums[prev_index] OR prev_index == -1):
        length = 1 + f(index + 1, index)

5. Answer:
   - Start with f(0, -1).

6. Memoization:
   - dp[index][prev_index + 1] → shifting prev_index by +1 to handle -1.
   - This avoids recalculating overlapping subproblems.

7. Time Complexity:
   - O(n * n) because:
       index → 0 to n-1  (n states)
       prev_index → -1 to n-1 (n+1 states)
   - Each state is computed once.

8. Space Complexity:
   - O(n * n) for the dp array
   - O(n) recursion stack space.
   - Not optimal for n up to 1e5 (memory issue).
--------------------------------------------------------------
*/

// Recursive function with memoization
int solve(int index, int prev_index, vector<int> &nums, vector<vector<int>> &dp) {
    // Base case: reached the end of the array
    if (index == nums.size()) {
        return 0;
    }

    // Check memoization table
    if (dp[index][prev_index + 1] != -1) {
        return dp[index][prev_index + 1];
    }

    // Option 1: Not Take current element
    int notTake = solve(index + 1, prev_index, nums, dp);

    // Option 2: Take current element (if allowed)
    int take = 0;
    if (prev_index == -1 || nums[index] > nums[prev_index]) {
        take = 1 + solve(index + 1, index, nums, dp);
    }

    // Store and return the best answer
    return dp[index][prev_index + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    // dp array size: n x (n+1), initialized with -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, -1, nums, dp);
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of LIS: " << lengthOfLIS(nums) << endl;

    return 0;
}

