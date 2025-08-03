/*
 * Problem Statement: Sum of Subarray Minimums
 *
 * Given an array of integers, find the sum of the minimum values of all possible
 * contiguous subarrays of the array. Since the sum can be very large, return
 * the result modulo 10^9 + 7.
 *
 * Example:
 * Input: [3,1,2,4]
 * Subarrays and their minimums:
 *   [3]       -> 3
 *   [3,1]     -> 1
 *   [3,1,2]   -> 1
 *   [3,1,2,4] -> 1
 *   [1]       -> 1
 *   [1,2]     -> 1
 *   [1,2,4]   -> 1
 *   [2]       -> 2
 *   [2,4]     -> 2
 *   [4]       -> 4
 * Total Sum = 3+1+1+1+1+1+1+2+2+4 = 17
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute Force Approach
int sumSubarrayMins_BruteForce(vector<int>& arr) {
    int mod = 1e9 + 7;  // Large prime modulus to avoid overflow
    int n = arr.size();
    long long total = 0;

    // Iterate over all possible starting points of subarrays
    for (int i = 0; i < n; ++i) {
        int currentMin = arr[i]; // Initialize minimum for subarray starting at i
        // Expand subarray to the right
        for (int j = i; j < n; ++j) {
            // Update minimum if current element is smaller
            currentMin = min(currentMin, arr[j]);
            // Add the current minimum to total sum, modulo applied
            total = (total + currentMin) % mod;
        }
    }

    return (int)total;
}

/*
 * Optimized Stack-based Approach
 *
 * Logic:
 * Each element in the array contributes to the total sum by being the minimum
 * in several subarrays. Instead of enumerating all subarrays, we calculate 
 * the number of subarrays for which each element is the minimum.
 *
 * To do this, we find:
 * 1. Previous Smaller or Equal Element (PSEE) index for each element:
 *    The closest element to the left which is smaller or equal to the current element.
 *    If none exists, use -1.
 * 2. Next Smaller Element (NSE) index for each element:
 *    The closest element to the right which is strictly smaller than the current element.
 *    If none exists, use n (size of array).
 *
 * For element at index i:
 * - left_count = i - PSEE_index
 * - right_count = NSE_index - i
 * 
 * The total number of subarrays where arr[i] is the minimum is:
 *    left_count * right_count
 * 
 * Contribution of arr[i] to final sum:
 *    arr[i] * left_count * right_count
 *
 * We calculate and sum all contributions modulo 10^9 + 7.
 */
int sumSubarrayMins_Optimized(vector<int>& arr) {
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> prevSmaller(n, -1);
    vector<int> nextSmaller(n, n);
    stack<int> s;

    // Find Previous Smaller or Equal Element (PSEE) for each index
    for (int i = 0; i < n; ++i) {
        // Pop indices from stack while top element is strictly greater than current arr[i]
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        // If stack empty, no smaller or equal element to the left, else top of stack is PSEE
        prevSmaller[i] = s.empty() ? -1 : s.top();
        s.push(i);  // Push current index for future reference
    }

    // Clear stack to reuse for next step
    while (!s.empty()) s.pop();

    // Find Next Smaller Element (NSE) for each index
    for (int i = n - 1; i >= 0; --i) {
        // Pop indices from stack while top element is greater than or equal to current arr[i]
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        // If stack empty, no smaller element to the right, else top of stack is NSE
        nextSmaller[i] = s.empty() ? n : s.top();
        s.push(i);  // Push current index for future reference
    }

    // Calculate sum of contributions for all elements
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left_count = i - prevSmaller[i];     // How far left subarrays can extend
        long long right_count = nextSmaller[i] - i;    // How far right subarrays can extend
        // Contribution from arr[i], modulo multiplication applied
        long long contribution = (arr[i] * left_count) % mod;
        contribution = (contribution * right_count) % mod;
        result = (result + contribution) % mod;
    }

    return (int)result;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};

    cout << "Brute Force: " << sumSubarrayMins_BruteForce(arr) << endl;
    cout << "Optimized Stack Approach: " << sumSubarrayMins_Optimized(arr) << endl;

    return 0;
}
