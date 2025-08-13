/*
Find First and Last Position of Element in Sorted Array
-------------------------------------------------------

This algorithm finds the **first** and **last** positions of a target value in a sorted array
in O(log N) time using **two binary searches** — one for the first occurrence, one for the last.

It is useful when:
- The array is sorted in non-decreasing order.
- You need to find the range of duplicate values.
- Performance matters (linear scan O(N) is too slow).

Definition:
Given a sorted array of size N and a target value X:
1. Use binary search to find the **leftmost index** of X.
2. Use binary search to find the **rightmost index** of X.
3. If X does not exist, return [-1, -1].

Example:
Array: [5,7,7,8,8,10]
Target: 8

Process:
First search (first occurrence):
    Step 1: low=0, high=5, mid=2 → nums[2]=7 (<8) → search right
    Step 2: low=3, high=5, mid=4 → nums[4]=8 (>=8) → search left
    Step 3: low=3, high=3, mid=3 → nums[3]=8 (>=8) → search left
    Step 4: low=3, high=2 → stop → first index = 3

Second search (last occurrence):
    Step 1: low=0, high=5, mid=2 → nums[2]=7 (<=8) → search right
    Step 2: low=3, high=5, mid=4 → nums[4]=8 (<=8) → search right
    Step 3: low=5, high=5, mid=5 → nums[5]=10 (>8) → search left
    Step 4: low=5, high=4 → stop → last index = 4

Result: [3, 4]

Working Principle:
1. Initialize ans = [-1, -1].
2. Binary search #1 (find first occurrence):
    - If nums[mid] >= target → move `high = mid - 1`.
    - Else → move `low = mid + 1`.
    - If nums[mid] == target → store in ans[0].
3. Binary search #2 (find last occurrence):
    - If nums[mid] <= target → move `low = mid + 1`.
    - Else → move `high = mid - 1`.
    - If nums[mid] == target → store in ans[1].
4. Return ans.

Time Complexity:
    - Best Case: O(log N) → Found quickly in middle.
    - Worst Case: O(log N) → Binary search both sides.

Space Complexity:
    - O(1) extra space.

Constraints:
- Array must be sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) return ans;

        // First occurrence (left bound)
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
            if (nums[mid] == target) ans[0] = mid;
        }

        // Last occurrence (right bound)
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) low = mid + 1;
            else high = mid - 1;
            if (nums[mid] == target) ans[1] = mid;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    Solution sol;
    vector<int> res = sol.searchRange(nums, target);

    cout << "Array: ";
    for (int v : nums) cout << v << " ";
    cout << "\nTarget: " << target << "\n";
    cout << "First and Last Positions: [" << res[0] << ", " << res[1] << "]\n";

    return 0;
}

/*
Example Dry Run:
----------------
Array: [5,7,7,8,8,10]
Target: 8

First occurrence search:
low=0, high=5 → mid=2 → nums[2]=7 (<8) → low=3
low=3, high=5 → mid=4 → nums[4]=8 (>=8) → high=3 → ans[0]=4
low=3, high=3 → mid=3 → nums[3]=8 (>=8) → high=2 → ans[0]=3
Done → ans[0]=3

Last occurrence search:
low=0, high=5 → mid=2 → nums[2]=7 (<=8) → low=3
low=3, high=5 → mid=4 → nums[4]=8 (<=8) → low=5 → ans[1]=4
low=5, high=5 → mid=5 → nums[5]=10 (>8) → high=4
Done → ans[1]=4

Output: [3,4]
*/
