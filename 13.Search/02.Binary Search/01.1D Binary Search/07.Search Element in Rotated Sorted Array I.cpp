/*
 * Problem Statement: Search Element in Rotated Sorted Array
 *
 * You are given a rotated sorted array 'arr' of unique integers and a target value 'target'.
 * A rotated sorted array is an array that was initially sorted but then rotated at some pivot.
 * The task is to find the index of 'target' in 'arr'. Return -1 if not found.
 *
 * Core Concept:
 * - Standard binary search doesn't directly work because the array is rotated.
 * - At each step, identify the sorted half (left or right).
 * - Decide which half can safely be eliminated based on the sorted segment and target's range.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [4,5,6,7,0,1,2], target = 0
 * Answer = 4
 * arr = [4,5,6,7,0,1,2], target = 3
 * Answer = -1
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// SEARCH IN ROTATED SORTED ARRAY
// ---------------------------
int searchRotatedSortedArray(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid; // target found

        // Identify which half is sorted
        if (arr[low] <= arr[mid]) {
            // Left half is sorted
            if (target >= arr[low] && target <= arr[mid]) {
                high = mid - 1; // target in left half
            } else {
                low = mid + 1;  // target in right half
            }
        } else {
            // Right half is sorted
            if (target >= arr[mid] && target <= arr[high]) {
                low = mid + 1;  // target in right half
            } else {
                high = mid - 1; // target in left half
            }
        }
    }

    return -1; // target not found
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;

    int index = searchRotatedSortedArray(arr, target);
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found in array." << endl;

    return 0;
}
