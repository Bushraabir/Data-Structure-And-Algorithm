/*
Rotated Binary Search is an extension of standard binary search
for finding a target element in a **rotated sorted array** 
in O(log N) time by identifying the sorted half in each iteration.

It is widely used when:
- The dataset is large
- The array is sorted but rotated
- Performance is important

Definition:
Given a rotated sorted array of size N and a target value X,
- Compare X with the middle element of the array.
- If they match, return the index.
- Determine which half is sorted (left or right).
- If the target lies in the sorted half, search there.
- Otherwise, search the other half.
- Repeat until the element is found or the search space becomes empty.

Example:
Array: [4,5,6,7,0,1,2]
Target: 0

Process:
    Step 1: mid = (0+6)/2 = 3 → arr[3] = 7
    Step 2: Left half [4,5,6,7] is sorted, target 0 not in left → search right
    Step 3: Update low = 4, high = 6 → mid = 5 → arr[5] = 1
    Step 4: Left half [0,1] sorted, target 0 in left → search left
    Step 5: low = 4, high = 4 → mid = 4 → arr[4] = 0 → match found

Working Principle:
1. Initialize `low = 0` and `high = N - 1`.
2. While `low <= high`:
    a. Calculate `mid = low + (high - low)/2`.
    b. If `nums[mid] == target`, return `mid`.
    c. If left half is sorted (`nums[low] <= nums[mid]`):
        - If target lies in left half, `high = mid - 1`.
        - Else, `low = mid + 1`.
    d. Else (right half sorted):
        - If target lies in right half, `low = mid + 1`.
        - Else, `high = mid - 1`.
3. If not found, return -1.

Time Complexity:
    - Best Case: O(1) → Target found at middle.
    - Average/Worst Case: O(log N) → Halving the array each step.

Space Complexity:
    - O(1) for iterative version
    - O(log N) for recursive version (stack space)

Stable: Not applicable (searching only)
Adaptive: No

Constraints:
- Works only on rotated sorted arrays with distinct elements.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return mid;

            if(nums[low] <= nums[mid]) { // left half sorted
                if(target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else { // right half sorted
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    Solution sol;
    int index = sol.search(nums, target);

    cout << "Array elements (rotated sorted): ";
    for(int val : nums) cout << val << " ";
    cout << "\nSearching for: " << target << "\n";

    if(index != -1)
        cout << "Element found at index: " << index << "\n";
    else
        cout << "Element not found\n";

    return 0;
}

/*
Example Dry Run:
----------------
Array: 4 5 6 7 0 1 2
Target: 0

Step 1: low=0, high=6, mid=3 → nums[3]=7
        Left half [4,5,6,7] sorted, target not in left → search right
Step 2: low=4, high=6, mid=5 → nums[5]=1
        Left half [0,1] sorted, target 0 in left → search left
Step 3: low=4, high=4, mid=4 → nums[4]=0 → match found → return 4

Final Output:
Element found at index: 4
*/
