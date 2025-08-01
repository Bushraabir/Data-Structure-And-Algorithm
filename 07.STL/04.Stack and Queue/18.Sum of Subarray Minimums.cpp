/*
 * Problem Statement: Sum of Subarray Minimums
 *
 * You are given an array of integers. The task is to find the sum of the minimums
 * of all possible contiguous subarrays of the given array.
 *
 * Example:
 * Input: [3,1,2,4]
 * Subarrays and their minimums:
 *   [3] => 3
 *   [3,1] => 1
 *   [3,1,2] => 1
 *   [3,1,2,4] => 1
 *   [1] => 1
 *   [1,2] => 1
 *   [1,2,4] => 1
 *   [2] => 2
 *   [2,4] => 2
 *   [4] => 4
 * Total Sum = 3+1+1+1+1+1+1+2+2+4 = 17
 *
 * Since the result can be large, return it modulo 1e9+7.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Brute Force Approach
int sumSubarrayMins_BruteForce(vector<int>& arr) {
    int mod = 1e9 + 7;
    int n = arr.size();
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int currentMin = arr[i];
        for (int j = i; j < n; ++j) {
            currentMin = min(currentMin, arr[j]);
            total = (total + currentMin) % mod;
        }
    }

    return (int)total;
}

// Optimized Stack-based Approach
int sumSubarrayMins_Optimized(vector<int>& arr) {
    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> nextSmaller(n, n);  // Default to n
    vector<int> prevSmaller(n, -1); // Default to -1
    stack<int> s;

    // Compute Previous Smaller or Equal Element Index (PSEE)
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            s.pop();
        }
        prevSmaller[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack to reuse
    while (!s.empty()) s.pop();

    // Compute Next Smaller Element Index (NSE)
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        nextSmaller[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Compute the final result using contributions
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - prevSmaller[i];
        long long right = nextSmaller[i] - i;
        long long contrib = (arr[i] * left % mod) * right % mod;
        result = (result + contrib) % mod;
    }

    return (int)result;
}

int main() {
    vector<int> arr = {3,1,2,4};

    cout << "Brute Force: " << sumSubarrayMins_BruteForce(arr) << endl;
    cout << "Optimized Stack Approach: " << sumSubarrayMins_Optimized(arr) << endl;

    return 0;
}