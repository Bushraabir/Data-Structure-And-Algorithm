/*
 * Problem Statement: Search Element in Rotated Sorted Array II
 *
 * You are given a rotated sorted array 'arr' of integers (may contain duplicates) 
 * and a target value 'target'.
 * A rotated sorted array is an array that was initially sorted but then rotated at some pivot.
 * The task is to determine if 'target' exists in 'arr'. Return true if found, false otherwise.
 *
 * Core Concept:
 * - Standard binary search must be adapted for rotated arrays.
 * - Duplicates can prevent identification of the sorted half.
 * - If arr[low] == arr[mid] == arr[high], shrink the search space: low++ and high--.
 * - Otherwise, identify sorted half and trim search space accordingly.
 * - Average Time Complexity: O(log N)
 * - Worst-case Time Complexity (many duplicates): O(N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [2,5,6,0,0,1,2], target = 0
 * Answer = true
 * arr = [2,5,6,0,0,1,2], target = 3
 * Answer = false
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// SEARCH IN ROTATED SORTED ARRAY WITH DUPLICATES
// ---------------------------
bool searchRotatedSortedArrayII(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return true; // target found

        // Handle duplicates that prevent identifying sorted half
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

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

    return false; // target not found
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {2,5,6,0,0,1,2};
    int target = 0;

    bool found = searchRotatedSortedArrayII(arr, target);
    if (found)
        cout << "Target exists in array." << endl;
    else
        cout << "Target does not exist in array." << endl;

    return 0;
}
