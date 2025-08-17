/*
Greedy Algorithm – Jump Game II (Minimum Number of Jumps)

Intuition & Logic:
- Given an array where each element represents max jump length from that position.
- Start at index 0, goal is to reach last index using minimum jumps.
- It is guaranteed you can reach the end.
- Greedy choice:
    - Track the current range of indices reachable with the current number of jumps ([L, R]).
    - Within this range, find the farthest position reachable by one more jump.
    - Once you've explored current range, increment jumps and update the range to the farthest reachable.
- This level-by-level range expansion ensures minimum jumps.

Problem Example:
- Array: [2, 3, 1, 1, 4]
- Jump 1: from index 0 (value 2), range [0,0], farthest = max(0+2) = 2
- Update range to [1, 2], jumps = 1
- Jump 2: from indices 1,2, farthest = max(1+3, 2+1) = 4 (last index)
- Update range to [3, 4], jumps = 2
- Reached end in 2 jumps

Algorithm:
- Initialize jumps = 0, L = 0, R = 0
- While R < last index:
    - farthest = 0
    - For i in [L, R]:
        - farthest = max(farthest, i + nums[i])
    - jumps++
    - L = R + 1
    - R = farthest
- Return jumps

TIME & SPACE COMPLEXITY:
- Time: O(N), each element visited once.
- Space: O(1), constant extra space.

*/

/* -------------------- JUMP GAME II IMPLEMENTATION -------------------- */

#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = (int)nums.size();
    int jumps = 0, L = 0, R = 0;

    while (R < n - 1) {
        int farthest = 0;
        for (int i = L; i <= R; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        jumps++;
        L = R + 1;
        R = farthest;
    }

    return jumps;
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Minimum jumps needed: " << jump(nums1) << "\n"; // Output: 2

    vector<int> nums2 = {2, 1, 2, 0, 1};
    cout << "Minimum jumps needed: " << jump(nums2) << "\n"; // Output: 3

    return 0;
}

