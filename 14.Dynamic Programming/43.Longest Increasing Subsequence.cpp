#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------------------
Problem:
Given an array of integers, find the length of the 
Longest Increasing Subsequence (LIS).

We want an O(N log N) solution because:
- O(N^2) will TLE for N up to 1e5.
- We avoid generating all subsequences.
- We only track a "representative" sequence in a
  temporary array (temp) to compute LIS length.

Key Ideas:
1. "temp" is NOT the actual LIS — it only stores the 
   smallest possible tail element for subsequences of
   each length.
2. When a new element x comes:
   - If x > last element in temp → append (increase LIS length).
   - Else → find the position of the first element >= x in temp 
     (binary search) and replace it with x (overwrite).
3. Replacing is safe because:
   - We keep a smaller tail value for subsequences of that length,
     making it easier to extend in the future.

Example Walkthrough:
arr = [1, 7, 8, 4, 5, 6, -1, 9]

Step-by-step:
1 → temp = [1]                     // start
7 → temp = [1, 7]                   // append (7 > 1)
8 → temp = [1, 7, 8]                // append (8 > 7)
4 → temp = [1, 4, 8]                // replace 7 with 4
5 → temp = [1, 4, 5]                // replace 8 with 5
6 → temp = [1, 4, 5, 6]              // append
-1 → temp = [-1, 4, 5, 6]            // replace 1 with -1
9 → temp = [-1, 4, 5, 6, 9]          // append
Length of LIS = temp.size() = 5

Why "temp" works:
- The array remains sorted.
- Binary search is possible.
- A smaller element in a position means better chance 
  of extension for future numbers.

Complexity:
- Time: O(N log N) → N iterations, binary search each time.
- Space: O(N) for temp.
----------------------------------------------------
*/

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;

    vector<int> temp; // stores the smallest possible tail for subsequences of each length
    temp.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > temp.back()) {
            // Case 1: nums[i] extends the largest subsequence
            temp.push_back(nums[i]);
        } else {
            // Case 2: nums[i] could replace an element in temp
            // Find first element >= nums[i]
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            *it = nums[i]; // overwrite
        }
    }

    return temp.size(); // length of LIS
}

// ---------------- Main ----------------
int main() {
    vector<int> arr = {1, 7, 8, 4, 5, 6, -1, 9};
    cout << "Length of LIS: " << lengthOfLIS(arr) << "\n";
    return 0;
}
