/*
 * Problem Statement: Find Number of Rotations in Rotated Sorted Array
 *
 * You are given a rotated sorted array 'arr' of unique integers.
 * A rotated sorted array is an array that was initially sorted but then rotated at some pivot.
 * The task is to find and return the number of times the array has been rotated.
 * Observation: The number of rotations is equal to the index of the minimum element in the array.
 *
 * Core Concept:
 * - Use binary search to efficiently find the minimum element and track its index.
 * - At each step, identify if the current search space is sorted:
 *   - If arr[low] <= arr[high], then arr[low] is the minimum in this segment. Record its index.
 * - Otherwise, determine which half is sorted and eliminate it while keeping track of potential minimums:
 *   - If left half is sorted, update answer = arr[low] and index = low, then search right half.
 *   - If right half is sorted, update answer = arr[mid] and index = mid, then search left half.
 * - Time Complexity: O(log N)
 * - Space Complexity: O(1)
 *
 * Examples:
 * arr = [15, 18, 2, 3, 6, 12]
 * Minimum element = 2 at index 2 => Rotated 2 times
 * arr = [7, 9, 11, 12, 5]
 * Minimum element = 5 at index 4 => Rotated 4 times
 */

#include <bits/stdc++.h>
using namespace std;

// ---------------------------
// FIND NUMBER OF ROTATIONS
// ---------------------------
int countRotations(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int answer = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If current segment is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < answer) {
                answer = arr[low];
                index = low;
            }
            break;
        }

        // Identify which half is sorted
        if (arr[low] <= arr[mid]) {
            // Left half is sorted
            if (arr[low] < answer) {
                answer = arr[low];
                index = low;
            }
            low = mid + 1; // search in right half
        } else {
            // Right half is sorted
            if (arr[mid] < answer) {
                answer = arr[mid];
                index = mid;
            }
            high = mid - 1; // search in left half
        }
    }

    return index; // index of minimum = number of rotations
}

// ---------------------------
// DRIVER CODE
// ---------------------------
int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};

    int rotations = countRotations(arr);
    cout << "Array has been rotated " << rotations << " times." << endl;

    return 0;
}
