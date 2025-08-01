/*
 * Given an array of integers, calculate the sum of the differences between
 * the largest and smallest elements for every possible contiguous subarray.
 *
 * Example:
 * Input: [1,4,3,2]
 * Subarrays and their ranges (max - min):
 *   [1]       -> 1 - 1 = 0
 *   [1,4]     -> 4 - 1 = 3
 *   [1,4,3]   -> 4 - 1 = 3
 *   [1,4,3,2] -> 4 - 1 = 3
 *   [4]       -> 4 - 4 = 0
 *   [4,3]     -> 4 - 3 = 1
 *   [4,3,2]   -> 4 - 2 = 2
 *   [3]       -> 3 - 3 = 0
 *   [3,2]     -> 3 - 2 = 1
 *   [2]       -> 2 - 2 = 0
 * Total Sum = 0 + 3 + 3 + 3 + 0 + 1 + 2 + 0 + 1 + 0 = 13
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute Force Approach
long long sumSubarrayRanges_BruteForce(vector<int>& arr) {
    int n = arr.size();
    long long total = 0;

    // Iterate over all subarrays starting at i
    for (int i = 0; i < n; ++i) {
        int currentMax = arr[i];
        int currentMin = arr[i];
        // Expand subarray ending at j
        for (int j = i; j < n; ++j) {
            currentMax = max(currentMax, arr[j]);
            currentMin = min(currentMin, arr[j]);
            total += (long long)(currentMax - currentMin);
        }
    }

    return total;
}

/*
 * Optimized Approach:
 *
 * The sum of subarray ranges can be computed as:
 *   sum of all subarray maximums - sum of all subarray minimums
 *
 * We solve this by computing these two sums separately using monotonic stacks,
 * then subtracting the two results.
 *
 * The logic for sum of subarray minimums and maximums is similar:
 * - For minimums: Find Previous Smaller or Equal Element (PSEE) and Next Smaller Element (NSE)
 * - For maximums: Find Previous Greater or Equal Element (PGEE) and Next Greater Element (NGE)
 *
 * For each element arr[i]:
 *   Contribution as minimum = arr[i] * (i - PSEE_i) * (NSE_i - i)
 *   Contribution as maximum = arr[i] * (i - PGEE_i) * (NGE_i - i)
 *
 * Summing these contributions for all elements and subtracting gives
 * the sum of all subarray ranges.
 *
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

// Helper function: sum of subarray minimums
long long sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> prevSmaller(n, -1);
    vector<int> nextSmaller(n, n);
    stack<int> s;

    // Find Previous Smaller or Equal Element (PSEE)
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        prevSmaller[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();

    // Find Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        nextSmaller[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - prevSmaller[i];
        long long right = nextSmaller[i] - i;
        result += (long long)arr[i] * left * right;
    }
    return result;
}

// Helper function: sum of subarray maximums
long long sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> prevGreater(n, -1);
    vector<int> nextGreater(n, n);
    stack<int> s;

    // Find Previous Greater or Equal Element (PGEE)
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            s.pop();
        }
        prevGreater[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();

    // Find Next Greater Element (NGE)
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] <= arr[i]) {
            s.pop();
        }
        nextGreater[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - prevGreater[i];
        long long right = nextGreater[i] - i;
        result += (long long)arr[i] * left * right;
    }
    return result;
}

// Main function to compute sum of subarray ranges
long long sumSubarrayRanges_Optimized(vector<int>& arr) {
    // sum of maxs - sum of mins
    return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
}

int main() {
    vector<int> arr = {1, 4, 3, 2};

    cout << "Brute Force Sum of Ranges: " << sumSubarrayRanges_BruteForce(arr) << endl;
    cout << "Optimized Sum of Ranges: " << sumSubarrayRanges_Optimized(arr) << endl;

    return 0;
}
