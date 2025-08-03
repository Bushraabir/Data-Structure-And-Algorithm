/*
 * Problem 6: Sliding Window Maximum
 *
 * Problem Statement:
 * -------------------
 * You are given an array of integers `nums` and an integer `k`.
 * Your task is to find the maximum element in every contiguous subarray (or window) of size `k`.
 * Return a list containing these maximums.
 *
 * Example:
 * Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
 * Output: [3, 3, 5, 5, 6, 7]
 *
 * Explanation:
 * - Window [1, 3, -1] → max = 3
 * - Window [3, -1, -3] → max = 3
 * - Window [-1, -3, 5] → max = 5
 * - Window [-3, 5, 3] → max = 5
 * - Window [5, 3, 6] → max = 6
 * - Window [3, 6, 7] → max = 7
 *
 * Intuition:
 * ----------
 * - Brute Force: Check all windows of size `k` and find the max in each → O(N*K)
 * - Optimized: Use a Deque to store indices in decreasing order of values (Monotonic Queue)
 *   - Remove elements out of the current window from the front.
 *   - Remove elements smaller than the current one from the back.
 *   - Front of the deque always holds the index of the max element in current window.
 *
 * Time Complexity:
 * ----------------
 * - Brute Force: O(N*K)
 * - Optimized (Deque): O(N) [Each element pushed and popped at most once]
 *
 * Space Complexity:
 * -----------------
 * - Brute Force: O(N) for result
 * - Optimized: O(K) for deque + O(N) for result
 */

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

// 6.1 Brute Force Approach
// ------------------------
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i <= n - k; ++i) {
        int maxi = INT_MIN;
        for (int j = i; j < i + k; ++j) {
            maxi = max(maxi, nums[j]);
        }
        result.push_back(maxi);
    }

    return result;
}
// Time Complexity: O(N*K)
// Space Complexity: O(N)


// 6.2 Optimized Deque-Based Approach
// ----------------------------------
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq; // Stores indices
    vector<int> result;

    for (int i = 0; i < n; ++i) {
        // Step 1: Remove elements out of window from front
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Step 2: Maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Step 3: Add current index
        dq.push_back(i);

        // Step 4: Collect result (start from i = k - 1)
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}
// Time Complexity: O(N)
// Space Complexity: O(K)


// 6.3 Example Usage
// -----------------
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Brute Force Output:\n";
    vector<int> bruteResult = maxSlidingWindowBrute(nums, k);
    for (int val : bruteResult) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Optimized Deque Output:\n";
    vector<int> optResult = maxSlidingWindow(nums, k);
    for (int val : optResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
