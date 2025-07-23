/*
Find the length of the longest contiguous subarray whose sum equals 0.
You are given an integer N and an array of N integers. You need to determine
the maximum length of any contiguous subarray whose elements sum to zero.

Approach:
 - Compute running prefix sum `currentSum` as you traverse the array.
 - Use an unordered_map to record the first index at which each prefix sum occurs.
 - If the same `currentSum` appears again at index j, the subarray between
   (firstIndex + 1) and j sums to zero.
 - Update the max length whenever you see a repeated prefix sum or when
   `currentSum` itself is zero.

Time Complexity: O(N) on average (each element does O(1) map operations)  
Space Complexity: O(N) (storing prefix‑sum → first index mappings)  
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns length of the longest subarray with sum = 0
int longestZeroSumSubarray(int n) {
    unordered_map<long long, int> firstIndex;
    long long currentSum = 0;
    int maxLen = 0;

    // Traverse array
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        currentSum += x;

        // If sum is zero from 0 to i → length = i+1
        if (currentSum == 0) {
            maxLen = i + 1;
        }
        // If currentSum seen before, subarray between firstIndex+1 and i sums to zero
        if (firstIndex.find(currentSum) != firstIndex.end()) {
            int len = i - firstIndex[currentSum];
            if (len > maxLen) maxLen = len;
        } else {
            // Record first occurrence of this sum
            firstIndex[currentSum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cout << "Enter N (array size): ";
    cin >> n;

    cout << "Enter " << n << " array elements:\n";
    int result = longestZeroSumSubarray(n);

    cout << "Length of the longest subarray with sum 0 is " << result << "\n";
    return 0;
}
// Time Complexity: O(N) on average (due to hash map operations)
// Space Complexity: O(N) (for storing prefix sums and their first indices)