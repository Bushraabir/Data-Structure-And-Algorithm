/*
 * Problem Statement: Smallest Divisor Given a Threshold
 *
 * You are given an array of positive integers 'nums' and an integer 'threshold'.
 * The task is to find the smallest positive integer divisor 'D' such that
 * the sum of ceil(nums[i] / D) for all elements in 'nums' is less than or equal to 'threshold'.
 *
 * Core Concept:
 * - Brute-force: Check every divisor from 1 to max(nums) and calculate the sum of ceiling divisions (O(max(nums) * n)), inefficient.
 * - Optimized solution uses binary search on the divisor:
 *   - Define search space from 1 to max(nums).
 *   - Use a helper function to calculate the sum of ceiling divisions for a given divisor.
 *   - If sum <= threshold, store the divisor and search left half to minimize it.
 *   - If sum > threshold, search right half for a larger divisor.
 * - Time Complexity: O(n * log(max(nums)))
 * - Space Complexity: O(1)
 *
 * Examples:
 * nums = [1,2,5,9], threshold = 6
 * Answer = 5
 * nums = [44,22,33,11,1], threshold = 5
 * Answer = 44
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// HELPER FUNCTION TO CALCULATE SUM OF CEIL DIVISIONS
// ---------------------------
long long calculateSum(const vector<int>& nums, int divisor) {
    long long sum = 0;
    for (int num : nums) {
        sum += (num + divisor - 1) / divisor; // equivalent to ceil(num/divisor)
    }
    return sum;
}

// ---------------------------
// FIND SMALLEST DIVISOR USING BINARY SEARCH
// ---------------------------
int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sum = calculateSum(nums, mid);

        if (sum <= threshold) {
            answer = mid;      // possible, try to find smaller divisor
            high = mid - 1;
        } else {
            low = mid + 1;     // sum too large, need larger divisor
        }
    }

    return answer;
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1,2,5,9}, 6},
        {{44,22,33,11,1}, 5},
        {{2,3,5,7,11}, 11}
    };

    for (auto &[nums, threshold] : testCases) {
        int divisor = smallestDivisor(nums, threshold);
        cout << "Smallest divisor for threshold " << threshold << ": " << divisor << endl;
    }

    return 0;
}
