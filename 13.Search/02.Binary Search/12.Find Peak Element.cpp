/*
 * Problem Statement: Find Peak Element
 *
 * You are given an array 'arr'. A peak element is an element that is strictly greater than its neighbors.
 * For the first and last elements, consider minus infinity outside the array.
 * Return the index of any peak element.
 *
 * Core Concept:
 * - Brute-force: check each element against neighbors (O(N)).
 * - Optimized solution uses binary search:
 *   - If mid > mid-1 and mid > mid+1, mid is a peak.
 *   - If mid > mid-1 (increasing slope), the peak is on the right half.
 *   - Else (decreasing slope), the peak is on the left half.
 *   - This works even with multiple peaks.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [1,2,3,1]
 * Answer = 2 (element 3)
 * arr = [1,2,1,3,5,6,4]
 * Answer = 1 or 5 (element 2 or 6)
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIND PEAK ELEMENT USING BINARY SEARCH
// ---------------------------
int findPeakElement(vector<int>& arr) {
    int n = arr.size();

    // Edge cases: first or last element
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is a peak
        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }

        // Move to the side which guarantees a peak
        if (arr[mid] > arr[mid-1]) {
            // Increasing slope: peak on the right
            low = mid + 1;
        } else {
            // Decreasing slope: peak on the left
            high = mid - 1;
        }
    }

    return -1; // Should never reach here
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {1,2,3,1};

    int peakIndex = findPeakElement(arr);
    cout << "Peak element index: " << peakIndex 
         << ", value: " << arr[peakIndex] << endl;

    return 0;
}
