/*
Problem Statement:
- You are given an array of n integers, where each integer represents the amount of money in a house.
- All houses are arranged in a **circle**, meaning:
    - The first house is adjacent to the last house.
    - Adjacent houses cannot both be robbed (security alarm triggers).
- You need to find the **maximum amount of money** you can rob without alerting the police.

Example:
arr = {2, 3, 2}
Possible picks (circular constraint):
    - Rob house 0 and house 2 → NOT ALLOWED (adjacent in circle)
    - Rob house 0 → sum = 2
    - Rob house 1 → sum = 3 (maximum)
Answer: 3

Why This is a DP Problem:
- We want the **maximum** sum under adjacency constraints.
- Overlapping subproblems: same subarray segments considered multiple times.
- Optimal substructure: best sum for a subarray depends on smaller subarrays.

Key Insight (Difference from House Robber 1):
- In House Robber 1 (linear), we could rob first and last houses separately.
- In House Robber 2 (circular), **first and last houses are adjacent**, so:
    1. Either rob houses from index 0 to n-2 (exclude last house).
    2. Or rob houses from index 1 to n-1 (exclude first house).
- Solve both using House Robber 1 logic and take the maximum.

Recurrence Relation (Pick / Not Pick):
Let f(index) = maximum sum of non-adjacent houses from 0 to index (linear case).

Options:
1. Pick current house arr[index]:
    - Must skip previous house (index-1), so add f(index-2)
    pick_sum = arr[index] + f(index-2)
2. Do not pick current house:
    - Can take the best till index-1
    not_pick_sum = f(index-1)

Formula:
f(index) = max(
    arr[index] + f(index-2), 
    0 + f(index-1)
)

Base Cases:
- f(0) = arr[0]
- f(index) = 0 if index < 0

Time Complexity:
- O(N) for each run of House Robber 1
- Total O(N) since we run twice
Space Complexity:
- Space optimized O(1)
*/

/* -------------------- LINEAR ROBBER (Space Optimized) -------------------- */
#include <bits/stdc++.h>
using namespace std;

int robLinear(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return arr[0];

    int prev = arr[0], prev2 = 0;

    for (int i = 1; i < n; i++) {
        int pick = arr[i] + (i > 1 ? prev2 : 0);
        int notPick = prev;
        int cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

/* -------------------- CIRCULAR ROBBER (House Robber 2) -------------------- */
int robCircular(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0]; // Edge case

    // Exclude last house
    vector<int> temp1(arr.begin(), arr.end() - 1);
    // Exclude first house
    vector<int> temp2(arr.begin() + 1, arr.end());

    return max(robLinear(temp1), robLinear(temp2));
}

/* -------------------- MAIN FUNCTION -------------------- */
int main() {
    vector<int> arr = {2, 3, 2};
    cout << "Max Rob Amount: " << robCircular(arr) << "\n";
    return 0;
}
