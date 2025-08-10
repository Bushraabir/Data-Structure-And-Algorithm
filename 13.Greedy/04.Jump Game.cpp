/*
Greedy Algorithm – Jump Game Problem

Intuition & Logic:
- Given an array where each element represents the max jump length from that position.
- Start at index 0, goal is to reach the last index.
- Challenge: If stuck on a zero or can't reach a position before a zero, you fail.
- Greedy choice:
    - Track the farthest index reachable at any point.
    - If current index exceeds max reachable, return false (stuck).
    - If max reachable reaches or exceeds last index, return true (success).
- This approach efficiently checks reachability in one pass.

Problem Example:
- Array: [1, 2, 3, 1, 1, 0, 2]
- max_reach progresses: 0→1→3→5→5→5→...
- At index 6 (value 2), index > max_reach → cannot reach, return false.

Algorithm:
- Initialize max_reach = 0.
- For each index i in array:
    - If i > max_reach, return false.
    - Update max_reach = max(max_reach, i + nums[i]).
    - If max_reach >= last index, return true early.
- If loop completes, return true.

TIME & SPACE COMPLEXITY:
- Time: O(N), one pass through array.
- Space: O(1), constant extra space.

*/

/* -------------------- JUMP GAME IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int max_reach = 0;
    int n = (int)nums.size();

    for (int i = 0; i < n; i++) {
        if (i > max_reach) return false;  // Can't reach this position
        max_reach = max(max_reach, i + nums[i]);
        if (max_reach >= n - 1) return true; // Can reach or surpass end
    }

    return true;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> nums1 = {2, 1, 3, 1, 1, 0, 2};
    cout << boolalpha << canJump(nums1) << "\n"; // Output: false

    vector<int> nums2 = {2, 3, 1, 1, 4};
    cout << boolalpha << canJump(nums2) << "\n"; // Output: true

    return 0;
}
